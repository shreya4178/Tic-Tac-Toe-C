#include <stdio.h>

// Function to display the board
void displayBoard(char board[]) {
    printf("\n");
    printf(" %c | %c | %c \n", board[0], board[1], board[2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[3], board[4], board[5]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[6], board[7], board[8]);
}

// Function to check if someone has won
int checkWinner(char board[]) {

    // Rows
    if (board[0] == board[1] && board[1] == board[2])
        return 1;

    if (board[3] == board[4] && board[4] == board[5])
        return 1;

    if (board[6] == board[7] && board[7] == board[8])
        return 1;

    // Columns
    if (board[0] == board[3] && board[3] == board[6])
        return 1;

    if (board[1] == board[4] && board[4] == board[7])
        return 1;

    if (board[2] == board[5] && board[5] == board[8])
        return 1;

    // Diagonals
    if (board[0] == board[4] && board[4] == board[8])
        return 1;

    if (board[2] == board[4] && board[4] == board[6])
        return 1;

    return 0;
}

int main() {

    char board[9] = {'1','2','3','4','5','6','7','8','9'};
    int position;
    int gameOver = 0;

    printf("=================================\n");
    printf("       TIC-TAC-TOE GAME\n");
    printf("=================================\n");

    for (int turn = 0; turn < 9; turn++) {

        displayBoard(board);

        // Player 1
        if (turn % 2 == 0) {

            printf("\nPlayer 1 (X), choose a position (1-9): ");
            scanf("%d", &position);

            if (position < 1 || position > 9) {
                printf("Invalid position! Choose between 1 and 9.\n");
                turn--;
                continue;
            }

            if (board[position - 1] == 'X' ||
                board[position - 1] == 'O') {

                printf("Position already taken! Choose another position.\n");
                turn--;
                continue;
            }

            board[position - 1] = 'X';
        }

        // Player 2
        else {

            printf("\nPlayer 2 (O), choose a position (1-9): ");
            scanf("%d", &position);

            if (position < 1 || position > 9) {
                printf("Invalid position! Choose between 1 and 9.\n");
                turn--;
                continue;
            }

            if (board[position - 1] == 'X' ||
                board[position - 1] == 'O') {

                printf("Position already taken! Choose another position.\n");
                turn--;
                continue;
            }

            board[position - 1] = 'O';
        }

        // Check for winner
        if (checkWinner(board)) {

            displayBoard(board);

            if (turn % 2 == 0)
                printf("\nPlayer 1 (X) wins! Congratulations!\n");
            else
                printf("\nPlayer 2 (O) wins! Congratulations!\n");

            gameOver = 1;
            break;
        }
    }

    // Check for draw
    if (gameOver == 0) {
        displayBoard(board);
        printf("\nIt's a draw!\n");
    }

    printf("\nThanks for playing!\n");

    return 0;
}