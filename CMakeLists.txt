cmake_minimum_required(VERSION 3.14)
project(GoFIsh)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(GoFIsh
        card.cpp
        card.h
        deck.cpp
        deck.h
        go_fish.cpp
        player.cpp
        player.h)
