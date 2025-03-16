
#include <iostream>
#include <vector>
#include <set>

int main() {
    // Read the maximum level from user input
    int max_level;
    std::cin >> max_level;

    // Read the levels completed by player X and convert them to a vector of integers
    int x_count;
    std::cin >> x_count;
    std::vector<int> x(x_count);
    for (int i = 0; i < x_count; i++) {
        std::cin >> x[i];
    }

    // Read the levels completed by player Y and convert them to a vector of integers
    int y_count;
    std::cin >> y_count;
    std::vector<int> y(y_count);
    for (int i = 0; i < y_count; i++) {
        std::cin >> y[i];
    }

    // Remove the first element from both vectors, which represents the count of levels
    x.erase(x.begin());
    y.erase(y.begin());

    // Convert the vectors of levels into sets to eliminate duplicates
    std::set<int> x_set(x.begin(), x.end());
    std::set<int> y_set(y.begin(), y.end());

    // Check if player X has completed level 0, if so, remove it from the set
    if (x_set.count(0)) {
        x_set.erase(0);
    }
    // If player X has not completed level 0, check if player Y has, and remove it if present
    else if (y_set.count(0)) {
        y_set.erase(0);
    }

    // Create a union of both sets to combine all unique levels completed by both players
    std::set<int> z_set;
    std::set_union(x_set.begin(), x_set.end(), y_set.begin(), y_set.end(), std::inserter(z_set, z_set.begin()));

    // Check if the number of unique levels completed matches the maximum level
    if (z_set.size()!= max_level) {
        // If not, print a message indicating that not all levels were completed
        std::cout << "Oh, my keyboard!" << std::endl;
    } else {
        // If all levels were completed, print a success message
        std::cout << "I become the guy." << std::endl;
    }

    return 0;
}
