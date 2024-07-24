/*
 * TestHwAccess.h
 *
 * "Access point for tests to control/view hardware"
 */

#include "DriverLayer/HwButton1.h"
#include "DriverLayer/HwTriLed.h"

// Global values for drivers to read/write to.
extern ButtonState_e HW_BUTTON_1_STATE;
extern LedState_e    HW_3LED_RED_STATE;
extern LedState_e    HW_3LED_GREEN_STATE;
extern LedState_e    HW_3LED_BLUE_STATE;

// Sets current input value of button 1.
void setButton1(ButtonState_e state);

// Gets current red value of 3 color LED.
LedState_e get3LedRed(void);

// Gets current green value of 3 color LED.
LedState_e get3LedGreen(void);

// Gets current blue value of 3 color LED.
LedState_e get3LedBlue(void);
