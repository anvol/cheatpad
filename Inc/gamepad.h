/*
 * gamepad.h
 *
 *  Created on: 10 лют. 2017 р.
 *      Author: volos
 */

#ifndef GAMEPAD_H_
#define GAMEPAD_H_

#include "stm32f1xx_hal.h"

typedef struct
	__packed {
		int8_t msgType;
		int8_t bSize;
		int8_t bButtonPacket1;
		int8_t bButtonPacket2;
		int8_t left_trigger;
		int8_t right_trigger;
		int16_t left_x;
		int16_t left_y;
		int16_t right_x;
		int16_t right_y;
		int8_t reserved[6];

	} Gamepad_Report_t;

	typedef enum {
		PAD_X = 0x0001,
		PAD_A = 0x0002,
		PAD_B = 0x0004,
		PAD_Y = 0x0008,
		PAD_LB = 0x0010,
		PAD_RB = 0x0020,

		PAD_SELECT = 0x0040,
		PAD_START = 0x0080,

		PAD_LT = 0x0100, // Z == 127
		PAD_RT = 0x0200, // Z == -127

		PAD_UP = 0x0400,
		PAD_DOWN = 0x0800,
		PAD_LEFT = 0x1000,
		PAD_RIGHT = 0x2000,

	} Gamepad_Button;

	Gamepad_Report_t gamepadState;

	void PushButton(Gamepad_Button btn, uint32_t time_press_ms) {

		gamepadState.msgType = 0x00;
		gamepadState.bSize = 20;

		switch (btn) {

		case PAD_A:
			gamepadState.bButtonPacket2 = 0x10;
			break;

		case PAD_LB:
			gamepadState.bButtonPacket2 = 0x01;
			break;
		case PAD_RB:
			gamepadState.bButtonPacket2 = 0x02;
			break;

		case PAD_LT:
			gamepadState.left_trigger = 127;
			break;
		case PAD_RT:
			gamepadState.right_trigger = -127;
			break;

		case PAD_UP:
			gamepadState.bButtonPacket1 = 0x01;
			break;
		case PAD_DOWN:
			gamepadState.bButtonPacket1 = 0x02;
			break;
		case PAD_LEFT:
			gamepadState.bButtonPacket1 = 0x04;
			break;
		case PAD_RIGHT:
			gamepadState.bButtonPacket1 = 0x08;
			break;
		}

//		USBD_HID_SendReport(&hUsbDeviceFS, (uint8_t *)&gamepadState,
//				sizeof(Gamepad_Report_t));

//		gamepadState.bButtonPacket2 = 0;
//		gamepadState.bButtonPacket1 = 0;
//		gamepadState.left_trigger = 0;
//		gamepadState.right_trigger = 0;
//		gamepadState.left_y = 0;
//		gamepadState.left_x = 0;

		USBD_HID_SendReport(&hUsbDeviceFS, &gamepadState,
				sizeof(Gamepad_Report_t));
	}

#endif /* GAMEPAD_H_ */
