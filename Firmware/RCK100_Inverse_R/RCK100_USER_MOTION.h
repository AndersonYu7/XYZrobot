#ifndef RCK100_USER_MOTION_H
#define RCK100_USER_MOTION_H

#include <avr/pgmspace.h>

const PROGMEM uint16_t NonePose[] = {6, 512, 512, 512, 512, 512, 512};

const PROGMEM transition_t None[] = {{0, 1} ,{NonePose, 400}};

const PROGMEM uint16_t DefaultPose_1[] = {6, 512, 480, 428, 588, 790, 707};

const PROGMEM uint16_t DefaultPose_2[] = {6, 512, 237, 235, 512, 790, 707};

const PROGMEM transition_t DefaultInitial_1[] = {{0, 1}, {DefaultPose_1, 1000}};
const PROGMEM transition_t DefaultInitial_2[] = {{0, 1}, {DefaultPose_2, 1000}};

const PROGMEM Action_t ACTION_LIST[] = {{DefaultInitial_1},
										{DefaultInitial_2},
										{DefaultInitial_1},
										{DefaultInitial_1},
										{DefaultInitial_1},
										{DefaultInitial_1},
										{DefaultInitial_1},
										{DefaultInitial_1},
										{DefaultInitial_1},
										{DefaultInitial_1},
										{DefaultInitial_1},
										};

#endif

