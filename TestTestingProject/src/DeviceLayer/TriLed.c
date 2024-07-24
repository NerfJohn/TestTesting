/*
 * TriLed.c
 *
 *  Created on: Jul 24, 2024
 *      Author: John
 */

#include "DriverLayer/HwTriLed.h"

#include <DeviceLayer/TriLed.h>

// =============================================================================
// Sets the 3 color LED based on given data model.
void TriLed_setColors(DataModel_t const* model) {
    // Simply set the LEDs.
    HwTriLed_set(model->m_redLed, model->m_greenLed, model->m_blueLed);
}
