#include "map/MapHooks.hpp"

Hook * MapHooks::newLevelHook;

void MapHooks::NewLevel(int level, int zone, int playerID, bool inEditor, LevelObject *levelObj, bool continuedRun) {
    newLevelHook->destroy();
    Level::NewLevel(level, zone, playerID, inEditor, levelObj, continuedRun);
    newLevelHook->install();

    if (level == -2) {
        prepareLobby();
    }
}

void MapHooks::setup() {
    newLevelHook = new Hook((int*) Level::ptr::NewLevel, (int*) NewLevel);
    newLevelHook->install();
}
