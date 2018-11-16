#ifndef MULTIDANCER_HOOK_H
#define MULTIDANCER_HOOK_H

#include <unistd.h>
#include <cstdint>

class Hook {
public:
    intptr_t src;
    intptr_t dst;

    Hook(int *src, int *dst);

    void install();
    void destroy();

private:
    int * code;
    size_t codeSize;

    bool isCreated;

    void createJmp();
    struct jmp32 {
        unsigned char opcode;
        int32_t offset;
    };
};


#endif //MULTIDANCER_HOOK_H
