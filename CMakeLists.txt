cmake_minimum_required(VERSION 3.22.2)

project(EffectiveBroccoli VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_BINARY_DIR}/conan_toolchain.cmake")
set(CMAKE_POLICY_DEFAULT_CMP0091 NEW)
set(CMAKE_POLICY_DEFAULT_CMP0042 NEW)

include(${CMAKE_TOOLCHAIN_FILE})

#include(FetchContent)
#FetchContent_Declare(
#        gRPC
#        GIT_REPOSITORY https://github.com/grpc/grpc
#        GIT_TAG v1.50.0
#)
#set(FETCHCONTENT_QUIET OFF)
#FetchContent_MakeAvailable(gRPC)

find_package(fmt REQUIRED)
find_package(GTest REQUIRED)
find_package(gRPC REQUIRED)
find_package(Protobuf REQUIRED)

set(PROTO_FILES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/proto)
set(GENERATED_FILES_DIR ${CMAKE_CURRENT_BINARY_DIR}/generated)

file(GLOB PROTO_FILES ${PROTO_FILES_DIR}/*.proto)
file(MAKE_DIRECTORY ${GENERATED_FILES_DIR})

foreach (PROTO_FILE ${PROTO_FILES})
    get_filename_component(PROTO_FILE_NAME ${PROTO_FILE} NAME_WE)
    set(GENERATED_FILES
            ${GENERATED_FILES_DIR}/${PROTO_FILE_NAME}.pb.cc
            ${GENERATED_FILES_DIR}/${PROTO_FILE_NAME}.pb.h
            ${GENERATED_FILES_DIR}/${PROTO_FILE_NAME}.grpc.pb.cc
            ${GENERATED_FILES_DIR}/${PROTO_FILE_NAME}.grpc.pb.h
            )
    add_custom_command(
            OUTPUT ${GENERATED_FILES}
            COMMAND /Users/nalevi/.local/bin/protoc # Need to make it a generic solution
            ARGS --cpp_out=${GENERATED_FILES_DIR}
            --grpc_out=${GENERATED_FILES_DIR}
            --proto_path=${PROTO_FILES_DIR}
            --plugin=protoc-gen-grpc=$<TARGET_FILE:gRPC::grpc_cpp_plugin>
            ${PROTO_FILE}
            DEPENDS ${PROTO_FILE}
            COMMENT "Generating C++ files from ${PROTO_FILE}"
    )
    list(APPEND GENERATED_CPP_FILES ${GENERATED_FILES})
endforeach ()

add_library(GeneratedProtobufFiles ${GENERATED_CPP_FILES})
target_include_directories(GeneratedProtobufFiles PUBLIC ${GENERATED_FILES_DIR})

add_subdirectory(configured_files)
add_subdirectory(src)
add_subdirectory(test)

target_link_libraries(${PROJECT_NAME}
        fmt::fmt
        #GTest::gtest
        gRPC::grpc++
        gRPC::grpc
        protobuf::libprotobuf)