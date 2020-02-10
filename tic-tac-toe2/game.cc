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

void Game::draw_divider(int length) {
    std::cout << "   ";
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < length; j++) {
            std::cout << "-";
        }

        std::cout << " ";
    }
    std::cout << "\n";
}

int* Game::decode_move(std::string move) {
    int* pos = new int[2];

    // Assume move string is lowercase already
    pos[0] = (int)move[0] - 97;         // row
    pos[1] = std::stoi(move.substr(1)) - 1; // column

    std::cout << pos[0] << " x " << pos[1] << "\n";
    return pos;
}

Game::Game() {}

Game::Game(int rows, int cols) {
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
    for (int i = 0; i < 5; i++) {
        wins[i] = 0;
        losses[i] = 0;
        draws[i] = 0;
    }
}

Game::~Game() {
    for (int i = 0; i < rows; i++) {
        delete [] board[i];
    }
    delete [] board;
}

bool Game::check_rows(int player, int row, int col) {
    if (board[row][col-1] == player && board[row][col-2] == player)
        return true;

    if (board[row][col+1] == player && board[row][col+2] == player)
        return true;

    if (board[row][col-1] == player && board[row][col+1] == player)
        return true;

    return false;
}

bool Game::check_cols(int player, int row, int col) {
    // This function requires verification of row and col

    if ((row-1) >= 0 && (row-2) >= 0 &&
        board[row-1][col] == player && board[row-2][col] == player)
        return true;

    if ((row+1) < rows && (row+2 < rows) &&
        board[row+1][col] == player && board[row+2][col] == player)
        return true;

    if ((row-1) >= 0 && (row+1) < rows &&
        board[row-1][col] == player && board[row+1][col] == player)
        return true;

    return false;
}

bool Game::check_diagonals(int player, int row, int col) {
    if ((row-1) >= 0 && (row+1) < rows &&
        board[row-1][col-1] == player && board[row+1][col+1] == player)
        return true;

    if ((row-1) >= 0 && (row+1) < rows &&
        board[row-1][col+1] == player && board[row+1][col-1] == player)
        return true;

    if ((row-1) >= 0 && (row-2) >= 0 &&
        board[row-1][col-1] == player && board[row-2][col-2] == player)
        return true;

    if ((row+1) < rows && (row+2) < rows &&
        board[row+1][col+1] == player && board[row+2][col+2] == player)
        return true;

    return false;
}

bool Game::check_draw() {
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            if (board[row][col] == -1)
                return false;
        }
    }

    return true;
}

bool Game::check_wins(int player, int row, int col) {
    if (check_rows(player, row, col) ||
        check_cols(player, row, col) ||
        check_diagonals(player, row, col))
        return true;

    return false;
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

void Game::add_player(int num, std::string name) {
    players[num] = name;
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
    if (move.empty())
        return 1;

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
        if (check_wins(player, row, col))
            return 3;
        else if (check_draw())
            return 4;

        return 0; // Valid
    }

    return 2; // Invalid: spot taken
}

void Game::draw_scores(int total) {
    std::cout << std::setw(60) << std::right
              << " ------ ------ ------\n"
              << std::setw(61) << std::right
              << "|  WIN | LOSS | DRAW |\n";

    for (int i = 0; i < total; i++) {
        std::cout << std::setw(60) << std::right
                  << " ------ ------ ------\n";

        std::cout << std::setw(30) << std::right
                  << get_name(i, true) << " ";

        std::cout << std::setw(10) << std::right
                  << "|  " << wins[i] << "  ";

        std::cout << std::setw(4) << std::right
                  << "|  " << losses[i] << "  ";

        std::cout << std::setw(4) << std::right
                  << "|  " << draws[i] << "   |\n";
    }

    std::cout << std::setw(60) << std::right
              << " ------ ------ ------\n";
}

void Game::add_win(int player) {
    wins[player]++;
}

void Game::add_loss(int player) {
    losses[player]++;
}

void Game::add_draw(int player) {
    draws[player]++;
}
