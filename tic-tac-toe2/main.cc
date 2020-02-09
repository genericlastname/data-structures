#include "game.h"

int main() {
    // Get the size of the game board.
    int rows, cols;

    do {
        std::cout << "\n";
        std::cout << "Enter the dimensions of the board.\n";
        std::cout << "The board should be no smaller than 3x3 and no larger than 11x16\n\n";
        std::cout << "Enter the number of rows    -> ";
        std::cin >> rows;
        std::cout << "Enter the number of columns -> ";
        std::cin >> cols;
    }
    while ((rows < 3 || cols < 3) || (rows > 11 || cols > 16));
    std::cout << "\n";
    
    // Get player names

    Game game(rows, cols, 4);

    game.add_player("Kyle");
    game.add_player("Chung Ng");
    game.add_player("Reggie");

    std::cout << game.get_name(1, false) << "\n"
              << game.get_name(1, true) << "\n";

    // Input players
    // std::cout << "Enter done to finish adding players.\n";

    // bool cont;
    // int num = 1;
    // do {
    //     std::string name;
    //     if (num >= 5)
    //         cont = false;

    //     std::cout << "Enter player " << num << "'s name: -> ";
    //     std::getline(std::cin, name);

    //     if (name == "done") {
    //         cont = false;
    //     }
    //     else {
    //         game.add_player(name);
    //         cont = true;
    //         num++;
    //     }
    // }
    // while (cont);

    game.draw_board();

    return 0;
}
