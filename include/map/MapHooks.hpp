#ifndef COMMUNITYDLC_MAPHOOKS_HPP
#define COMMUNITYDLC_MAPHOOKS_HPP

#include <utils/Hook.h>
#include "Lobby.hpp"

class MapHooks {
public:
    static void setup();

    static void NewLevel(int level, int zone, int playerID, bool inEditor, LevelObject * levelObj, bool continuedRun);

private:
    static Hook * newLevelHook;
};

#endif //COMMUNITYDLC_MAPHOOKS_HPP
