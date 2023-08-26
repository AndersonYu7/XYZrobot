#ifndef ARM_KINEMETIC_H
#define ARM_KINEMETIC_H

#define DELTA_TIME_ARM			20

#define MASK_AXIS_MOVE			0x01
#define MASK_READY_RELAX		0x02
#define MASK_TORQUE_OFF			0x80

#define JOINT_LENGTH_L1			81.16
#define JOINT_LENGTH_L2			72.20
#define JOINT_LENGTH_L3			142.057

#define JOINT_LENGTH_L1_SQ		6586.9456		// JOINT_LENGTH_L1*JOINT_LENGTH_L1
#define JOINT_LENGTH_L2_SQ		5212.84			// JOINT_LENGTH_L2*JOINT_LENGTH_L2
#define JOINT_LENGTH_L3_SQ		20180.19		// JOINT_LENGTH_L3*JOINT_LENGTH_L3

// reference angle value(servo position counts)
#define REF_ANGLE_1				512
#define REF_ANGLE_2				480
#define REF_ANGLE_3				428
#define REF_ANGLE_4				588
#define REF_ANGLE_5				790
#define REF_ANGLE_6				707
// delta angle value(radius)
#define INITIAL_ANGLE_1			0
#define INITIAL_ANGLE_2			0
#define INITIAL_ANGLE_3			0
#define INITIAL_ANGLE_4			0
#define INITIAL_ANGLE_5			0
#define INITIAL_ANGLE_6			0

#define INITIAL_AXIS_X			JOINT_LENGTH_L2 + JOINT_LENGTH_L3
#define INITIAL_AXIS_Y			0
#define INITIAL_AXIS_Z			JOINT_LENGTH_L1

#define INITIAL_RADIUS			JOINT_LENGTH_L2 + JOINT_LENGTH_L3

#define RELAX_RADIUS			130.807
#define RELAX_AXIS_Z			37.0

#define DEG2POS(degree)			((degree)*1024/330)
#define RAD2DEG(radian)			((radian)*180.0f/PI)
#define DEG2RAD(degree)			((degree)*PI/180.0f)
#define RAD2COUNT(radian)		((radian)*177.791f)		// radian*(180/PI)*(1024/330)
#define DEG2COUNT(radian)		((radian)*3.103f)		// degree*(1024/330)

#define LIMIT_ROLL				75
#define LIMIT_GRIPPER			29

#define LIMIT_MAX_SERVO_1		900
#define LIMIT_MIN_SERVO_1		124

#define LIMIT_MAX_SERVO_2		820
#define LIMIT_MIN_SERVO_2		190

#define LIMIT_MAX_SERVO_3		790
#define LIMIT_MIN_SERVO_3		240

#define LIMIT_MAX_SERVO_4		830
#define LIMIT_MIN_SERVO_4		180

#define LIMIT_MAX_SERVO_5		990
#define LIMIT_MIN_SERVO_5		33

#define LIMIT_MAX_SERVO_6		790
#define LIMIT_MIN_SERVO_6		624

#define MASK_LED_WHI			0x01
#define MASK_LED_BLE			0x02
#define MASK_LED_GRN			0x04
#define MASK_LED_RED			0x08
#define MASK_LED_ALL			0x0F
#define MASK_LED_NO				0x00

#endif