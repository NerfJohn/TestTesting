/*
 * HwButton1.h
 *
 *  Created on: Jul 24, 2024
 *      Author: John
 */

#ifndef SRC_DRIVERLAYER_HWBUTTON1_H_
#define SRC_DRIVERLAYER_HWBUTTON1_H_

#include "DomainLayer/ButtonState_e.h"

// Initializes hardware for button 1 usage.
void HwButton1_init(void);

// Reads state of button 1.
ButtonState_e HwButton1_read(void);

#endif /* SRC_DRIVERLAYER_HWBUTTON1_H_ */
