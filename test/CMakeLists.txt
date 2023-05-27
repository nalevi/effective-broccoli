enable_testing()

add_executable(
        broccoli_test
        broccoli_test.cc
)
target_link_libraries(
        broccoli_test
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(broccoli_test)