// Defines the Game class for managing board state.

#ifndef __game_h__
#define __game_h__

#include <iostream>
#include "player.h"

class Game {
  int cols, rows;
  int** board;

  int make_move(int space);

public:
  Player p1, p2;
  std::string current;

  Game();
  Game(int cols, int rows);
  ~Game();
  void init();
  void init(std::string p1_name, std::string p2_name);
  void reset_board();
  std::string get_board(int post_game = 0);
  std::string get_record();
  void turn();
  int check_wins();
};

#endif
