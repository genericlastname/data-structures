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

void Game::init() {
  if (current == "p1")
    current = "p2";
  else
    current = "p1";
}

void Game::init(std::string p1_name, std::string p2_name) {
  p1.set_name(p1_name);
  p2.set_name(p2_name);
  current = "p2";
}

void Game::reset_board() {
  for (int x = 0; x < cols; x++) {
    for (int y = 0; y < rows; y++) {
      board[x][y] = 0;
    }
  }
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

std::string Game::get_board(int post_game) {
  std::stringstream out;

  for (int y = 0; y < rows; y++) {
    out << "+---+---+---+\n";
    for (int x = 0; x < cols; x++) {
      out << "| ";

      if (board[x][y] == 0)
        out << (1+x+(3*y));
      else if (board[x][y] == 1)
        if (post_game == 2)
          out << "X";
        else
          out << "x";

      else if (board[x][y] == 2)
        if (post_game == 1)
          out << "O";
        else
          out << "o";

      out << " ";
    }
    out << "|\n";
  }
  out << "+---+---+---+\n";

  return out.str();
}

int Game::make_move(int space) {
  int x, y;

  if (space < 1 || space > 9)
    return 1;

  switch(space) {
    case 1: x = 0; y = 0; break;
    case 2: x = 1; y = 0; break;
    case 3: x = 2; y = 0; break;
    case 4: x = 0; y = 1; break;
    case 5: x = 1; y = 1; break;
    case 6: x = 2; y = 1; break;
    case 7: x = 0; y = 2; break;
    case 8: x = 1; y = 2; break;
    case 9: x = 2; y = 2; break;
  }

  if (board[x][y] != 0)
    return 2;

  if (current == "p1")
    board[x][y] = 1;
  else if (current == "p2")
    board[x][y] = 2;

  return 0;
}

void Game::turn() {
  int outcome = -1;
  int space;
  
  while (outcome != 0) {
    if (current == "p1")
      std::cout << p1.get_name();
    else
      std::cout << p2.get_name();
    std::cout << " > ";
    std::cin >> space;
    outcome = this->make_move(space);

    if (outcome == 1)
      std::cout << "Please enter a number between 1 and 9.\n";
    else if (outcome == 2)
      std::cout << "That space is already taken\n";
  }
  if (current == "p1")
    current = "p2";
  else
    current = "p1";
}

int Game::check_wins() {
  // --- Check Player 1 first. ---
  /// Check horizontals.
  for (int y = 0; y < rows; y++) {
    if (board[0][y] == 1 && board[1][y] == 1 && board[2][y] == 1)
      return 1;
  }
  /// Check verticals
  for (int x = 0; x < cols; x++) {
    if (board[x][0] == 1 && board[x][1] == 1 && board[x][2] == 1)
      return 1;
  }
  /// Check diagonals
  if (board[0][0] == 1 && board[1][1] == 1 && board[2][2] == 1)
    return 1;
  if (board[2][0] == 1 && board[1][1] == 1 && board[0][2] == 1)
    return 1;

  // --- Check Player 2 now. ---
  /// Check horizontals.
  for (int y = 0; y < rows; y++) {
    if (board[0][y] == 2 && board[1][y] == 2 && board[2][y] == 2)
      return 2;
  }
  /// Check verticals
  for (int x = 0; x < cols; x++) {
    if (board[x][0] == 2 && board[x][1] == 2 && board[x][2] == 2)
      return 2;
  }
  /// Check diagonals
  if (board[0][0] == 2 && board[1][1] == 2 && board[2][2] == 2)
    return 1;
  if (board[2][0] == 2 && board[1][1] == 2 && board[0][2] == 2)
    return 2;

  // --- Check for ties ---
  int full_board = 0;
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (board[x][y] != 0)
        full_board++;
    }
  }
  if (full_board == 9)
    return 3;

  // No wins found
  return 0;
}
