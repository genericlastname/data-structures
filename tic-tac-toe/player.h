// Defines the Player class to store info about names, wins, losses, etc.

#ifndef __player_h__
#define __player_h__

#include <string>
#include <sstream>

class Player {
  int wins, losses, draws;
  std::string name;

public:
  Player();
  int get_wins() const;
  int get_losses() const;
  int get_draws() const;
  void add_win();
  void add_loss();
  void add_draw();
  std::string get_name(bool full = false) const;
  void set_name(std::string n);
};

#endif
