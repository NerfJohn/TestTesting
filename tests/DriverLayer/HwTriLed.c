/*
 * HwTriLed.c
 *
 *  Created on: Jul 24, 2024
 *      Author: John
 */

#include "TestTools/TestHwAccess.h"

#include "DriverLayer/HwTriLed.h"

// =============================================================================
// Initialized hardware for 3 color LED.
void HwTriLed_init(void) {
    /* Test Dummy- no setup to do */
}

// =============================================================================
// Sets 3 digital LEDs of 3 color LED.
void HwTriLed_set(LedState_e red, LedState_e green, LedState_e blue) {
    /* Test Dummy- set tester data*/
	HW_3LED_RED_STATE   = red;
	HW_3LED_GREEN_STATE = green;
	HW_3LED_BLUE_STATE  = blue;
}
