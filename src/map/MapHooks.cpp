#include "map/MapHooks.hpp"
#include "map/LevelGenerator.hpp"
#include "globals.hpp"

Hook * MapHooks::newLevelHook;
Hook * MapHooks::createMapZone1Hook;

void MapHooks::NewLevel(int level, int zone, int playerID, bool inEditor, LevelObject *levelObj, bool continuedRun) {
    newLevelHook->destroy();
    Level::NewLevel(level, zone, playerID, inEditor, levelObj, continuedRun);
    newLevelHook->install();

    if (level == -2) {
        prepareLobby();
    }
}

bool MapHooks::CreateMapZone1() {
    int zone = *global::currentZone;

    if (zone == 6) {
        LevelGenerator generator;
        return generator.createMap();
    }

    createMapZone1Hook->destroy();
    bool result = Level::CreateMapZone1();
    createMapZone1Hook->install();

    return result;
}

void MapHooks::setup() {
    newLevelHook = new Hook((int*) Level::ptr::NewLevel, (int*) NewLevel);
    newLevelHook->install();

    createMapZone1Hook = new Hook((int*) Level::ptr::CreateMapZone1, (int*) CreateMapZone1);
    createMapZone1Hook->install();
}
