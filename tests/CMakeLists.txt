add_executable(
  result_test
  result_test.cpp
)
target_link_libraries(
  result_test
  GTest::gtest_main
  lib
)

target_include_directories(result_test PRIVATE ../src/)

include(GoogleTest)
gtest_discover_tests(result_test)