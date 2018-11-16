#include "map/LevelGenerator.hpp"

bool LevelGenerator::createMap() {
    Level::InitNewMap(true);
    auto * room = Level::PlaceFirstRoom();

    Level::PlaceExit(room);
    Level::CreateIndestructibleBorder();

    return true;
}
