/*
 * TestHwAccess.c
 *
 * "Access point for tests to control/view hardware"
 */

#include "TestTools/TestHwAccess.h"

// Global values for drivers to read/write to.
ButtonState_e HW_BUTTON_1_STATE   = BUTTON_RELEASED;
LedState_e    HW_3LED_RED_STATE   = LED_OFF;
LedState_e    HW_3LED_GREEN_STATE = LED_OFF;
LedState_e    HW_3LED_BLUE_STATE  = LED_OFF;

// =============================================================================
// Sets current input value of button 1.
void setButton1(ButtonState_e state) {
	HW_BUTTON_1_STATE = state;
}

// =============================================================================
// Gets current red value of 3 color LED.
LedState_e get3LedRed(void) {
	return HW_3LED_RED_STATE;
}

// =============================================================================
// Gets current green value of 3 color LED.
LedState_e get3LedGreen(void) {
	return HW_3LED_GREEN_STATE;
}

// =============================================================================
// Gets current blue value of 3 color LED.
LedState_e get3LedBlue(void) {
	return HW_3LED_BLUE_STATE;
}
