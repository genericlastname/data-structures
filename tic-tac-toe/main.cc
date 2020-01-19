#include <iostream>
#include "player.h"
#include "game.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {
  Game* game = new Game;

  string p1, p2;
  cout << "Enter Player 1's name: ";
  cin >> p1;
  cout << "Enter Player 2's name: ";
  cin >> p2;
  game->init(p1, p2);
  cout << game->get_record();

  return 0;
}
