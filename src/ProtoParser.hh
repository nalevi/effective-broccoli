#ifndef EFFECTIVEBROCCOLI_PROTOPARSER_H
#define EFFECTIVEBROCCOLI_PROTOPARSER_H

#include <string>

enum class ProtoParamType {
    STRING,
    INTEGER,
    DOUBLE
};

/// @brief Wrapper around the generated serialization classes
class ProtoParser {
public:
    ProtoParser();

};

#endif //EFFECTIVEBROCCOLI_PROTOPARSER_H
