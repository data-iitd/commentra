#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int main() {
    // Read the maximum level from user input
    int max_level;
    std::cin >> max_level;

    // Read the levels completed by player X
    int n;
    std::cin >> n; // Read the count of levels for player X
    std::set<int> x;
    for (int i = 0; i < n; ++i) {
        int level;
        std::cin >> level;
        x.insert(level);
    }

    // Read the levels completed by player Y
    std::cin >> n; // Read the count of levels for player Y
    std::set<int> y;
    for (int i = 0; i < n; ++i) {
        int level;
        std::cin >> level;
        y.insert(level);
    }

    // Check if player X has completed level 0, if so, remove it from the set
    if (x.count(0)) {
        x.erase(0);
    }
    // If player X has not completed level 0, check if player Y has, and remove it if present
    else if (y.count(0)) {
        y.erase(0);
    }

    // Create a union of both sets to combine all unique levels completed by both players
    std::set<int> z = x;
    z.insert(y.begin(), y.end());

    // Check if the number of unique levels completed matches the maximum level
    if (z.size() != max_level) {
        // If not, print a message indicating that not all levels were completed
        std::cout << "Oh, my keyboard!" << std::endl;
    } else {
        // If all levels were completed, print a success message
        std::cout << "I become the guy." << std::endl;
    }

    return 0;
}

// <END-OF-CODE>
