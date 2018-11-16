#include "globals.hpp"
#include "base/BaseHooks.hpp"

Hook * BaseHooks::onCreateHook;

int BaseHooks::onCreate(NecroDancerGame *self) {
    onCreateHook->destroy();
    int result = self->OnCreate();
    onCreateHook->install();

    *global::DEBUG_BUILD = true;

    return result;
}

void BaseHooks::setup() {
    onCreateHook = new Hook((int *) NecroDancerGame::ptr::OnCreate, (int *) onCreate);
    onCreateHook->install();
}
