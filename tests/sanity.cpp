/*
 * Sanity.cpp
 *
 * "Sanity check that tests do work"
 */

#include <gtest/gtest.h>

// Run some basic sanity tests.
TEST(SanityTest, BasicAssertions) {
	// Check basic assertions.
	EXPECT_STRNE("hello", "world");
	EXPECT_EQ(7 * 6, 42);
}
