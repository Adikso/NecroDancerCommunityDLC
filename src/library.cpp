#include <iostream>
#include "CommunityDLC.hpp"

#ifdef _WIN32 // Windows
#include <windows.h>

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
        setup();
    }

    return TRUE;
}
#else // Linux and OSX
#include <dlfcn.h>
#include <unistd.h>

long int strtol(const char* str, char** endptr, int base) {
    static int (*original_strtol)(const char* str, char** endptr, int base) = nullptr;

    if (original_strtol == nullptr) {
        *(void **) (&original_strtol) = dlsym(RTLD_NEXT, "strtol");
        setup();
    }

    return original_strtol(str, endptr, base);
}
#endif
