#include "map/Lobby.hpp"

void prepareLobby() {
    createZoneEntrance();
}

void createZoneEntrance() {
    auto * zone6Text = new String(L"Zone 6", 6);

    Tile *entranceTile = Level::PlaceTileRemovingExistingTiles(3, 4, 2, false, 0, false);
    entranceTile->AddTextLabel(zone6Text, 0, 0, 0.0f, false, true);
    Level::AddExit(3, 4, 1, 6);

    delete(zone6Text);
}