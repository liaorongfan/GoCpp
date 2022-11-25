cmake_minimum_required(VERSION 3.20)
project(snake)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(snake
        Game.cpp
        Game.h
        main.cpp
        Player.h
        SmartArr.h
        SmartArrNode.h
        Snake.cpp
        Snake.h
        test.cpp)
