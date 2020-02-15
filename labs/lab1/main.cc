#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
using namespace std;

unordered_map<char, int> get_alpha_stats(const string input) {
    unordered_map<char, int> freq;

    for (int i = 0; i < input.length(); i++) {
        if (isalpha(input[i])) {
            char current = tolower(input[i]);
            
            if (freq.count(current) == 0) {
                // Key does not exist.
                freq[current] = 1;
            }
            else {
                // Key exists.
                freq[current]++;
            }
        }
    }

    return freq;
}

void show_alpha_stats(const unordered_map<char, int> freq) {
    for (pair<char, int> element : freq) {
        cout << (char)toupper(element.first) << " or "
             << element.first << ": "
             << element.second << "\n";
    }
}

int main(int argc, char** argv) {
    string input;
    unordered_map<char, int> freq;

    if (argc == 1) {
        cout << "Enter a string: ";
        getline(cin, input);

        freq = get_alpha_stats(input);

        cout << "\n\"" << input << "\"\n\n";
    }
    else {
        ifstream input_file(argv[1]);
        unordered_map<char, int> temp;

        if (!input_file.is_open()) {
            cout << "File \"" << argv[1] << "\" not found\n";
            return 1;
        }

        while (input_file >> input) {
            temp = get_alpha_stats(input);

            // Merge temp with freq
            for (auto& it : temp) {
                if (freq.count(it.first) == 0)
                    freq[it.first] = it.second;
                else
                    freq[it.first] += it.second;
            }
        }

        cout << "\n";
    }

    show_alpha_stats(freq);
    cout << "\n";

    return 0;
}
