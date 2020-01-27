#include <iostream>
#include "player.h"
#include "game.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {
  Game* game = new Game(3, 3);

  // Gather player data
  string name1, name2;
  cout << "Enter player 1's name: ";
  getline(cin, name1);
  cout << "Enter player 2's name: ";
  getline(cin, name2);
  
  // players select their turn order.
  while (true) {
    string input;
    cout << "Which player would like to be X? ";
    getline(cin, input);

    if (input == name1) {
      game->init(name1, name2);
      cout << name1 << " is X, " << name2 << " is O" << endl;
      break;
    }
    else if (input == name2) {
      game->init(name2, name1);
      cout << name2 << " is X, " << name1 << " is O" << endl;
      break;
    }
    else {
      cout << "Please enter a valid player name." << endl;
    }
  }

  // The main loop.
  // Every pass the Game object checks win conditions on the board.
  while (true) {
    int winner;
    winner = game->check_wins();
    
    if (winner == 0) {
      // Play game normally here.
      cout << "\n" << game->get_board();
      game->turn();
    }
    else if (winner == 1) {
      cout << game->get_board(1) << endl;
      cout << "Player 1 wins!" << endl;
      game->p1.add_win();
      game->p2.add_loss();
    }
    else if (winner == 2) {
      cout << game->get_board(2) << endl;
      cout << "Player 2 wins!" << endl;
      game->p2.add_win();
      game->p1.add_loss();
    }
    else if (winner == 3) {
      cout << game->get_board() << endl;
      cout << "It's a draw!" << endl;
      game->p1.add_draw();
      game->p2.add_draw();
    }

    // Put all common code shared between win scenarios here.
    if (winner != 0) {
      string quit;
      cout << game->get_record();

      cout << "Type q to quit> ";
      cin >> quit;
      if (quit == "q")
        break;

      cout << "\n========" << "\nNew Game" << "\n========" << endl;

      game->init();
      game->reset_board();
    }
  }

  cout << "\nFinal scores\n" << game->get_record() << endl;

  delete game;

  return 0;
}
