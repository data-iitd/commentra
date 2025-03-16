#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Read the number of test cases
    int n;
    std::cin >> n;

    // Read the array of integers
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    // Initialize variables
    int current_level = 0;
    int counter = 0;
    int counter_turns = -1;

    // Main loop
    while (counter < n) {
        // Increment turns counter
        counter_turns += 1;

        // Iterate through the array
        for (int i = 0; i < n; ++i) {
            // If current index is valid and its value is less than or equal to current level
            if (a[i] != -1 && a[i] <= counter) {
                // Increment counter and mark the index as visited
                counter += 1;
                a[i] = -1;
            }
        }

        // Reverse the array
        std::reverse(a.begin(), a.end());
    }

    // Print the result
    std::cout << counter_turns << std::endl;

    return 0;
}

