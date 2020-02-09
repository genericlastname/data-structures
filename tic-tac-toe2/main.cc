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
    // std::cout << std::endl;
    
    Game game(rows, cols);

    // Get player names
    std::cout << "\nEnter done when you are finished entering names.\n";

    std::cin.ignore();

    std::string name;
    int total = 1;
    while (name != "done" && total <= 5) {
        std::cout << "Enter player " << total << "'s name -> ";
        std::getline(std::cin, name);

        if (name != "done") {
            game.add_player(total-1, name);
            total++;
            std::cout << game.get_name(total-1, true) << "\n";
        }
    }
    total--;

    // Main game loop
    std::string input;
    bool running = true;
    int current = 0;
    int games_played = 1;

    std::cin.ignore();

    while (running) {
        game.draw_board();

        
        std::cout << game.get_name(current, false) << "'s turn -> ";
        std::getline(std::cin, input);

        switch (game.make_move(current, input)) {
            case 1: // out of range
                std::cout << "Please enter a value within range.\n\n";
                break;
            case 2: // spot taken
                std::cout << "That spot is already taken\n\n";
                break;
            case 3:
                std::cout << game.get_name(current, true) << " wins\n";
            default:
                current++;
        }

        // Roll over current
        if (current == total)
            current = 0;
    }

    return 0;
}
