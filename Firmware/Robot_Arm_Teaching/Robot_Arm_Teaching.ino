#include <BOLIDE_Player.h>

#define DELTA_POSITION	5

const PROGMEM uint16_t U_init1[] = {6, 512, 377, 496, 398, 790, 513};
const PROGMEM transition_t U_arm_stop[] = {{0, 1} ,{U_init1, 500}};

BOLIDE_Player XYZrobot;

void setup(void){
	Serial.begin(115200);
	XYZrobot.setup(115200, 6);
	delay(100);
	XYZrobot.readPose();
	XYZrobot.playSeq(U_arm_stop);
	while(XYZrobot.playing) XYZrobot.play();
}

void loop(void){
	static int _position[7] = { 0 };
	static int _position_ref[7] = { 0 };
	static int _i = 0;
	for(_i = 1;_i <= 6;_i++){
		_position[_i] = ReadPosition(_i);
		_position_ref[_i] = ReadDataRAM2(_i, RAM_Position_Ref);
		if(abs(_position_ref[_i] - _position[_i]) > DELTA_POSITION) SetPositionI_JOG(_i, 0, _position[_i]);
	}
}
