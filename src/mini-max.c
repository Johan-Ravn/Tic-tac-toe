
#include "mini-max.h"

int miniMax(char *board[], char player) {
    // Guard clauses
    if (game_state(board) != ONGOING) {
        return (player == COMPUTER ? MIN : MAX);
    }
    if (game_state(board) == TIE) {
        return MAX + MIN;
    }

    // MINIMIZING PLAYER
    if (player == HUMAN) {
        int evaluation = MAX;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLUMNS; j++) {
                if (board[i][j] == EMPTY_SPACE) {
                    board[i][j] = player;
                    int position_evaluation = miniMax(board, switch_player(player));
                    if (position_evaluation < evaluation) {
                        evaluation = position_evaluation;
                    }
                    board[i][j] = EMPTY_SPACE;
                }
            }
        }
        return evaluation;
    }

    // MAXIMIZING PLAYER
    if (player == COMPUTER) {
        int evaluation = MIN;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLUMNS; j++) {
                if (board[i][j] == EMPTY_SPACE) {
                    board[i][j] = player;
                    int position_evaluation = miniMax(board, switch_player(player));
                    if (position_evaluation > evaluation) {
                        evaluation = position_evaluation;
                    }
                    board[i][j] = EMPTY_SPACE;
                }
            }
        }
        return evaluation;
    }
    exit(EXIT_FAILURE);
}

void best_move(char *board[], char player, int *move) {
    // Maximizing player is computer
    int evaluation = MIN;
    int best_move[2] = {-1, -1};
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (board[i][j] == EMPTY_SPACE) {
                board[i][j] = player;
                int position_evaluation = miniMax(board, switch_player(player));
                if (position_evaluation > evaluation) {
                    evaluation = position_evaluation;
                    best_move[0] = i;
                    best_move[1] = j;
                }
                board[i][j] = EMPTY_SPACE;
            }
        }
    }
    move[0] = best_move[0];
    move[1] = best_move[1];
}