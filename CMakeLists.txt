cmake_minimum_required(VERSION 3.22.2)

project(EffectiveBroccoli VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_BINARY_DIR}/conan_toolchain.cmake")
set(CMAKE_POLICY_DEFAULT_CMP0091 NEW)
include(${CMAKE_TOOLCHAIN_FILE})

find_package(fmt REQUIRED)
find_package(GTest REQUIRED)
find_package(grpc REQUIRED)

add_subdirectory(configured_files)
add_subdirectory(src)
add_subdirectory(test)

target_link_libraries(${PROJECT_NAME}
        fmt::fmt
        #GTest::gtest
        grpc::grpc parser)