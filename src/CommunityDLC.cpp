#include <iostream>
#include "base/BaseHooks.hpp"
#include "map/MapHooks.hpp"
#include "CommunityDLC.hpp"

void setup() {
    std::cout << "Crypt of the NecroDancer Community Mod" << std::endl;

    MapHooks::setup();
    BaseHooks::setup();
}
