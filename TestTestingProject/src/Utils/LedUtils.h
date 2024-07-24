/*
 * LedUtils.h
 *
 *  Created on: Jul 24, 2024
 *      Author: John
 */

#ifndef SRC_UTILS_LEDUTILS_H_
#define SRC_UTILS_LEDUTILS_H_

#include "DomainLayer/LedState_e.h"

// Simply "inverts" the given input.
LedState_e LedUtils_invert(LedState_e state);

#endif /* SRC_UTILS_LEDUTILS_H_ */
