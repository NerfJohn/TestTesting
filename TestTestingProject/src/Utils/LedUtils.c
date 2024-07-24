/*
 * LedUtils.c
 *
 *  Created on: Jul 24, 2024
 *      Author: John
 */

#include <Utils/LedUtils.h>

// =============================================================================
// Simply "inverts" the given input.
LedState_e LedUtils_invert(LedState_e state) {
    // Return the digital inversion of the signal.
    return (state == LED_ON) ? LED_OFF : LED_ON;
}
