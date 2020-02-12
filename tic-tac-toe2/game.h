#ifndef __game_h__
#define __game_h__

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cctype>
#include <string>

class Game {
    std::string players[5];
    int wins[5], losses[5], draws[5];

    int cols, rows;
    int** board;

    void draw_col_labels();
    void draw_divider(int length = 3);
    int* decode_move(std::string move);
    bool check_rows(int player, int row, int col);
    bool check_cols(int player, int row, int col);
    bool check_diagonals(int player, int row, int col);
    bool check_draw();

public:
    Game();
    Game(int rows, int cols);
    ~Game();
    bool check_wins(int player, int row, int col);
    void draw_board();
    void reset_board();
    void add_player(int num, std::string name);
    std::string get_name(int player, bool full);
    int make_move(int player, std::string move);
    void draw_scores(int total);
    void add_win(int player);
    void add_loss(int player);
    void add_draw(int player);
};

bool validate_board_size_input(std::string input);

#endif
