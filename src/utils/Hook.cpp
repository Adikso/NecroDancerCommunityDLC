#include <cstring>
#include <cstdlib>
#include "utils/Hook.h"
#include "utils/Memory.hpp"

Hook::Hook(int *src, int *dst) {
    this->src = (int) src;
    this->dst = (int) dst;
}

void Hook::install() {
    if (!this->isCreated) {
        createJmp();
    }

    auto offset = (int32_t) (this->dst - this->src - this->codeSize);

    *(unsigned char*) this->src = 0xE9;
    *(int32_t *) ((unsigned char*) this->src + 1) = offset;

//    auto * jmp = (struct jmp32 *) this->src;
//    jmp->opcode = 0xE9;
//    jmp->offset = offset;
}

void Hook::destroy() {
    memcpy((int*)this->src, this->code, this->codeSize);
}

void Hook::createJmp() {
    size_t len = 5;

    this->code = (int*) malloc(len);
    this->codeSize = len;
    memcpy(this->code, (int*)this->src, len);

    Memory::unprotect((int*)this->src, len);
    this->isCreated = true;
}
