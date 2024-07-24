/*
 * main.c
 */

#include <stdbool.h>
#include "DomainLayer/DataModel_t.h"
#include "DriverLayer/HwButton1.h"
#include "DriverLayer/HwTriLed.h"
#include "msp.h"
#include "Utils/LedUtils.h"

// TODO- move eventually- see below note.
#include "DeviceLayer/Button.h"
#include "DeviceLayer/TriLed.h"

/**
 * main.c
 */
void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer

	// Initialize data model.
	DataModel_t prgmData = {
	    .m_curButtonState  = BUTTON_RELEASED,
	    .m_prevButtonState = BUTTON_RELEASED,

	    .m_redLed          = LED_OFF,
	    .m_greenLed        = LED_ON,
	    .m_blueLed         = LED_OFF
	};

	// Initialize hardware.
	HwButton1_init();
	HwTriLed_init();

	// run main process loop // TODO- for brevity, steps are inlined here for now.
	while (1) {
	    // Collect inputs.
	    Button_process(&prgmData);

	    // Process inputs + state machine.
	    bool isPosEdge = ((prgmData.m_curButtonState == BUTTON_PRESSED) &&
	                      (prgmData.m_prevButtonState == BUTTON_PRESSED)
	                     );
	    bool isPressed = ((prgmData.m_curButtonState == BUTTON_PRESSED));

	    if (isPosEdge) {prgmData.m_redLed = LedUtils_invert(prgmData.m_redLed);}
	    prgmData.m_greenLed = (isPressed) ? LED_OFF : LED_ON;
	    prgmData.m_blueLed  = (isPressed) ? LED_ON  : LED_OFF;

	    // Drive outputs.
	    TriLed_setColors(&prgmData);
	}
}
