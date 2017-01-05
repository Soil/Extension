#include "common.h"
#include <string.h>
#include "hull.h"
#include <vector>
#include <iostream>

extern "C" {
    EXPORT void RV_ENTRY(char *output, int outputSize, const char *function);
}

void RV_ENTRY(char *output, int outputSize, const char *function) {
    if (!strcmp(function, "version")) {
        strncpy(output, "0.1", outputSize);
    }
}

int main(int argc, char const *argv[]) {
    std::vector<position> test;
    test.push_back(new float[3] {0, 0, 0});
    test.push_back(new float[3] {1, 0, 0});
    test.push_back(new float[3] {1, 1, 0});
    test.push_back(new float[3] {0, 1, 0});
    test.push_back(new float[3] {0.5, 0.5, 0});

    std::vector<position> hull = Soil::Hull::findFromPositions(test);
    for (position p: hull) {
        std::cout << "[" << p[0] << ", " << p[1] << "]" << std::endl;
    }

    return 0;
}
