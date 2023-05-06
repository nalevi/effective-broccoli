add_subdirectory(parser)
add_executable(EffectiveBroccoli main.cpp ../configured_files/EffectiveBroccoliConfig.hpp.in)
target_include_directories(EffectiveBroccoli PRIVATE
        "${CMAKE_BINARY_DIR}/configured_files/include")
