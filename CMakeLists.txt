cmake_minimum_required(VERSION 3.14)
project(TestTesting)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Location definitions for extracting files needed for testing.
set(PROD_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/TestTestingProject/src)
set(PROD_DRIVERS ${PROD_ROOT}/DriverLayer)
set(PROD_REL_MAIN TestTestingProject/src/main.c)
set(TEST_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/tests)

# Get list of testable sources (exclude main and drivers- native testing).
file(GLOB_RECURSE DUT_SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${PROD_ROOT}/*.c)
file(GLOB_RECURSE DUT_DRIVERS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${PROD_DRIVERS}/*.c)
list(REMOVE_ITEM DUT_SRCS ${DUT_DRIVERS} ${PROD_REL_MAIN}) # delete main.c relative to current directory

# Get list of test sources.
file(GLOB_RECURSE TST_SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${TEST_ROOT}/*.cpp ${TEST_ROOT}/*.c)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  all_tests
  ${DUT_SRCS}
  ${TST_SRCS}
)
target_include_directories(
  all_tests
  PUBLIC
  ${PROD_ROOT}
  ${TEST_ROOT}
)
target_link_libraries(
  all_tests
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(all_tests)