/*
 * HwButton1.c
 *
 *  Created on: Jul 24, 2024
 *      Author: John
 */

#include "msp.h"

#include "DriverLayer/HwButton1.h"

// =============================================================================
// Initializes hardware for button 1 usage.
void HwButton1_init(void) {
    // Set as input.
    P1->DIR &= ~BIT1;

    // Set internal pull up resistor.
    P1->REN |= BIT1; // enable resistors
    P1->OUT |= BIT1; // pulled up
}

// =============================================================================
// Reads state of button 1.
ButtonState_e HwButton1_read(void) {
    // Return based on read (active low button).
    return ((P1->IN & BIT1) == 0) ? BUTTON_PRESSED : BUTTON_RELEASED;
}
