#include "game.h"

// Draw the A, B, C, ... column labels for the board.
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

// Draws the horizontal divider lines for the board.
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

// Translates alphanumeric move input (e.g. a2 or B5) into a 2D int position array.
int* Game::decode_move(std::string move) {
    int* pos = new int[2];

    // Assume move string is lowercase already
    pos[0] = (int)move[0] - 97;         // row
    pos[1] = std::stoi(move.substr(1)) - 1; // column

    return pos;
}

Game::Game() {}

// Initialize the Game, including board size, player names, and scores.
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

// Takes in the player number, row, and col of the last move and checks for horizontal wins.
bool Game::check_rows(int player, int row, int col) {
    if ((col-1) >= 0 && (col-2) >= 0 &&
        board[row][col-1] == player && board[row][col-2] == player)
        return true;

    if ((col+1) >= 0 && (col+2) >= 0 &&
        board[row][col+1] == player && board[row][col+2] == player)
        return true;

    if ((col-1) >= 0 && (col+1) >= 0 &&
        board[row][col-1] == player && board[row][col+1] == player)
        return true;

    return false;
}

// Takes in the player number, row, and col of the last move and checks for vertical wins.
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

// Takes in the player number, row, and col of the last move and checks for diagonal wins.
bool Game::check_diagonals(int player, int row, int col) {
    if ((row-1) >= 0 && (row+1) < rows &&
        (col-1) >= 0 && (col+1) < cols &&
        board[row-1][col-1] == player && board[row+1][col+1] == player)
        return true;

    if ((row-1) >= 0 && (row+1) < rows &&
        (col-1) >= 0 && (col+1) < cols &&
        board[row-1][col+1] == player && board[row+1][col-1] == player)
        return true;

    if ((row-1) >= 0 && (row-2) >= 0 &&
        (col-1) >= 0 && (col-2) >= 0 &&
        board[row-1][col-1] == player && board[row-2][col-2] == player)
        return true;

    if ((row+1) < rows && (row+2) < rows &&
        (col+1) < cols && (col+2) < cols &&
        board[row+1][col+1] == player && board[row+2][col+2] == player)
        return true;

    if ((row+1) < rows && (col-1) >= 0 &&
        (row+2) < rows && (col-2) >= 0 &&
        board[row+1][col-1] == player && board[row+2][col-2] == player)
        return true;

    if ((row-1) >= 0 && (col+1) < cols &&
        (row-2) >= 0 && (col+2) < cols &&
        board[row-1][col+1] == player && board[row-2][col+2] == player)
        return true;

    return false;
}

// Loops through the whole board and checks for draw conditions.
bool Game::check_draw() {
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            if (board[row][col] == -1)
                return false;
        }
    }

    return true;
}

// Checks horizontal, vertical, and diagonal wins.
bool Game::check_wins(int player, int row, int col) {
    if (check_rows(player, row, col) ||
        check_cols(player, row, col) ||
        check_diagonals(player, row, col))
        return true;

    return false;
}

// Draws the board with labels and player moves.
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

// Clears the board.
void Game::reset_board() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            board[i][j] = -1;
        }
    }
}

// Set the specified player's name.
void Game::add_player(int num, std::string name) {
    players[num] = name;
}

// Take in player number and return full or first name.
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

// Take in a player and move string and update board accordingly.
int Game::make_move(int player, std::string move) {
    if (move.empty() || move.length() < 2)
        return 1;
    else if (!isdigit(move[1]))
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

// Take in number of players and draw a right aligned scoreboard.
void Game::draw_scores(int total) {
    std::cout << "\n"
              << std::setw(60) << std::right
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

// Takes in a player number and adds a win.
void Game::add_win(int player) {
    wins[player]++;
}

// Takes in a player number and adds a loss.
void Game::add_loss(int player) {
    losses[player]++;
}

// Takes in a player number and adds a draw.
void Game::add_draw(int player) {
    draws[player]++;
}

// Makes sure the board size input is only numbers
bool validate_board_size_input(std::string input) {
    for (int i = 0; i < input.length(); i++) {
        if (!isdigit(input[i]))
            return false;
    }

    return true;
}
