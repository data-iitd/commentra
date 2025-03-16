#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<std::vector<char>> t(4, std::vector<char>(4));

    // Read 4 lines of input and store each line as a list of strings in the list 't'
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            std::cin >> t[i][j];
        }
    }

    // Initialize counters for black and white cells
    int black = 0, white = 0;
    // Initialize a flag to indicate if the grid is correct
    bool correct = false;

    // Iterate through the 3x3 grid (the first 3 rows and columns)
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            // Count the number of black cells ('#') in the 2x2 block
            if (t[i][j] == '#') black++;
            else white++;

            if (t[i][j + 1] == '#') black++;
            else white++;

            if (t[i + 1][j] == '#') black++;
            else white++;

            if (t[i + 1][j + 1] == '#') black++;
            else white++;

            // Check if the current 2x2 block is valid (all black or all white)
            if (black == 0 || black == 3 || white == 0 || white == 3 || white == 4 || black == 4) {
                correct = true; // Mark as correct if the condition is met
                break;
            }

            // Reset counters for the next 2x2 block
            black = 0;
            white = 0;
        }
        if (correct) break;
    }

    // Output the result based on whether a correct block was found
    if (correct) {
        std::cout << "YES" << std::endl; // Print 'YES' if a valid block was found
    } else {
        std::cout << "NO" << std::endl;  // Print 'NO' if no valid block was found
    }

    return 0;
}
