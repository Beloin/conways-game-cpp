cmake_minimum_required(VERSION 3.24)
project(conways_game)

set(CMAKE_CXX_STANDARD 14)

add_executable(conways_game
        main.cpp Interface.cpp Interface.h conf.h grid/Grid.cpp grid/Grid.h grid/Cell.cpp grid/Cell.h)
