#include "utils/Memory.hpp"

#if defined(__linux__)
#include <unistd.h>
#include <sys/mman.h>

void Memory::unprotect(void * address, size_t len) {
    long pagesize = sysconf(_SC_PAGESIZE);
    auto *page = (void *)((int) address & ~(pagesize - 1));

    mprotect(page, len, PROT_READ | PROT_WRITE | PROT_EXEC);
}
#endif

bool Memory::isSameType(int *a, int *b) {
    return *a == *b;
}