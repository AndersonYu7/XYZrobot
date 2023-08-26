#include <BOLIDE_Player.h>
#include <A1_16.h>

#include "Simple_Function.h"
#include "BOLIDE_Board.h"
#include "RCK100_USER_MOTION.h"
#include "ARM_Kinemetic.h"

BOLIDE_Player RobotARM_W;

/*== BT Receive Variables ==*/
static int BT_packet[7] = {0};
static uint8_t BT_update = 0;
/*==== IK Variables ====*/
/*== IK Status Value ==*/
static uint8_t status_arm = 0x00;
/*== Robot Arm State Value ==*/
static double length_r = INITIAL_RADIUS;
static double axis_z = INITIAL_AXIS_Z;

static double angle_roll = 0.0;
static double angle_yaw = 0.0;
static double angle_pitch = 0.0;
static double angle_gripper = 0.0;
/*== Robot Arm Delta Value ==*/
static double delta_r = 0.0;
static double delta_z = 0.0;

static double delta_roll = 0.0;
static double delta_yaw = 0.0;
static double delta_pitch = 0.0;
static double delta_gripper = 0.0;
/*== A1-16 Servo Angle ==*/
static double angle_1 = INITIAL_ANGLE_1;
static double angle_2 = INITIAL_ANGLE_2;
static double angle_3 = INITIAL_ANGLE_3;
static double angle_4 = INITIAL_ANGLE_4;
static double angle_5 = INITIAL_ANGLE_5;
static double angle_6 = INITIAL_ANGLE_6;
/*== A1-16 Servo Counts ==*/
static int servo_position_1 = REF_ANGLE_1;
static int servo_position_2 = REF_ANGLE_2;
static int servo_position_3 = REF_ANGLE_3;
static int servo_position_4 = REF_ANGLE_4;
static int servo_position_5 = REF_ANGLE_5;
static int servo_position_6 = REF_ANGLE_6;

Constant_Timer Timer_ARM;

void setup(void){
	Hardware_Setup();
	Software_Setup();
	delay(100);
}

void loop(void){
	BT_Receive_Task();
	if(BT_update) BT_Task();
	Trajectory_Task();
}

/*========= Function =========*/
/*==== Setup Function ====*/
void Hardware_Setup(void){
	/*== USB Setup Function ==*/
		// config USB UART baud rate
	Serial.begin(115200);
	/*== A1_16 Servo Setup Function ==*/
		// config A1_16 UART baud rate
	RobotARM_W.setup(115200, 6);
	/*== BT Setup Function ==*/
		// config BT module UART baud rate
	Serial2.begin(9600);
	/*== Button Setup Function ==*/
		// config IO direction of switch function
	pinMode(PIN_BUTTON_1, INPUT);
	pinMode(PIN_BUTTON_2, INPUT);
	pinMode(PIN_BUTTON_3, INPUT);
	pinMode(PIN_BUTTON_4, INPUT);
	/*== Power Setup Function ==*/
		// config IO direction of system
	pinMode(PIN_BUZZER, OUTPUT);
	pinMode(PIN_PWRDET, INPUT);
	analogReference(EXTERNAL);
}
void Software_Setup(void){
	/*== A1_16 Servo Setup Function ==*/
		// config A1_16 setting
	Pose_Initial_Task();
	/*== Button Record Setup Function ==*/
	/*== Timer Setup Function ==*/
	Timer_ARM.Timer_Task(0);
}
/*== BT Function ==*/
void BT_Task(void){
	static int _speed_right = 0;
	static int _speed_left = 0;
	static int _turning_speed = 0;
	static int _forward_speed = 0;
	static int _temp = 0;

	BT_update = 0;
	if(BT_packet[6] & MASK_RCU_PACKET_NUMBER){
		// BT Data Source : RCU
		if(BT_packet[5] & MASK_RCU_RELEASE){
			Action_Sequence_Load(-1);
			Clear_LED_Status();
			status_arm = MASK_TORQUE_OFF;
			length_r = 0;
			axis_z = 0;

			angle_roll = 0;
			angle_yaw = 0;
			angle_pitch = 0;
			angle_gripper = 0;
		}
		else{
			if(BT_packet[5] & MASK_RCU_POWER){
				if(Trajectory_Initial_Check()){
					Action_Sequence_Load(1);
					status_arm = MASK_READY_RELAX;

					length_r = RELAX_RADIUS;
					axis_z = RELAX_AXIS_Z;

					angle_roll = 0;
					angle_yaw = 0;
					angle_pitch = 0;
					angle_gripper = 0;
				}
				else{
					Action_Sequence_Load(0);
					status_arm = 0x00;

					length_r = INITIAL_RADIUS;
					axis_z = INITIAL_AXIS_Z;

					angle_roll = 0;
					angle_yaw = 0;
					angle_pitch = 0;
					angle_gripper = 0;
				}
			}
			else if(BT_packet[5] & MASK_RCU_BT) ;
			else{
				if(BT_packet[6] & MASK_RCU_L3){
					_temp = 127 - BT_packet[1];
					if(abs(_temp) > THERHOLD_JOYSTICK) _turning_speed = _temp << 3;
					else _turning_speed = 0;
					_temp = BT_packet[2] - 127;
					if(abs(_temp) > THERHOLD_JOYSTICK) _forward_speed = _temp << 3;
					else _forward_speed = 0;

					_speed_right = -_forward_speed - _turning_speed;
					_speed_left = _forward_speed - _turning_speed;

					if(_speed_right > 1023) _speed_right = 1023;
					else if(_speed_right < -1023) _speed_right = -1023;

					if(_speed_left > 1023) _speed_left = 1023;
					else if(_speed_left < -1023) _speed_left = -1023;

					A1_16_SetSpeed(7, 0, _speed_right);
					A1_16_SetSpeed(8, 0, _speed_left);
				}
				else{
					_temp = BT_packet[2] - 127;
					if(_temp > THERHOLD_JOYSTICK) delta_r = 1.0;
					else if(_temp < -THERHOLD_JOYSTICK) delta_r = -1.0;
					else delta_r = 0.0;

					_temp = 127 - BT_packet[1];
					if(_temp > THERHOLD_JOYSTICK) delta_yaw = 1.0;
					else if(_temp < -THERHOLD_JOYSTICK) delta_yaw = -1.0;
					else delta_yaw = 0.0;

					if(BT_packet[6] & MASK_RCU_L1) delta_z = 1.0;
					else if(BT_packet[6] & MASK_RCU_L2) delta_z = -1.0;
					else delta_z = 0.0;

					_temp = 127 - BT_packet[4];
					if(_temp > THERHOLD_JOYSTICK) delta_pitch = 1.0;
					else if(_temp < -THERHOLD_JOYSTICK) delta_pitch = -1.0;
					else delta_pitch = 0.0;

					_temp = BT_packet[3] - 127;
					if(_temp > THERHOLD_JOYSTICK) delta_roll = 1.0;
					else if(_temp < -THERHOLD_JOYSTICK) delta_roll = -1.0;
					else delta_roll = 0.0;

					if(BT_packet[5] & MASK_RCU_R1) delta_gripper = -1.0;
					else if(BT_packet[5] & MASK_RCU_R2) delta_gripper = 1.0;
					else delta_gripper = 0.0;

					if(delta_r != 0.0 || delta_z != 0.0|| delta_roll != 0.0  || delta_yaw != 0.0 || delta_pitch != 0.0 || delta_gripper != 0.0) status_arm |= MASK_AXIS_MOVE;
					else status_arm &= ~MASK_AXIS_MOVE;

					A1_16_SetSpeed(7, 0, 0);
					A1_16_SetSpeed(8, 0, 0);
				}
			}
		}
	}
}
void BT_Receive_Task(void){
	// return torque_relase button status
	static int _temp_packet[7] = {0};
	static int _temp = 0;
	static uint8_t _i = 0;
	if(Serial2.available() >= 7){
		if((_temp_packet[0] = Serial2.read()) != 0) {BT_Packet_Header_Finder(); return;}
		if((_temp_packet[1] = Serial2.read()) == 0) {BT_Packet_Header_Finder(); return;}
		if((_temp_packet[2] = Serial2.read()) == 0) {BT_Packet_Header_Finder(); return;}
		if((_temp_packet[3] = Serial2.read()) == 0) {BT_Packet_Header_Finder(); return;}
		if((_temp_packet[4] = Serial2.read()) == 0) {BT_Packet_Header_Finder(); return;}
		if((_temp_packet[5] = Serial2.read()) == 0) {BT_Packet_Header_Finder(); return;}
		if((_temp_packet[6] = Serial2.read()) == 0) {BT_Packet_Header_Finder(); return;}
		_temp = (_temp_packet[6] & 0x00F0) >> 4;
		if(_temp != 0) Serial2.write(_temp);
		for(_i = 0;_i < 7;_i++) BT_packet[_i] = _temp_packet[_i];
		BT_Buffer_Clear();
		BT_update = 1;
	}
}
void BT_Buffer_Clear(void){
	// Clean BT Buffer
	while((Serial2.read()) != -1);
}
void BT_Packet_Header_Finder(void){
	while(Serial2.available() > 0){
		if(Serial2.peek() == 0) return;
		Serial2.read();
	}
}
/*== A1-16 Function ==*/
void Pose_Initial_Task(void){
	// initial to home pose
	Action_Sequence_Load(0);
}
void Servo_Torque_On(void){
	static uint8_t _i = 0;
	static int _temp = 0;
	for(_i = 1;_i <= 6;_i++){
		_temp = ReadPosition(_i);
		SetPositionI_JOG(_i, 0, _temp);
	}
}
void Clear_LED_Status(void){
	WriteDataRAM1(A1_16_Broadcast_ID, RAM_Alarm_LED_Policy, 0xFF);
	delay(20);
	WriteDataRAM1(A1_16_Broadcast_ID, RAM_LED_Control, MASK_LED_WHI);
	delay(20);
	WriteDataRAM1(A1_16_Broadcast_ID, RAM_Alarm_LED_Policy, 0x00);
	delay(20);
}
/*== Sequence Load Function ==*/
void Action_Sequence_Load(int _motion){
	if(_motion < 0) RobotARM_W.stopMotion();
	else{
		RobotARM_W.readPose();
		RobotARM_W.playSeq((const transition_t *)pgm_read_word(&(ACTION_LIST + _motion)->Seq_A1_16));
	}
}
/*== Trajectory Function ==*/
void Trajectory_Task(void){
	if(RobotARM_W.playing){
		RobotARM_W.play();
		Timer_ARM.Timer_Task(0);
	}
	else if(Timer_ARM.Timer_Task(DELTA_TIME_ARM)){
		if(status_arm & MASK_TORQUE_OFF) ;
		else if(status_arm & MASK_READY_RELAX){
			Action_Sequence_Load(-1);
			status_arm = MASK_TORQUE_OFF;
		}
		else if(status_arm & MASK_AXIS_MOVE){
			length_r += delta_r;
			axis_z += delta_z;
			angle_roll += delta_roll;
			angle_yaw += delta_yaw;
			angle_pitch += delta_pitch;
			angle_gripper += delta_gripper;

			Serial.print(F("Length R : ")); Serial.println(length_r);
			Serial.print(F("Axis Z : ")); Serial.println(axis_z);
			Serial.print(F("Angle Roll : ")); Serial.println(angle_roll);
			Serial.print(F("Angle Pitch : ")); Serial.println(angle_pitch);
			Serial.print(F("Angle Gripper : ")); Serial.println(angle_gripper);
			IK_Robot_Arm();
		}
		else noTone(PIN_BUZZER);
	}
}
void IK_Robot_Arm(void){
	static double _temp = 0;
	static double _r = JOINT_LENGTH_L2;
	static double _r_sq = JOINT_LENGTH_L2_SQ;
	static double _L = 108.63;
	static double _L_sq = 11800.4769;
	static double _alpha = 1.57;		// temperature initial value
	static double _add_r = 0.0;
	static double _add_z = 0.0;
	static double _axis_z = 0.0;

	static double _last_r = 0.0;
	static double _last_z = 0.0;
	static double _last_roll = 0.0;
	static double _last_yaw = 0.0;
	static double _last_pitch = 0.0;
	static double _last_gripper = 0.0;

	static int _status_angle = 0;

	_temp = DEG2RAD(angle_pitch);
	_add_r = JOINT_LENGTH_L3*cos(_temp);
	_add_z = JOINT_LENGTH_L3*sin(_temp);

	Serial.print(F("Additional r : ")); Serial.println(_add_r);
	Serial.print(F("Additional z : ")); Serial.println(_add_z);

	_r = length_r - _add_r;
	_r_sq = _r*_r;

	_axis_z = axis_z - _add_z;

	_L_sq = _r_sq + _axis_z*_axis_z;
	_L = sqrt(_L_sq);

	_alpha = atan2(_axis_z, _r);

	angle_1 = DEG2RAD(angle_yaw);

	_temp = JOINT_LENGTH_L1_SQ + JOINT_LENGTH_L2_SQ - _L_sq;
	_temp = _temp/(2*JOINT_LENGTH_L1*JOINT_LENGTH_L2);
	angle_3 = asin(_temp);

	_temp = _L_sq + JOINT_LENGTH_L1_SQ - JOINT_LENGTH_L2_SQ;
	_temp = _temp/(2*JOINT_LENGTH_L1*_L);
	angle_2 = asin(_temp) - _alpha;

	angle_4 = angle_3 + angle_2 + DEG2RAD(angle_pitch);

	angle_5 = angle_roll;

	angle_6 = angle_gripper;

	_status_angle = isnan(angle_2) + isnan(angle_3);

	// _temp = RAD2DEG(angle_1);
	_temp = RAD2COUNT(angle_1);
	servo_position_1 = REF_ANGLE_1 + _temp;
	if(servo_position_1 > LIMIT_MAX_SERVO_1) _status_angle++;
	else if(servo_position_1 < LIMIT_MIN_SERVO_1) _status_angle++;
	else Serial.print(F("Angle 1 : ")); Serial.println(_temp);

	// _temp = RAD2DEG(angle_2);
	_temp = RAD2COUNT(angle_2);
	servo_position_2 = REF_ANGLE_2 + _temp;
	if(servo_position_2 > LIMIT_MAX_SERVO_2) _status_angle++;
	else if(servo_position_2 < LIMIT_MIN_SERVO_2) _status_angle++;
	else Serial.print(F("Angle 2 : ")); Serial.println(_temp);

	// _temp = RAD2DEG(angle_3);
	_temp = RAD2COUNT(angle_3);
	servo_position_3 = REF_ANGLE_3 - _temp;
	if(servo_position_3 > LIMIT_MAX_SERVO_3) _status_angle++;
	else if(servo_position_3 < LIMIT_MIN_SERVO_3) _status_angle++;
	else Serial.print(F("Angle 3 : ")); Serial.println(_temp);

	// _temp = RAD2DEG(angle_4);
	_temp = RAD2COUNT(angle_4);
	servo_position_4 = REF_ANGLE_4 + _temp;
	if(servo_position_4 > LIMIT_MAX_SERVO_4) _status_angle++;
	else if(servo_position_4 < LIMIT_MIN_SERVO_4) _status_angle++;
	else Serial.print(F("Angle 4 : ")); Serial.println(_temp);

	_temp = DEG2COUNT(angle_5);
	servo_position_5 = REF_ANGLE_5 + _temp;
	if(servo_position_5 > LIMIT_MAX_SERVO_5) _status_angle++;
	else if(servo_position_5 < LIMIT_MIN_SERVO_5) _status_angle++;
	else Serial.print(F("Angle 5 : ")); Serial.println(_temp);

	_temp = DEG2COUNT(angle_6);
	servo_position_6 = REF_ANGLE_6 + _temp;
	if(servo_position_6 > LIMIT_MAX_SERVO_6) _status_angle++;
	else if(servo_position_6 < LIMIT_MIN_SERVO_6) _status_angle++;
	else Serial.print(F("Angle 6 : ")); Serial.println(_temp);

	if(_status_angle != 0){
		tone(PIN_BUZZER, 1000);
		Serial.println(F("Request Position Over Constraint"));
		length_r = _last_r;
		axis_z = _last_z;
		angle_roll = _last_roll;
		angle_yaw = _last_yaw;
		angle_pitch = _last_pitch;
		angle_gripper = _last_gripper;
	}
	else{
		noTone(PIN_BUZZER);
		SetPositionI_JOG(1, 0, servo_position_1);
		SetPositionI_JOG(2, 0, servo_position_2);
		SetPositionI_JOG(3, 0, servo_position_3);
		SetPositionI_JOG(4, 0, servo_position_4);
		SetPositionI_JOG(5, 0, servo_position_5);
		SetPositionI_JOG(6, 0, servo_position_6);

		_last_r = length_r;
		_last_z = axis_z;
		_last_roll = angle_roll;
		_last_yaw = angle_yaw;
		_last_pitch = angle_pitch;
		_last_gripper = angle_gripper;
	}
	Serial.println(F("================================================"));
}
boolean Trajectory_Initial_Check(void){
	// return true if system in initial pose
	if(length_r != INITIAL_RADIUS) return false;
	if(axis_z != INITIAL_AXIS_Z) return false;
	if(angle_roll != 0.0) return false;
	if(angle_yaw != 0.0) return false;
	if(angle_pitch != 0.0) return false;
	if(angle_gripper != 0.0) return false;
	return true;
}