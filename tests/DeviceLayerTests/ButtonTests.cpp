/*
 * ButtonTests.cpp
 *
 * "Tests regarding Button device"
 */

extern "C" {
#include "DeviceLayer/Button.h"

#include "TestTools/TestHwAccess.h"
}

#include <gtest/gtest.h>

// Check it updates model correctly for constantly released button.
TEST(ButtonTests, NoPressButton) {
	// Prep model.
	DataModel_t model;
	model.m_curButtonState  = BUTTON_RELEASED;
	model.m_prevButtonState = BUTTON_RELEASED;
	
	// Prep "hardware".
	setButton1(BUTTON_RELEASED);
	
	// Run Button code.
	Button_process(&model);
	
	// Run checks.
	EXPECT_EQ(model.m_curButtonState, BUTTON_RELEASED);
	EXPECT_EQ(model.m_prevButtonState, BUTTON_RELEASED);
}

// Check it updates model correctly for positive edge of button.
TEST(ButtonTests, PosEdgeButton) {
	// Prep model.
	DataModel_t model;
	model.m_curButtonState  = BUTTON_RELEASED;
	model.m_prevButtonState = BUTTON_RELEASED;
	
	// Prep "hardware".
	setButton1(BUTTON_PRESSED);
	
	// Run Button code.
	Button_process(&model);
	
	// Run checks.
	EXPECT_EQ(model.m_curButtonState, BUTTON_PRESSED);
	EXPECT_EQ(model.m_prevButtonState, BUTTON_RELEASED);
}

// Check it updates model's two states in the proper order.
TEST(ButtonTests, UpdateOrderButton) {
	// Prep model.
	DataModel_t model;
	model.m_curButtonState  = BUTTON_RELEASED;
	model.m_prevButtonState = BUTTON_RELEASED;
	
	// Prep "hardware".
	setButton1(BUTTON_PRESSED);
	
	// Run Button code.
	Button_process(&model);
	
	// Run checks.
	EXPECT_EQ(model.m_curButtonState, BUTTON_PRESSED);
	EXPECT_EQ(model.m_prevButtonState, BUTTON_RELEASED);
	
	// Update "hardware".
	setButton1(BUTTON_RELEASED);
	
	// Run Button code.
	Button_process(&model);
	
	// Run checks.
	EXPECT_EQ(model.m_curButtonState, BUTTON_RELEASED);
	EXPECT_EQ(model.m_prevButtonState, BUTTON_PRESSED);
}

// Check process function returns based on success of updating model.
TEST(ButtonTests, BadInputButton) {
	// Prep model.
	DataModel_t model;
	model.m_curButtonState  = BUTTON_RELEASED;
	model.m_prevButtonState = BUTTON_RELEASED;
	
	// Prep "hardware".
	setButton1(BUTTON_PRESSED);
	
	// Run Button code.
	RetErr_e ret = Button_process(&model);
	
	// Run checks.
	EXPECT_EQ(model.m_curButtonState, BUTTON_PRESSED);
	EXPECT_EQ(model.m_prevButtonState, BUTTON_RELEASED);
	EXPECT_EQ(ret, RET_GOOD);
	
	// Run Button code with model that cannot be updated.
	ret = Button_process((DataModel_t*)(0));
	
	// Run checks.
	EXPECT_EQ(model.m_curButtonState, BUTTON_PRESSED);
	EXPECT_EQ(model.m_prevButtonState, BUTTON_RELEASED);
	EXPECT_EQ(ret, RET_FAIL);
}