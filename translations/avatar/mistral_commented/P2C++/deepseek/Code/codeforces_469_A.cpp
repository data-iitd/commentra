#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int main() {
    int max_level;
    std::cin >> max_level;

    std::vector<int> x, y;
    int input;

    // Read the first list (x)
    while (std::cin >> input && input != 0) {
        x.push_back(input);
    }

    // Read the second list (y)
    while (std::cin >> input && input != 0) {
        y.push_back(input);
    }

    // Convert vectors to sets for faster set operations
    std::set<int> x_set(x.begin(), x.end());
    std::set<int> y_set(y.begin(), y.end());

    // Combine both sets into a new set z
    std::set<int> z;
    std::set_union(x_set.begin(), x_set.end(), y_set.begin(), y_set.end(), std::inserter(z, z.begin()));

    // Check if the size of the combined set is equal to the maximum level
    if (z.size() != max_level) {
        // If not, print an error message
        std::cout << "Oh, my keyboard!" << std::endl;
    } else {
        // Else, print a success message
        std::cout << "I become the guy." << std::endl;
    }

    return 0;
}
