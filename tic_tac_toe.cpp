#include <iostream>
using namespace std;
const int SIZE = 3;

void printBoard(const char board[SIZE][SIZE]) {
    std::cout << "\n";
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            std::cout << board[i][j];
            if (j < SIZE - 1) std::cout << " | ";
        }
        std::cout << "\n";
        if (i < SIZE - 1) std::cout << "--|---|--\n";
    }
    std::cout << "\n";
}

bool makeMove(char board[SIZE][SIZE], int row, int col, char player) {
    if (board[row][col] == ' ') {
        board[row][col] = player;
        return true;
    }
    return false;
}

int main() {
    char board[SIZE][SIZE] = { {' ', ' ', ' '},
                               {' ', ' ', ' '},
                               {' ', ' ', ' '} };

    char currentPlayer = 'X';
    int row, col;

    std::cout << "Tic-Tac-Toe Game\n";
    printBoard(board);

    while (true) {
        std::cout << "Player " << currentPlayer << ", enter your move (row and column, 1-3 each): ";
        std::cin >> row >> col;

        // Convert to 0-based index
        row--;
        col--;

        if (row >= 0 && row < SIZE && col >= 0 && col < SIZE) {
            if (makeMove(board, row, col, currentPlayer)) {
                printBoard(board);

                // Check for win or draw here if needed...

                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X'; // Switch player
            } else {
                std::cout << "This position is already taken. Try again.\n";
            }
        } else {
            std::cout << "Invalid move. Enter a row and column between 1 and 3.\n";
        }
    }

    return 0;
}