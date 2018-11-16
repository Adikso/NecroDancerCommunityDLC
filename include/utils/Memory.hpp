#ifndef COMMUNITYDLC_MEMORY_HPP
#define COMMUNITYDLC_MEMORY_HPP

#include <cstdlib>

class Memory {
public:
    static void unprotect(void * address, size_t len);
    static bool isSameType(int *a, int *b);
    static void * (*gc_malloc)(int size);
};

#endif //COMMUNITYDLC_MEMORY_HPP
