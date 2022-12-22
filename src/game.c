#include "game.h"

void print_board(char *board[]) {
    printf("__________\n");
    for (int i = 0; i < ROWS; i++) {
        printf("%c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        printf("__________\n");
    }
}

int game_state(char *board[]) {
    // Tie
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (board[i][j] == EMPTY_SPACE) {
                break;
            }
            if (i == ROWS - 1 && j == COLUMNS - 1) {
                return TIE;
            }
        }
    }

    // Winner, straight line
    for (int i = 0; i < ROWS; i++) {
        // ROW
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != EMPTY_SPACE)
            return WINNER;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != EMPTY_SPACE)
            return WINNER;
    }
    // Winner, diagonally
    if (board[1][1] != EMPTY_SPACE) {
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
            return WINNER;
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
            return WINNER;
    }
    // Game is still ongoing
    return ONGOING;
}

void move(char *board[], char player) {
    printf("What move would you like to make: \n");
    int move[2] = {-1, -1};

    // Get move from user, and validate their input
    while (true) {
        scanf("%d %d", &move[0], &move[1]);
        --move[0];
        --move[1];
        if (move[0] >= 0 && move[0] < COLUMNS && move[1] >= 0 && move[1] < ROWS &&
            board[move[0]][move[1]] == EMPTY_SPACE) {
            fflush(stdin);
            break;
        }
    }
    // Make move
    printf("Row: %d, Column: %d\n", move[0] + 1, move[1] + 1);
    board[move[0]][move[1]] = player;
}

char switch_player(char player) {
    if (player == 'X')
        return 'O';
    return 'X';
}