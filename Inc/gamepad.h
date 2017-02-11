/*
 * gamepad.h
 *
 *  Created on: 10 лют. 2017 р.
 *      Author: volos
 */

#ifndef GAMEPAD_H_
#define GAMEPAD_H_


typedef struct __packed {
	volatile uint16_t buttons;
	volatile int8_t left_x;
	volatile int8_t left_y;
	volatile int8_t right_x;
	volatile int8_t right_y;
	volatile uint8_t hat_switch;
} Gamepad_Report_t;

typedef enum
{
  PAD_A 	= 0x01,
  PAD_B 	= 0x02,
  PAD_X 	= 0x04,
  PAD_Y 	= 0x08,
  PAD_LB 	= 0x10,
  PAD_RB 	= 0x20,

  PAD_SELECT = 0x40,
  PAD_START = 0x80,

  PAD_UP 	= 0x00,
  PAD_DOWN 	= 0x00,
  PAD_LEFT 	= 0x00,
  PAD_RIGHT	= 0x00,

  PAD_LT 	= 0x00, // Z == 127
  PAD_RT 	= 0x00  // Z == -127
} Gamepad_Button;

#endif /* GAMEPAD_H_ */
