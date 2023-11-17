#include <iostream>
#include <vector>

using namespace std;

// Function prototypes
void displayBoard(const vector<vector<char>> &board);
bool isMoveValid(const vector<vector<char>> &board, int row, int col);
bool checkForWin(const vector<vector<char>> &board, char player);
bool checkForDraw(const vector<vector<char>> &board);
void switchPlayer(char &currentPlayer);
bool playAgain();

int main() {
    const int boardSize = 3;
    vector<vector<char>> board(boardSize, vector<char>(boardSize, ' '));
    char currentPlayer = 'X';

    do {
        displayBoard(board);

        int row, col;
        do {
            cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            cin >> row >> col;
        } while (!isMoveValid(board, row, col));

        board[row][col] = currentPlayer;

        if (checkForWin(board, currentPlayer)) {
            displayBoard(board);
            cout << "Player " << currentPlayer << " wins!" << endl;
        } else if (checkForDraw(board)) {
            displayBoard(board);
            cout << "It's a draw!" << endl;
        } else {
            switchPlayer(currentPlayer);
        }

    } while (playAgain());

    return 0;
}

void displayBoard(const vector<vector<char>> &board) {
    cout << "  0 1 2" << endl;
    for (int i = 0; i < board.size(); ++i) {
        cout << i << " ";
        for (int j = 0; j < board[i].size(); ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool isMoveValid(const vector<vector<char>> &board, int row, int col) {
    return (row >= 0 && row < board.size() && col >= 0 && col < board[row].size() && board[row][col] == ' ');
}

bool checkForWin(const vector<vector<char>> &board, char player) {
    for (int i = 0; i < board.size(); ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }

    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

bool checkForDraw(const vector<vector<char>> &board) {
    for (const auto &row : board) {
        for (char cell : row) {
            if (cell == ' ') {
                return false;
            }
        }
    }
    return true;
}

void switchPlayer(char &currentPlayer) {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

bool playAgain() {
    char choice;
    cout << "Do you want to play again? (y/n): ";
    cin >> choice;
    return (choice == 'y' || choice == 'Y');
}
