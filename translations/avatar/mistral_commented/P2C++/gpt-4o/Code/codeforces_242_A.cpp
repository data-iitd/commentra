#include <iostream>
#include <vector>

int main() {
    // Get user input as a string and convert it to a list of integers
    int x, y, a, b;
    std::cin >> x >> y >> a >> b;

    // Initialize an empty vector to store the games
    std::vector<std::pair<int, int>> games;

    // Iterate through a range of numbers from a to x+1
    for (int i = a; i <= x; ++i) {
        // If i is less than or equal to b, skip to the next iteration
        if (i <= b) {
            continue;
        }
        // Iterate through a range of numbers from b to y+1
        for (int j = b; j <= y; ++j) {
            // If i is greater than j, append the pair (i, j) to the games vector
            if (i > j) {
                games.push_back(std::make_pair(i, j));
            }
        }
    }

    // Print the length of the games vector
    std::cout << games.size() << std::endl;

    // Iterate through the games vector and print each pair
    for (const auto& game : games) {
        // Print the pair as a string in the format "i j"
        std::cout << game.first << " " << game.second << std::endl;
    }

    return 0;
}

// <END-OF-CODE>
