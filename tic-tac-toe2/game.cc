#include "game.h"

void Game::draw_col_labels() {
    std::cout << "    ";
    for (int i = 1; i <= cols; i++) {
        std::cout << i;
        // Accout for two char column nums
        if (i < 10)
            std::cout << "   ";
        else
            std::cout << "  ";
    }
    std::cout << "\n";
}

void Game::draw_divider() {
    std::cout << "   ";
    for (int i = 0; i < cols; i++) {
        std::cout << "--- ";
    }
    std::cout << "\n";
}

int* Game::decode_move(std::string move) {
    int* pos = new int[2];

    // Assume move string is lowercase already
    pos[0] = (int)move[0] - 97; // row
    pos[1] = move[1];      // column

    return pos;
}

Game::Game() {}

Game::Game(int rows, int cols, int num_of_players) {
    this->rows = rows;
    this->cols = cols;
    
    // initialize board
    board = new int*[rows];
    for (int i = 0; i < rows; i++) {
        board[i] = new int[cols];

        for (int j = 0; j < cols; j++) {
            board[i][j] = -1;
        }
    }

    // initialize players and scores
    for (int i = 0; i < num_of_players; i++) {
        scores[i] = 0;
    }
}

Game::~Game() {
    for (int i = 0; i < rows; i++) {
        delete [] board[i];
    }
    delete [] board;
}

int Game::check_wins(int player, int row, int col) {
}

void Game::draw_board() {
    char alpha[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K' };

    draw_col_labels();

    /// Draw rows
    for (int row = 0; row < rows; row++) {
        draw_divider();

        std::cout << alpha[row] << " ";
        for (int col = 0; col < cols; col++) {
            std::cout << "| ";
            switch (board[row][col]) {
                case 0:
                    std::cout << "a";
                    break;
                case 1:
                    std::cout << "b";
                    break;
                case 2:
                    std::cout << "c";
                    break;
                case 3:
                    std::cout << "d";
                    break;
                case 4:
                    std::cout << "e";
                    break;
                default:
                    std::cout << " ";
            }
            std::cout << " ";
        }
        std::cout << "| ";

        std::cout << alpha[row] << "\n";
    }

    draw_divider();
    draw_col_labels();
}

int Game::add_player(std::string name) {
    if (name.empty() || name == "\n")
        return 2; // Empty string, done inputting players

    for (int i = 0; i < 5; i++) {
        if (players[i].empty()) {
            players[i] = name;
            return 0;
        } 
    }

    return 1; // No more player slots
}

std::string Game::get_name(int player, bool full) {
    if (full)
        return players[player];

    std::string first_name;
    for (int i = 0; i < players[player].length(); i++) {
        if (players[player][i] == ' ')
            return first_name;
        else
            first_name += players[player][i];
    }

    return players[player];
}

int Game::make_move(int player, std::string move) {
    // Convert move to lowercase
    std::transform(move.begin(), move.end(), move.begin(),
        [](unsigned char c){ return std::tolower(c); });

    int* pos = decode_move(move);
    int row = pos[0];
    int col = pos[1];

    if ((row < 0 || col < 0) || (row >= rows || col >= cols)) {
        return 1; // Invalid: out of range
    }
    else if (board[row][col] == -1) {
        board[row][col] = player;
        return 0; // Valid
    }

    return 2; // Invalid: spot taken
}
