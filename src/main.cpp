#include "internal_use_only/EffectiveBroccoliConfig.hpp"

#include <fmt/format.h>
#include <iostream>


int main(int argc, char **argv) {
    std::cout << "Hello, this is effective-broccoli!\n";
    fmt::print("Version {}.{}", EffectiveBroccoli_VERSION_MAJOR, EffectiveBroccoli_VERSION_MINOR);

    return 0;
}

