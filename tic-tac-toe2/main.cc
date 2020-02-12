#include "game.h"

int main() {
    // Get the size of the game board.
    int rows, cols;
    std::string row_str, col_str;

    do {
        std::cout << "\n";
        std::cout << "Enter the dimensions of the board.\n";
        std::cout << "The board should be no smaller than 3x3 and no larger than 11x16\n\n";
        std::cout << "Enter the number of rows    -> ";
        std::cin >> row_str;
        std::cout << "Enter the number of columns -> ";
        std::cin >> col_str;

        // Check rows and cols
        if (validate_board_size_input(row_str) &&
            validate_board_size_input(col_str)) {
                rows = std::stoi(row_str);
                cols = std::stoi(col_str);
        }
        else {
            rows = 0;
            cols = 0;
            std::cout << "\nEnter numbers only.\n\n";
        }
    }
    while ((rows < 3 || cols < 3) || (rows > 11 || cols > 16));
    // std::cout << std::endl;
    
    Game game(rows, cols);

    // Get player names
    std::cout << "\nType done and enter twice when you are finished entering names.\n";

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
    int starter = current;
    int games_played = 0;

    std::cin.ignore();

    while (running) {
        game.draw_board();

        std::cout << "\n" << game.get_name(current, false) << "'s turn -> ";
        std::getline(std::cin, input);
        std::cout << "\n";

        switch (game.make_move(current, input)) {
            case 1: // out of range
                std::cout << "Please enter a value within range.\n\n";
                break;
            case 2: // spot taken
                std::cout << "That spot is already taken\n\n";
                break;
            case 3: // winner
                std::cout << "\n" << game.get_name(current, true) << " wins!\n\n";

                for (int i = 0; i < total; i++) {
                    if (i == current)
                        game.add_win(i);
                    else
                        game.add_loss(i);
                }

                current++;
                if (current >= total)
                    current = 0;
                starter = current;

                game.draw_board();
                game.reset_board();
                games_played++;
                std::cout << "Games played: " << games_played << "\n";
                game.draw_scores(total);

                std::cout << "\nWould you like to quit?\n"
                          << "Type q to exit or <Enter> to continue. ";
                std::getline(std::cin, input);
                if (input == "q")
                    running = false;
                else
                    std::cout << "\n";

                break;
            case 4: // draw
                std::cout << "\nIt's a draw!\n\n";

                for (int i = 0; i < total; i++) {
                    game.add_draw(i);
                }

                current = starter + 1;
                if (current >= total)
                    current = 0;

                game.draw_board();
                game.reset_board();
                games_played++;
                std::cout << "Games played: " << games_played << "\n";
                game.draw_scores(total);

                std::cout << "\nWould you like to quit?\n"
                          << "Type y to exit or <Enter> to continue. ";
                std::getline(std::cin, input);
                if (input == "y")
                    running = false;
                else
                    std::cout << "\n";

                break;
            default:
                current++;
        }

        // Roll over current
        if (current >= total)
            current = 0;
    }

    std::cout << "Games played: " << games_played << "\n";
    game.draw_scores(total);
    return 0;
}
