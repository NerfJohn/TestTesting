/*
 * TriLedTests.cpp
 *
 * "Tests regarding TriLed device"
 */

extern "C" {
#include "DeviceLayer/TriLed.h"

#include "TestTools/TestHwAccess.h"
}

#include <gtest/gtest.h>

// Check it updates model is used to update the red LED.
TEST(TriLedTests, RedLed) {
	// Prep model.
	DataModel_t model;
	model.m_redLed = LED_OFF;
	
	// Run TriLed code.
	TriLed_setColors(&model);
	
	// Run checks.
	EXPECT_EQ(get3LedRed(), LED_OFF);

	// Prep model.
	model.m_redLed = LED_ON;
	
	// Run TriLed code.
	TriLed_setColors(&model);
	
	// Run checks.
	EXPECT_EQ(get3LedRed(), LED_ON);
}

// Check it updates model is used to update the green LED.
TEST(TriLedTests, GreenLed) {
	// Prep model.
	DataModel_t model;
	model.m_greenLed = LED_OFF;
	
	// Run TriLed code.
	TriLed_setColors(&model);
	
	// Run checks.
	EXPECT_EQ(get3LedGreen(), LED_OFF);

	// Prep model.
	model.m_greenLed = LED_ON;
	
	// Run TriLed code.
	TriLed_setColors(&model);
	
	// Run checks.
	EXPECT_EQ(get3LedGreen(), LED_ON);
}

// Check it updates model is used to update the blue LED.
TEST(TriLedTests, BlueLed) {
	// Prep model.
	DataModel_t model;
	model.m_blueLed = LED_OFF;
	
	// Run TriLed code.
	TriLed_setColors(&model);
	
	// Run checks.
	EXPECT_EQ(get3LedBlue(), LED_OFF);

	// Prep model.
	model.m_blueLed = LED_ON;
	
	// Run TriLed code.
	TriLed_setColors(&model);
	
	// Run checks.
	EXPECT_EQ(get3LedBlue(), LED_ON);
}
