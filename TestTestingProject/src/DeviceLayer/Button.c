/*
 * Button.c
 *
 *  Created on: Jul 24, 2024
 *      Author: John
 */

#include "DriverLayer/HwButton1.h"

#include "DeviceLayer/Button.h"

// =============================================================================
// Updates model with button inputs.
RetErr_e Button_process(DataModel_t* model) {
    // Return code, indicating process status.
    RetErr_e retCode = RET_GOOD; // innocent till guilty

    // Get most recent button value.
    ButtonState_e newState = HwButton1_read();

    // Update model (if valid pointer).
    if (0 == model) {
        retCode = RET_FAIL;
    }
    else {
        // Valid pointer- move state contents.
        model->m_prevButtonState = model->m_curButtonState;
        model->m_curButtonState  = newState;
    }

    // Return result of processing.
    return retCode;
}
