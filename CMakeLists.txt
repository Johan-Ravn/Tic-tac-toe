cmake_minimum_required(VERSION 3.1)
project(Tic-tac-toe C)
set(CMAKE_C_STANDARD 11)

add_executable(main src/main.c)
add_library(minimax-lib src/mini-max.c)
add_library(game-lib src/game.c)
target_link_libraries(main minimax-lib)
target_link_libraries(main game-lib)
