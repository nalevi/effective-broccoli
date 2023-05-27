
add_executable(${PROJECT_NAME}
        main.cc
        ../configured_files/EffectiveBroccoliConfig.hpp.in
        ${GENERATED_CPP_FILES}
        ProtoParser.cc)

target_include_directories(EffectiveBroccoli PRIVATE
        "${CMAKE_BINARY_DIR}/configured_files/include"
        ProtoParser.hh)
