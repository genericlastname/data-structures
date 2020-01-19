#include "game.h"

Game::Game() {  }

Game::Game(int c, int r) {
  cols = c;
  rows = r;
  board = new int*[cols];
  for (int i = 0; i < cols; i++) {
    board[i] = new int[rows];
  }
}

Game::~Game() {
  for (int i = 0; i < cols; i++) {
    delete [] board[i];
  }
  delete [] board;
}

void Game::init(std::string p1_name, std::string p2_name) {
  p1.set_name(p1_name);
  p2.set_name(p2_name);
}

std::string Game::get_record() {
  std::stringstream out;
  out << p1.get_name() << ": ";
  out << p1.get_wins() << " wins, ";
  out << p1.get_losses() << " losses, ";
  out << p1.get_draws() << " draws" << std::endl;

  out << p2.get_name() << ": ";
  out << p2.get_wins() << " wins, ";
  out << p2.get_losses() << " losses, ";
  out << p2.get_draws() << " draws" << std::endl;

  return out.str();
}
