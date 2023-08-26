#ifndef RCK100_USER_MOTION_H
#define RCK100_USER_MOTION_H
#include <avr/pgmspace.h>
static char Motor_Number = 6;
const PROGMEM uint16_t NonePose[] = {6, 512, 512, 512, 512, 512, 512};
const PROGMEM transition_t None[] = {{0,1} ,{NonePose,400}};

const PROGMEM uint16_t DefaultPose1[] = {6, 512, 374, 507, 402, 790, 512};
const PROGMEM transition_t DefaultInitial[] = {{0,1}, {DefaultPose1, 1000}};
//===== User Define Pose ======
const PROGMEM uint16_t U_init1[] = {6, 512, 374, 507, 402, 790, 512};
const PROGMEM uint16_t U_arm1[] = {6, 612, 251, 261, 600, 509, 513};
const PROGMEM uint16_t U_arm2[] = {6, 622, 492, 512, 602, 442, 612};
const PROGMEM uint16_t U_arm3[] = {6, 412, 250, 255, 600, 510, 513};
const PROGMEM uint16_t U_arm4[] = {6, 402, 499, 504, 602, 612, 602};
const PROGMEM uint16_t U_yes1[] = {6, 510, 417, 588, 445, 802, 515};
const PROGMEM uint16_t U_yes2[] = {6, 510, 418, 588, 342, 802, 515};
const PROGMEM uint16_t U_no1[] = {6, 392, 419, 585, 339, 802, 514};
const PROGMEM uint16_t U_no2[] = {6, 632, 420, 584, 339, 803, 514};
const PROGMEM uint16_t U_happy1[] = {6, 528, 351, 370, 636, 530, 514};
const PROGMEM uint16_t U_happy2[] = {6, 528, 396, 449, 636, 704, 624};
const PROGMEM uint16_t U_happy3[] = {6, 528, 373, 418, 637, 847, 521};
const PROGMEM uint16_t U_happy4[] = {6, 528, 373, 411, 637, 891, 645};
const PROGMEM uint16_t U_M12_F[] = {6, 712, 531, 493, 399, 790, 513};
const PROGMEM uint16_t U_M12_B[] = {6, 312, 526, 496, 399, 790, 513};
const PROGMEM uint16_t U_M34_F[] = {6, 512, 377, 396, 500, 790, 513};
const PROGMEM uint16_t U_M34_B[] = {6, 512, 377, 596, 300, 790, 513};
const PROGMEM uint16_t U_M56_F[] = {6, 512, 377, 495, 394, 512, 651};
const PROGMEM uint16_t U_grabA1[] = {6, 362, 426, 482, 461, 790, 704};
const PROGMEM uint16_t U_grabA2[] = {6, 362, 538, 467, 408, 792, 696};
const PROGMEM uint16_t U_grabA3[] = {6, 362, 728, 710, 282, 800, 754};
const PROGMEM uint16_t U_grabA4[] = {6, 362, 724, 705, 280, 799, 532};
const PROGMEM uint16_t U_grabB1[] = {6, 512, 426, 482, 461, 790, 704};
const PROGMEM uint16_t U_grabB2[] = {6, 512, 538, 467, 408, 792, 696};
const PROGMEM uint16_t U_grabB3[] = {6, 512, 728, 710, 282, 800, 754};
const PROGMEM uint16_t U_grabB4[] = {6, 512, 724, 705, 280, 799, 532};
const PROGMEM uint16_t U_grabC1[] = {6, 662, 426, 482, 461, 790, 704};
const PROGMEM uint16_t U_grabC2[] = {6, 662, 538, 467, 408, 792, 696};
const PROGMEM uint16_t U_grabC3[] = {6, 662, 728, 710, 282, 800, 754};
const PROGMEM uint16_t U_grabC4[] = {6, 662, 724, 705, 280, 799, 532};
const PROGMEM uint16_t U_putD1[] = {6, 362, 599, 564, 418, 790, 511};
const PROGMEM uint16_t U_putD2[] = {6, 362, 660, 564, 393, 791, 511};
const PROGMEM uint16_t U_putD3[] = {6, 362, 660, 564, 393, 791, 724};
const PROGMEM uint16_t U_putD4[] = {6, 362, 614, 628, 393, 791, 723};
const PROGMEM uint16_t U_putE1[] = {6, 513, 599, 564, 418, 790, 511};
const PROGMEM uint16_t U_putE2[] = {6, 512, 660, 564, 393, 791, 511};
const PROGMEM uint16_t U_putE3[] = {6, 512, 660, 564, 393, 791, 724};
const PROGMEM uint16_t U_putE4[] = {6, 513, 614, 628, 393, 791, 723};
const PROGMEM uint16_t U_putF1[] = {6, 662, 599, 564, 418, 790, 511};
const PROGMEM uint16_t U_putF2[] = {6, 662, 660, 564, 393, 791, 511};
const PROGMEM uint16_t U_putF3[] = {6, 662, 660, 564, 393, 791, 724};
const PROGMEM uint16_t U_putF4[] = {6, 662, 614, 628, 393, 791, 723};
const PROGMEM uint16_t U_catchA1[] = {6, 362, 465, 574, 408, 632, 793};
const PROGMEM uint16_t U_catchA2[] = {6, 362, 716, 665, 595, 530, 792};
const PROGMEM uint16_t U_catchA3[] = {6, 362, 723, 660, 593, 528, 532};
const PROGMEM uint16_t U_catchB1[] = {6, 512, 465, 574, 408, 632, 793};
const PROGMEM uint16_t U_catchB2[] = {6, 512, 716, 665, 595, 530, 792};
const PROGMEM uint16_t U_catchB3[] = {6, 512, 723, 660, 593, 528, 532};
const PROGMEM uint16_t U_catchC1[] = {6, 662, 465, 574, 408, 632, 793};
const PROGMEM uint16_t U_catchC2[] = {6, 662, 716, 665, 595, 530, 792};
const PROGMEM uint16_t U_catchC3[] = {6, 662, 723, 660, 593, 528, 532};
//===== User Define Sequence ======
const PROGMEM transition_t U_arm_stop[] = {{0,1} ,{U_init1,500}};
const PROGMEM transition_t U_arm_move[] = {{0,8} ,{U_arm1,500} ,{U_arm2,500} ,{U_arm1,500} ,{U_init1,400} ,{U_arm3,500} ,{U_arm4,500} ,{U_arm3,500} ,{U_init1,500}};
const PROGMEM transition_t U_nod[] = {{0,5} ,{U_yes1,400} ,{U_yes2,400} ,{U_yes1,400} ,{U_yes2,400} ,{U_init1,500}};
const PROGMEM transition_t U_refuse[] = {{0,7} ,{U_yes2,500} ,{U_no1,500} ,{U_no2,500} ,{U_no1,500} ,{U_no2,500} ,{U_yes2,200} ,{U_init1,500}};
const PROGMEM transition_t U_pleasure[] = {{0,7} ,{U_happy1,500} ,{U_happy2,500} ,{U_happy3,500} ,{U_happy4,500} ,{U_happy2,500} ,{U_happy3,500} ,{U_init1,500}};
const PROGMEM transition_t U_M12_move[] = {{0,8} ,{U_M12_F,600} ,{U_init1,500} ,{U_M12_B,600} ,{U_init1,500} ,{U_M12_F,600} ,{U_init1,500} ,{U_M12_B,600} ,{U_init1,500}};
const PROGMEM transition_t U_M34_move[] = {{0,8} ,{U_M34_F,400} ,{U_init1,500} ,{U_M34_B,400} ,{U_init1,500} ,{U_M34_F,400} ,{U_init1,500} ,{U_M34_B,400} ,{U_init1,500}};
const PROGMEM transition_t U_M56_move[] = {{0,4} ,{U_M56_F,300} ,{U_init1,400} ,{U_M56_F,300} ,{U_init1,400}};
const PROGMEM transition_t U_GRABA[] = {{0,5} ,{U_grabA1,500} ,{U_grabA2,500} ,{U_grabA3,500} ,{U_grabA4,500} ,{U_init1,500}};
const PROGMEM transition_t U_GRABB[] = {{0,5} ,{U_grabB1,500} ,{U_grabB2,500} ,{U_grabB3,500} ,{U_grabB4,500} ,{U_init1,500}};
const PROGMEM transition_t U_GRABC[] = {{0,5} ,{U_grabC1,500} ,{U_grabC2,500} ,{U_grabC3,500} ,{U_grabC4,500} ,{U_init1,500}};
const PROGMEM transition_t U_PUTE[] = {{0,5} ,{U_putE1,500} ,{U_putE2,500} ,{U_putE3,500} ,{U_putE4,500} ,{U_init1,500}};
const PROGMEM transition_t U_PUTD[] = {{0,5} ,{U_putD1,500} ,{U_putD2,500} ,{U_putD3,500} ,{U_putD4,500} ,{U_init1,500}};
const PROGMEM transition_t U_PUTF[] = {{0,5} ,{U_putF1,500} ,{U_putF2,500} ,{U_putF3,500} ,{U_putF4,500} ,{U_init1,500}};
const PROGMEM transition_t U_CATCHA[] = {{0,4} ,{U_catchA1,500} ,{U_catchA2,500} ,{U_catchA3,500} ,{U_init1,500}};
const PROGMEM transition_t U_CATCHB[] = {{0,4} ,{U_catchB1,500} ,{U_catchB2,500} ,{U_catchB3,500} ,{U_init1,500}};
const PROGMEM transition_t U_CATCHC[] = {{0,4} ,{U_catchC1,500} ,{U_catchC2,500} ,{U_catchC3,500} ,{U_init1,500}};
////==== User Sequence Setup ====////
#define ActionNo_1   None
#define ActionNo_2   None
#define ActionNo_3   None
#define ActionNo_4   None
#define ActionNo_5   None
#define ActionNo_6   None
#define ActionNo_7   None
#define ActionNo_8   None
#define ActionNo_9   None
#define ActionNo_10   None
#define ActionNo_11   None
#define ActionNo_12   None
#define ActionNo_13   None
#define ActionNo_14   None
#define ActionNo_15   None
#define ActionNo_16   None
#define ActionNo_17   None
#define ActionNo_18   None
#define ActionNo_19   None
#define ActionNo_20   None
#define ActionNo_21   None
#define ActionNo_22   None
#define ActionNo_23   None
#define ActionNo_24   None
#define ActionNo_25   None
#define ActionNo_26   None
#define ActionNo_27   None
#define ActionNo_28   None
#define ActionNo_29   None
#define ActionNo_30   None
#define ActionNo_31   None
#define ActionNo_32   None
#define ActionNo_33   None
#define ActionNo_34   None
#define ActionNo_35   None
#define ActionNo_36   None
#define ActionNo_37   None
#define ActionNo_38   None
#define ActionNo_39   None
#define ActionNo_40   None
#define ActionNo_41   None
#define ActionNo_42   U_CATCHC
#define ActionNo_43   U_CATCHB
#define ActionNo_44   U_CATCHA
#define ActionNo_45   U_PUTF
#define ActionNo_46   U_PUTD
#define ActionNo_47   U_PUTE
#define ActionNo_48   U_GRABC
#define ActionNo_49   U_GRABB
#define ActionNo_50   U_GRABA
#define ActionNo_51   U_arm_move
#define ActionNo_52   U_M12_move
#define ActionNo_53   U_M34_move
#define ActionNo_54   U_M56_move

////==== Robot Button Control & Remote Control ====////
#define RB_1   0
#define RB_2   0
#define RB_3   0
#define RB_4   0
#define RCU_LJU   0
#define RCU_LJD   0
#define RCU_LJL   0
#define RCU_LJR   0
#define RCU_L1   0
#define RCU_L2   0
#define RCU_L3   0
#define RCU_R1   0
#define RCU_R2   0
#define RCU_R3   0
#define RCU_RJU   0
#define RCU_RJD   0
#define RCU_RJL   0
#define RCU_RJR   0

////==== Music Setup ====////
#define Music_1   "none"
#define Music_2   "none"
#define Music_3   "none"
#define Music_4   "none"
#define Music_5   "none"
#define Music_6   "none"
#define Music_7   "none"
#define Music_8   "none"
#define Music_9   "none"
#define Music_10   "none"
#define Music_11   "none"
#define Music_12   "none"
#define Music_13   "none"
#define Music_14   "none"
#define Music_15   "none"
#define Music_16   "none"
#define Music_17   "none"
#define Music_18   "none"
#define Music_19   "none"
#define Music_20   "none"
#define Music_21   "none"
#define Music_22   "none"
#define Music_23   "none"
#define Music_24   "none"
#define Music_25   "none"
#define Music_26   "none"
#define Music_27   "none"
#define Music_28   "none"
#define Music_29   "none"
#define Music_30   "none"
#define Music_31   "none"
#define Music_32   "none"
#define Music_33   "none"
#define Music_34   "none"
#define Music_35   "none"
#define Music_36   "none"
#define Music_37   "none"
#define Music_38   "none"
#define Music_39   "none"
#define Music_40   "none"
#define Music_41   "none"
#define Music_42   "none"
#define Music_43   "none"
#define Music_44   "none"
#define Music_45   "none"
#define Music_46   "none"
#define Music_47   "none"
#define Music_48   "none"
#define Music_49   "none"
#define Music_50   "none"
#define Music_51   "none"
#define Music_52   "none"
#define Music_53   "none"
#define Music_54   "none"

#endif

