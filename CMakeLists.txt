cmake_minimum_required(VERSION 3.12)
project(communitydlc)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS -m32)

add_library(communitydlc SHARED src/library.cpp src/CommunityDLC.cpp)
target_include_directories(communitydlc PUBLIC include)
