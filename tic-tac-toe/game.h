// Defines the Game class for managing board state.

#ifndef __game_h__
#define __game_h__

#include "player.h"

class Game {
  Player p1, p2;
  int cols, rows;
  int** board;
  bool current; // false for p1, true for p2

public:
  Game();
  Game(int cols, int rows);
  ~Game();
  void init(std::string p1_name, std::string p2_name);
  std::string get_board();
  std::string get_record();
};

#endif
