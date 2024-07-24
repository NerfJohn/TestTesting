/*
 * Button.h
 *
 *  Created on: Jul 24, 2024
 *      Author: John
 */

#ifndef SRC_DEVICELAYER_BUTTON_H_
#define SRC_DEVICELAYER_BUTTON_H_

#include "DomainLayer/DataModel_t.h"
#include "DomainLayer/RetErr_e.h"

// Updates model with button inputs.
RetErr_e Button_process(DataModel_t* model);

#endif /* SRC_DEVICELAYER_BUTTON_H_ */
