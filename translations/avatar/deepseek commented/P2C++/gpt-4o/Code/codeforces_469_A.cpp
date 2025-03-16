#include <iostream>
#include <vector>
#include <set>

int main() {
    int max_level;
    std::cin >> max_level;

    int n;
    std::cin >> n; // Read the number of levels for player x
    std::set<int> x_levels;
    for (int i = 0; i < n; ++i) {
        int level;
        std::cin >> level;
        if (level != 0) {
            x_levels.insert(level);
        }
    }

    std::cin >> n; // Read the number of levels for player y
    std::set<int> y_levels;
    for (int i = 0; i < n; ++i) {
        int level;
        std::cin >> level;
        if (level != 0) {
            y_levels.insert(level);
        }
    }

    // Find the union of the two sets
    std::set<int> z_levels = x_levels;
    z_levels.insert(y_levels.begin(), y_levels.end());

    // Check if the size of the union is equal to max_level
    if (z_levels.size() != max_level) {
        std::cout << "Oh, my keyboard!" << std::endl;
    } else {
        std::cout << "I become the guy." << std::endl;
    }

    return 0;
}

// <END-OF-CODE>
