#include <iostream>
#include <vector>

int main() {
    // Read input values for x, y, a, and b
    int x, y, a, b;
    std::cin >> x >> y >> a >> b;

    // Initialize a vector to store valid game pairs
    std::vector<std::pair<int, int>> games;

    // Iterate over the range from a to x (inclusive)
    for (int i = a; i <= x; ++i) {
        // Skip the iteration if i is less than or equal to b
        if (i <= b) {
            continue;
        } else {
            // Iterate over the range from b to y (inclusive)
            for (int j = b; j <= y; ++j) {
                // Check if the current i is greater than j
                if (i > j) {
                    // If the condition is met, append the pair (i, j) to the games vector
                    games.push_back(std::make_pair(i, j));
                }
            }
        }
    }

    // Print the total number of valid game pairs found
    std::cout << games.size() << std::endl;

    // Print each valid game pair
    for (const auto& pair : games) {
        std::cout << pair.first << " " << pair.second << std::endl;
    }

    return 0;
}

// <END-OF-CODE>
