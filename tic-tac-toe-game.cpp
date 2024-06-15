#include <iostream>

char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
char player1_marker, player2_marker;
int current_player;

void drawBoard() {
    std::cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << std::endl;
    std::cout << "---|---|---" << std::endl;
    std::cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << std::endl;
    std::cout << "---|---|---" << std::endl;
    std::cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << std::endl;
}

bool placeMarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = (current_player == 1) ? player1_marker : player2_marker;
        return true;
    }
    return false;
}

int checkWin() {
    for (int i = 0; i < 3; i++) {
        // Check rows
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return current_player;
        // Check columns
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return current_player;
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return current_player;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return current_player;

    return 0;
}

void swapPlayer() {
    current_player = (current_player == 1) ? 2 : 1;
}

void game() {
    std::cout << "Player 1, choose your marker (X or O): ";
    std::cin >> player1_marker;
    while (player1_marker != 'X' && player1_marker != 'O') {
        std::cout << "Invalid marker. Choose either X or O: ";
        std::cin >> player1_marker;
    }

    player2_marker = (player1_marker == 'X') ? 'O' : 'X';

    std::cout << "Player 1 is " << player1_marker << " and Player 2 is " << player2_marker << "." << std::endl;

    current_player = 1;
    drawBoard();

    int player_won = 0;

    for (int i = 0; i < 9; i++) {
        std::cout << "Player " << current_player << "'s turn. Enter your slot: ";
        int slot;
        std::cin >> slot;

        if (slot < 1 || slot > 9) {
            std::cout << "That slot is invalid! Try another slot!" << std::endl;
            i--;
            continue;
        }

        if (!placeMarker(slot)) {
            std::cout << "That slot is occupied! Try another slot!" << std::endl;
            i--;
            continue;
        }

        drawBoard();

        player_won = checkWin();

        if (player_won != 0) {
            std::cout << "Player " << player_won << " wins!" << std::endl;
            break;
        }

        swapPlayer();
    }

    if (player_won == 0) {
        std::cout << "It's a tie!" << std::endl;
    }
}

int main() {
    game();
    return 0;
}
