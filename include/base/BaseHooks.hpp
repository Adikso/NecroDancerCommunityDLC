#ifndef COMMUNITYDLC_BASEHOOKS_HPP
#define COMMUNITYDLC_BASEHOOKS_HPP

#include "utils/Hook.h"
#include "NecroDancerGame.hpp"

class BaseHooks {
public:
    static void setup();

    static int onCreate(NecroDancerGame * self);

private:
    static Hook * onCreateHook;
};

#endif //COMMUNITYDLC_BASEHOOKS_HPP
