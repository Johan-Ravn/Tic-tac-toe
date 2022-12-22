
#ifndef MINIMAX_H
#define MINIMAX_H

#include <stdlib.h>
#include <stdbool.h>

#include "game.h"

#define MAX 1000
#define MIN -1000
#define COMPUTER 'X'
#define HUMAN 'O'

int miniMax(char *board[], char player);
void best_move(char *board[], char player, int *move);

#endif