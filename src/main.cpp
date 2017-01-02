#include "common.h"
#include <string.h>

extern "C" {
    EXPORT void RV_ENTRY(char *output, int outputSize, const char *function);
}

void RV_ENTRY(char *output, int outputSize, const char *function) {
    if (!strcmp(function, "version")) {
        strncpy(output, "0.1", outputSize);
    }
}
