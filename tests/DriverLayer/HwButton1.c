/*
 * HwButton1.c
 *
 *  Created on: Jul 24, 2024
 *      Author: John
 */

#include "TestTools/TestHwAccess.h"

#include "DriverLayer/HwButton1.h"

// =============================================================================
// Initializes hardware for button 1 usage.
void HwButton1_init(void) {
	/* Test Dummy- no setup to do */
}

// =============================================================================
// Reads state of button 1.
ButtonState_e HwButton1_read(void) {
	/* Test Dummy- return value set by tester */
	return HW_BUTTON_1_STATE;
}
