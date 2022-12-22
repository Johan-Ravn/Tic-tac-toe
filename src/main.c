// Main document
#include "game.h"
#include "mini-max.h"

void initialize_board(char *board[]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            board[i][j] = EMPTY_SPACE;
        }
    }
}

int main(void) {
    // Allocating memory for the board with malloc, and initializing board
    char **board = malloc(ROWS * sizeof(char *));
    for (int i = 0; i < COLUMNS; i++) {
        board[i] = malloc(COLUMNS * sizeof(char*));
    }
    initialize_board(board);

    // Init variables
    char player = HUMAN;
    char *winner = malloc(10 * sizeof(char));

    while (true) {
        print_board(board);
        // Variables
        int result = game_state(board);

        // Checks if game is done
        if (result != ONGOING) {
            // If results is a tie, player is set to empty
            if (result == TIE)
                strcpy(winner, "tie");

            // If results is winner, player is set to the opposite of the current player
            if (result == WINNER) {
                player = switch_player(player);
                winner[0] = player;
            }
            break;
        }

        // Make move
        if (player == COMPUTER) {
            int move_arr[2];
            best_move(board, player, move_arr);
            board[move_arr[0]][move_arr[1]] = player;
            switch_player(player);
            continue;
        }
        move(board, player);

        // Switch player
        player = switch_player(player);
    }

    if (strcmp(winner, "tie") == 0) {
        printf("It was a tie \n");
    }
    printf("The winner is player %s", winner);

    free(board);
    free(winner);
    return 0;
}