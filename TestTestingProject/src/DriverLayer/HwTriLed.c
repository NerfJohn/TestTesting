/*
 * HwTriLed.c
 *
 *  Created on: Jul 24, 2024
 *      Author: John
 */

#include "msp.h"

#include "DriverLayer/HwTriLed.h"

// =============================================================================
// Initialized hardware for 3 color LED.
void HwTriLed_init(void) {
    // Set as outputs.
    P2->DIR |= (BIT2 | BIT1 | BIT0);

    // Turn off.
    P2->OUT &= ~(BIT2 | BIT1 | BIT0);
}

// =============================================================================
// Sets 3 digital LEDs of 3 color LED.
void HwTriLed_set(LedState_e red, LedState_e green, LedState_e blue) {
    // Get P2->OUT (w/ RGB LEDs off).
    uint8_t retOuts = P2->OUT & ~(BIT2 | BIT1 | BIT0);

    // Turn LEDs on as needed.
    retOuts = (red == LED_ON) ? (retOuts | BIT0) : retOuts;
    retOuts = (green == LED_ON) ? (retOuts | BIT1) : retOuts;
    retOuts = (blue == LED_ON) ? (retOuts | BIT2) : retOuts;

    // Write P2->OUT (and LEDs with it).
    P2->OUT = retOuts;
}
