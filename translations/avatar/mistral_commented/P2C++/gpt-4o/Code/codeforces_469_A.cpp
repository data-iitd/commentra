#include <iostream>
#include <vector>
#include <set>

int main() {
    // User inputs the maximum level of the set
    int max_level;
    std::cin >> max_level;

    // User inputs two lists, x and y, separated by a newline
    std::vector<int> x, y;
    int n;

    // Read the first list
    std::cin >> n; // Read the size of the first list
    x.resize(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> x[i];
    }

    // Read the second list
    std::cin >> n; // Read the size of the second list
    y.resize(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> y[i];
    }

    // Remove the first element from both lists, as they are not part of the sets
    x.erase(x.begin());
    y.erase(y.begin());

    // Convert both lists to sets for faster set operations
    std::set<int> set_x(x.begin(), x.end());
    std::set<int> set_y(y.begin(), y.end());

    // Check if zero is present in the first set
    if (set_x.count(0)) {
        // If it is, remove it
        set_x.erase(0);
    } else {
        // Else, check if zero is present in the second set
        if (set_y.count(0)) {
            // If it is, remove it
            set_y.erase(0);
        }
    }

    // Combine both sets into a new set z
    std::set<int> set_z;
    set_z.insert(set_x.begin(), set_x.end());
    set_z.insert(set_y.begin(), set_y.end());

    // Check if the size of the combined set is equal to the maximum level
    if (set_z.size() != max_level) {
        // If not, print an error message
        std::cout << "Oh, my keyboard!" << std::endl;
    } else {
        // Else, print a success message
        std::cout << "I become the guy." << std::endl;
    }

    return 0;
}

// <END-OF-CODE>
