/*
 * HwTriLed.h
 *
 *  Created on: Jul 24, 2024
 *      Author: John
 */

#ifndef SRC_DRIVERLAYER_HWTRILED_H_
#define SRC_DRIVERLAYER_HWTRILED_H_

#include "DomainLayer/LedState_e.h"

// Initialized hardware for 3 color LED.
void HwTriLed_init(void);

// Sets 3 digital LEDs of 3 color LED.
void HwTriLed_set(LedState_e red, LedState_e green, LedState_e blue);

#endif /* SRC_DRIVERLAYER_HWTRILED_H_ */
