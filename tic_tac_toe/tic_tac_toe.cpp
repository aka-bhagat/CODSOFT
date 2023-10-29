#include <iostream>
#include <vector>

// Function to display the Tic-Tac-Toe board
void displayBoard(const std::vector<std::vector<char>>& board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << board[i][j];
            if (j < 2)
                std::cout << " | ";
        }
        std::cout << std::endl;
        if (i < 2)
            std::cout << "---------" << std::endl;
    }
    std::cout << std::endl;
}

// Function to check if a player has won
bool checkWin(const std::vector<std::vector<char>>& board, char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) // Check rows
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) // Check columns
            return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) // Check diagonal (top-left to bottom-right)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) // Check diagonal (top-right to bottom-left)
        return true;
    return false;
}

// Function to check if the game is a draw
bool checkDraw(const std::vector<std::vector<char>>& board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
        }
    }
    return true;
}

int main() {
    std::vector<std::vector<char>> board(3, std::vector<char>(3, ' '));
    char currentPlayer = 'X';

    std::cout << "Welcome to Tic-Tac-Toe!" << std::endl;

    do {
        displayBoard(board);
        std::cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        int row, col;
        std::cin >> row >> col;

        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
            std::cout << "Invalid move. Try again." << std::endl;
        } else {
            board[row - 1][col - 1] = currentPlayer;
            if (checkWin(board, currentPlayer)) {
                displayBoard(board);
                std::cout << "Player " << currentPlayer << " wins! Congratulations!" << std::endl;
                break;
            } else if (checkDraw(board)) {
                displayBoard(board);
                std::cout << "It's a draw! Good game." << std::endl;
                break;
            }
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X'; // Switch players
        }
    } while (true);

    std::cout << "Do you want to play again? (Y/N): ";
    char playAgain;
    std::cin >> playAgain;

    if (playAgain == 'Y' || playAgain == 'y') {
        main(); // Restart the game
    } else {
        std::cout << "Thanks for playing Tic-Tac-Toe!" << std::endl;
    }

    return 0;
}
