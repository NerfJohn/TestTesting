/*
 * DataModel_t.h
 *
 *  Created on: Jul 24, 2024
 *      Author: John
 */

#ifndef SRC_DOMAINLAYER_DATAMODEL_T_H_
#define SRC_DOMAINLAYER_DATAMODEL_T_H_

#include "DomainLayer/ButtonState_e.h"
#include "DomainLayer/LedState_e.h"

// Pertinent data passed between layers of program.
typedef struct {
    // General status of pushbutton.
    ButtonState_e m_curButtonState;
    ButtonState_e m_prevButtonState;

    // General status of 3 LEDs.
    LedState_e m_redLed;
    LedState_e m_greenLed;
    LedState_e m_blueLed;
} DataModel_t;

#endif /* SRC_DOMAINLAYER_DATAMODEL_T_H_ */
