// Library exports
#if defined(_MSC_VER)
    #define EXPORT __declspec(dllexport)
#elif defined(__GNUC__)
    #define EXPORT __attribute__((visibility("default")))
#else
    #define EXPORT
    #pragma warning Unknown dynamic link export semantic.
#endif

// RV extension entry
#if defined(_MSC_VER)
    #define WIN32_LEAN_AND_MEAN
    #include <windows.h>
    #define RV_ENTRY __stdcall RVExtension
#else
    #define RV_ENTRY RVExtension
#endif
