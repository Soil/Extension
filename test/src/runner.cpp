// Compile with:
// gcc runner.cpp -lstdc++ -Wl,--no-as-needed -ldl -o ../runner

#include <iostream>
#include <dlfcn.h>

int main(int argc, const char* argv[]) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <input>" << std::endl;
        return 0;
    }

    void* handle = dlopen("./soil.so", RTLD_LAZY);
    if (handle == NULL) {
        std::cerr << "Error: Could not load soil.so." << std::endl;
        return 0;
    } else {
        typedef void (*func_ptr_t)(char*, int, const char*);
        func_ptr_t rvEntry = (func_ptr_t) dlsym(handle, "RVExtension");

        if (rvEntry == NULL) {
            std::cerr << "Error: Could not load RVExtension function." << std::endl;
            return 0;
        } else {
            char outputBuffer[10000];
            rvEntry(outputBuffer, 10000, argv[1]);
            std::cout << outputBuffer << std::endl;
        }

        dlclose(handle);
    }
    return 0;
}
