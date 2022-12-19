// Main document

#include "main.h"

int main(void) {
    // Allocating memory for the board with malloc
    char **board = malloc(ROWS * sizeof(char *));
    for (int i = 0; i < COLUMNS; i++) {
        board[i] = malloc(COLUMNS * sizeof(char*));
    }



    free(board);
}