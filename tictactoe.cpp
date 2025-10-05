#include <iostream>
#include <string>

using namespace std;


void clearInputBuffer() {
    cin.clear();
    cin.ignore(1000, '\n');
}


class Player {
private:
    string name;
    char symbol;

public:
    Player(string n, char s) {
        name = n;
        symbol = s;
    }

    string getName() const {
        return name;
    }

    char getSymbol() const {
        return symbol;
    }
};


class GameBoard {
private:
    char board[3][3];

public:
    GameBoard() {
        resetBoard();
    }

    void resetBoard() {
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                board[i][j] = ' ';
    }

    void printBoard() const {
        cout << "\n";
        cout << "     0   1   2\n";
        cout << "   -------------\n";
        for (int i = 0; i < 3; ++i) {
            cout << " " << i << " | ";
            for (int j = 0; j < 3; ++j) {
                cout << board[i][j];
                if (j < 2) cout << " | ";
            }
            cout << " |\n";
            cout << "   -------------\n";
        }
        cout << "\n";
    }

    void placeSymbol(int row, int col, char symbol) {
        if (row < 0 || row > 2 || col < 0 || col > 2)
            throw invalid_argument("Position out of range");
        if (board[row][col] != ' ')
            throw invalid_argument("Cell already occupied");
        board[row][col] = symbol;
    }

    bool isWin(char symbol) const {
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol)
                return true;
            if (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol)
                return true;
        }

        if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol)
            return true;
        if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol)
            return true;

        return false;
    }

    bool isDraw() const {
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                if (board[i][j] == ' ')
                    return false;
        return true;
    }
};


class Game {
private:
    Player player1;
    Player player2;
    GameBoard board;

    int player1Wins = 0;
    int player2Wins = 0;
    int draws = 0;

public:
    Game()
        : player1("Player 1", 'X'), player2("Player 2", 'O') {}

    void start() {
        bool keepPlaying = true;

        while (keepPlaying) {
            board.resetBoard();
            board.printBoard();

            Player* current = &player1;
            Player* other = &player2;

            bool gameOver = false;
            while (!gameOver) {
                makeMove(*current);
                board.printBoard();

                if (board.isWin(current->getSymbol())) {
                    cout << current->getName() << " wins the game! Congratulations!\n";
                    if (current == &player1)
                        player1Wins++;
                    else
                        player2Wins++;
                    gameOver = true;
                } else if (board.isDraw()) {
                    cout << "The game is a draw!\n";
                    draws++;
                    gameOver = true;
                } else {
                    swap(current, other);
                }
            }

            cout << "\nCurrent record:\n";
            cout << "Player 1 wins: " << player1Wins << "\n";
            cout << "Player 2 wins: " << player2Wins << "\n";
            cout << "Draws: " << draws << "\n";

            char response;
            do {
                cout << "Would you like to play again? (y/n): ";
                cin >> response;
                response = tolower(response);
                clearInputBuffer();
            } while (response != 'y' && response != 'n');

            if (response == 'n') {
                keepPlaying = false;
                cout << "Thanks for playing! Goodbye!\n";
            }
        }
    }

    void makeMove(Player& player) {
        int row, col;
        bool validInput = false;

        do {
            try {
                cout << player.getName() << " (" << player.getSymbol() << ") - Enter your move (row and column): ";
                if (!(cin >> row >> col)) {
                    throw invalid_argument("Invalid input: please enter numbers.");
                }
                board.placeSymbol(row, col, player.getSymbol());
                validInput = true;
            } catch (const invalid_argument& e) {
                cout << "Error: " << e.what() << " Try again.\n";
                clearInputBuffer();
            }
        } while (!validInput);
    }
};


int main() {
    Game game;
    game.start();
    return 0;
}
