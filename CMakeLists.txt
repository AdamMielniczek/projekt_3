cmake_minimum_required(VERSION 3.13)
project(AMielniczekProjekt2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -Ofast")


add_executable(AMielniczekProjekt2
        gra.cpp
        gra.h
        main.cpp
        minimax.cpp
        minimax.h
        plansza.cpp
        plansza.h)

target_link_libraries(AMielniczekProjekt2 -static)
