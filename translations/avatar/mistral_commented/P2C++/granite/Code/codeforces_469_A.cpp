
#include <iostream>
#include <set>
#include <vector>

int main() {
    // User inputs the maximum level of the set
    int max_level;
    std::cin >> max_level;

    // User inputs two lists, x and y, separated by a newline
    std::vector<int> x, y;
    int temp;
    while (std::cin >> temp) {
        x.push_back(temp);
    }
    while (std::cin >> temp) {
        y.push_back(temp);
    }

    // Remove the first element from both lists, as they are not part of the sets
    x.erase(x.begin());
    y.erase(y.begin());

    // Convert both lists to sets for faster set operations
    std::set<int> x_set(x.begin(), x.end());
    std::set<int> y_set(y.begin(), y.end());

    // Check if zero is present in the first set
    if (x_set.count(0)) {
        // If it is, remove it
        x_set.erase(0);
    }
    // Else, check if zero is present in the second set
    else {
        if (y_set.count(0)) {
            // If it is, remove it
            y_set.erase(0);
        }
    }

    // Combine both sets into a new set z
    std::set<int> z;
    std::set_union(x_set.begin(), x_set.end(), y_set.begin(), y_set.end(), std::inserter(z, z.begin()));

    // Check if the size of the combined set is equal to the maximum level
    if (z.size()!= max_level) {
        // If not, print an error message
        std::cout << "Oh, my keyboard!" << std::endl;
    }
    // Else, print a success message
    else {
        std::cout << "I become the guy." << std::endl;
    }

    return 0;
}
