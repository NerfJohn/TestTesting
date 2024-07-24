/*
 * TriLed.h
 *
 *  Created on: Jul 24, 2024
 *      Author: John
 */

#ifndef SRC_DEVICELAYER_TRILED_H_
#define SRC_DEVICELAYER_TRILED_H_

#include "DomainLayer/DataModel_t.h"

// Sets the 3 color LED based on given data model.
void TriLed_setColors(DataModel_t const* model);

#endif /* SRC_DEVICELAYER_TRILED_H_ */
