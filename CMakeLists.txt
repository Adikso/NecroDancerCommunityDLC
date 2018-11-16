cmake_minimum_required(VERSION 3.12)
project(communitydlc)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS -m32)

add_library(communitydlc SHARED src/library.cpp src/CommunityDLC.cpp include/map/MapHooks.hpp src/map/MapHooks.cpp

        src/utils/Memory.cpp
        include/utils/Memory.hpp
        src/utils/Hook.cpp include/map/Lobby.hpp src/map/Lobby.cpp include/base/BaseHooks.hpp src/base/BaseHooks.cpp include/map/LevelGenerator.hpp src/map/LevelGenerator.cpp)
target_include_directories(communitydlc PUBLIC include)
target_include_directories(communitydlc PUBLIC game/headers)
