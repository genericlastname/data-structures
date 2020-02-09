#ifndef __game_h__
#define __game_h__

#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>

class Game {
    std::string players[5];
    int scores[5];

    int cols, rows;
    int** board;

    void draw_col_labels();
    void draw_divider();
    int* decode_move(std::string move);
    void check_rows(int player, int row, int col);
    void check_cols(int player, int row, int col);
    void check_diagonals(int player, int row, int col);

public:
    Game();
    Game(int rows, int cols, int num_of_players);
    ~Game();
    int check_wins(int player, int row, int col);
    void draw_board();
    int add_player(std::string name);
    std::string get_name(int player, bool full);
    int make_move(int player, std::string move);
};

#endif
