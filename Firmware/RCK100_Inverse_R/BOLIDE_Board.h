#ifndef BOLIDE_BOARD_H
#define BOLIDE_BOARD_H

#include <avr/pgmspace.h>

typedef struct{
	const transition_t * Seq_A1_16;
} Action_t;

/*======== Hardware Definition ========*/
/*==== Pin Definition ====*/
/*== Digital Output ==*/
#define PIN_BUZZER						4
#define PIN_LED_EYE_BLE					25
#define PIN_LED_EYE_GRN					26
#define PIN_LED_LSA_BLE					44
#define PIN_LED_LSA_GRN					45
#define PIN_LED_LSA_RED					46
/*== Digital Input ==*/
#define PIN_BUTTON_1					32
#define PIN_BUTTON_2					33
#define PIN_BUTTON_3					34
#define PIN_BUTTON_4					35
/*== Analog Input ==*/
#define PIN_PWRDET						A0
#define PIN_IR							A3

/*======== Software Definition ========*/
/*==== LED Eye Function ====*/
#define LED_EYE_BLE_ON					digitalWrite(PIN_LED_EYE_BLE, HIGH), digitalWrite(PIN_LED_EYE_GRN, LOW)
#define LED_EYE_GRN_ON					digitalWrite(PIN_LED_EYE_BLE, HIGH), digitalWrite(PIN_LED_EYE_GRN, LOW)
#define LED_EYE_OFF						digitalWrite(PIN_LED_EYE_BLE, HIGH), digitalWrite(PIN_LED_EYE_GRN, LOW)
/*==== Timer Function ====*/
#define TIMER3_ENABLE					TIMSK3 |= _BV(TOIE3)
#define TIMER3_DISABLE					TIMSK3 &= ~_BV(TOIE3)
#define TIMER3_RESET(t)					TCNT3 = -t
#define TIMER4_ENABLE					TIMSK4 |= _BV(TOIE4)
#define TIMER4_DISABLE					TIMSK4 &= ~_BV(TOIE4)
#define TIMER4_RESET(t)					TCNT4 = -t

#define TIMEOUT_LIMIT					15625	// Ticks for 1 sec @16 MHz,prescale : 1024

/*==== Power Function ====*/
#define TIME_SYSTEM_DETECT				1000
#define LIMIT_POWER_MAX					1022
#define LIMIT_POWER_MIN					756
#define LIMIT_COUNTER_POWER				5

/*==== A1-30 Function ====*/
#define DEFAULT_KP						6000
#define DEFAULT_KD						2500

/*==== BT Communication Constant ====*/
/*== BT_packet[0]:BT Header 0 ==*/
/*== BT_packet[1]:Left Joystick X ==*/
/*== BT_packet[2]:Left Joystick Y ==*/
/*== BT_packet[3]:Right Joystick X ==*/
/*== BT_packet[4]:Right Joystick Y ==*/

/*== BT_packet[5] ==*/
#define MASK_RCU_R1						0x0001
#define MASK_RCU_R2						0x0002
#define MASK_RCU_R3						0x0004
#define MASK_RCU_RELEASE				0x0010
#define MASK_RCU_BT						0x0020
#define MASK_RCU_POWER					0x0040
/*== BT_packet[6] ==*/
#define MASK_RCU_L1						0x0001
#define MASK_RCU_L2						0x0002
#define MASK_RCU_L3						0x0004
#define MASK_RCU_PACKET_NUMBER			0x00F0

#define THERHOLD_JOYSTICK				75

/*==== LSA LED Constant ====*/
#define MASK_LSA_LED_MODE				0x01			// 0 : Normal Mode, 1 : PWM Mode
#define MASK_LSA_LED_RED				0x02
#define MASK_LSA_LED_GRN				0x04
#define MASK_LSA_LED_BLE				0x08
#define MASK_EYE_LED_BLE				0x10
#define MASK_EYE_LED_GRN				0x20

#define TIMER_LED_SET_LSA				10

#define COUNTER_FLASH_LIMIT				40

#define LSA_LED_RED(brightness)			OCR5A = brightness
#define LSA_LED_GRN(brightness)			OCR5B = brightness
#define LSA_LED_BLE(brightness)			OCR5C = brightness

#define LSA_LED_OFF()					OCR5A = 0, OCR5B = 0, OCR5C = 0

#define LED_MODE_NUMBER					4
#define LED_MODE_ERROR					0
#define LED_MODE_SEQ					1
#define LED_MODE_EEP					2
#define LED_MODE_CLOSE					3

/*==== LSA Music Constant ====*/
#define MASK_LSA_MUSIC_UPDATE			0x01
#define MASK_LSA_MUSIC_PLAYING			0x02

#define LSA_LIST_NUMBER					0
#define LSA_LIST_SAVE					1
#define LSA_LIST_PLAY_POSE				2
#define LSA_LIST_MOTION					3

/*==== G-sensor ADXL345 Constant ====*/
#define ADDR_I2C_ADXL345				0x1D

#define REG_THRESH_TAP_ADXL345			0x1D
#define REG_OFSX_ADXL345				0x1E
#define REG_OFSY_ADXL345				0x1F
#define REG_OFSZ_ADXL345				0x20
#define REG_DUR_ADXL345					0x21
#define REG_LATENT_ADXL345				0x22
#define REG_WINDOW_ADXL345				0x23
#define REG_THRESH_ACT_ADXL345			0x24
#define REG_THRESH_INACT_ADXL345		0x25
#define REG_TIME_INACT_ADXL345			0x26
#define REG_ACT_INACT_CTL_ADXL345		0x27
#define REG_THRESH_FF_ADXL345			0x28
#define REG_TIME_FF_ADXL345				0x29
#define REG_TAP_AXES_ADXL345			0x2A
#define REG_ACT_TAP_STATUS_ADXL345		0x2B
#define REG_BW_RATE_ADXL345				0x2C
#define REG_POWER_CTL_ADXL345			0x2D
#define REG_INT_ENABLE_ADXL345			0x2E
#define REG_INT_MAP_ADXL345				0x2F
#define REG_INT_SOURCE_ADXL345			0x30
#define REG_DATA_FORMAT_ADXL345			0x31
#define REG_DATA_X0_ADXL345				0x32
#define REG_DATA_X1_ADXL345				0x33
#define REG_DAYA_Y0_ADXL345				0x34
#define REG_DATA_Y1_ADXL345				0x35
#define REG_DATA_Z0_ADXL345				0x36
#define REG_DATA_Z1_ADXL345				0x37
#define REG_FIFO_CTL_ADXL345			0x38
#define REG_FIFO_STATUS_ADXL345			0x39

#define REG_POWER_CTL_ADXL345			0x2D

#define TIMER_DEBOUNCE_ADXL345			100

/*==== Button Constant ====*/
#define MASK_BUTTON_SAMPLEING			0x3C	// 0011 1100, PC2~PC5

#define MASK_BUTTON_1					0x08
#define MASK_BUTTON_2					0x04
#define MASK_BUTTON_3					0x02
#define MASK_BUTTON_4					0x01
#define MASK_BUTTON_1_LT				0x80
#define MASK_BUTTON_2_LT				0x40
#define MASK_BUTTON_3_LT				0x20
#define MASK_BUTTON_4_LT				0x10

#define TIMER_DEBOUNCE_BUTTON			20
#define COUNTER_LT_BUTTON				30		// long trigger

#define COUNTER_DEBOUNCE_BUTTON			2

/*======== LSA LED Freqency ========*/
const PROGMEM uint16_t BRIGHTNESS_LOG[41] = { 1,
											1, 1, 2, 2, 2, 3, 3, 4, 5, 6,
											7, 8, 10, 11, 13, 16, 19, 23, 27, 32,
											38, 45, 54, 64, 76, 90, 108, 128, 152, 181,
											215, 256, 304, 362, 430, 512, 608, 723, 860, 1023};

#endif