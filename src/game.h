
#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ROWS 3
#define COLUMNS 3
#define EMPTY_SPACE '_'

typedef enum {
    WINNER = 0,
    TIE = 1,
    ONGOING = 2
} result;

void print_board(char *board[]);
int game_state(char *board[]);
void move(char *board[], char player);
char switch_player(char player);

#endif
