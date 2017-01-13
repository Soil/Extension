#include "common.h"
#include <cstring>
#include <string>

extern "C" {
    EXPORT void RV_ENTRY(char* output, int outputSize, const char* function);
}

void RV_ENTRY(char* output, int outputSize, const char* function) {
    std::string input = std::string(function);
    if (input == "version") {
        strncpy_s(output, outputSize, "0.1", _TRUNCATE);
    }
}
