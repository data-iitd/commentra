#include <iostream>
#include <vector>

int main() {
    int x, y, a, b;
    std::cin >> x >> y >> a >> b;
    // Taking input values for x, y, a, and b

    std::vector<std::pair<int, int>> games;
    // Initializing a vector of pairs called games

    for (int i = a; i <= x; ++i) {
        // Looping from a to x
        if (i <= b) continue;
        // Skipping values of i that are less than or equal to b
        else {
            for (int j = b; j <= y; ++j) {
                // Looping from b to y
                if (i > j) {
                    // Checking if i is greater than j
                    games.push_back(std::make_pair(i, j));
                    // Appending the pair (i, j) to the games vector
                }
            }
        }
    }

    std::cout << games.size() << std::endl;
    // Printing the size of the games vector
    for (const auto& game : games) {
        std::cout << game.first << " " << game.second << std::endl;
        // Printing each pair in the games vector
    }

    return 0;
}
// <END-OF-CODE>
