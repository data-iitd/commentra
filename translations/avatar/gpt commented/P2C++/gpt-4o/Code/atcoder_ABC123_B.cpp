#include <iostream>  // Include the iostream library for input and output
#include <vector>    // Include the vector library for dynamic arrays
#include <algorithm> // Include the algorithm library for sorting
#include <cmath>     // Include the cmath library for mathematical functions

int main() {
    std::vector<std::pair<int, int>> menu; // Initialize a vector to store menu items as pairs

    // Loop to collect 5 menu items from user input
    for (int i = 0; i < 5; ++i) {
        std::string m; // Declare a string to hold user input
        std::cin >> m; // Take input from the user
        int e = m.back() - '0'; // Extract the last character of the input and convert it to an integer
        if (e == 0) { // If the last digit is 0
            e = 10; // Change it to 10 (to avoid zero as a value)
        }
        menu.push_back({std::stoi(m), e}); // Append a pair containing the integer value of m and e to the menu
    }

    // Sort the menu based on the second element (e) of each pair
    std::sort(menu.begin(), menu.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
    });

    int ans = 0; // Initialize a variable to accumulate the total cost

    // Loop through the sorted menu starting from the second item
    for (size_t i = 1; i < menu.size(); ++i) {
        // Calculate the cost for each item, rounding up to the nearest multiple of 10
        ans += std::ceil(menu[i].first / 10.0) * 10;
    }

    // Print the total cost, including the first item's original value
    std::cout << ans + menu[0].first << std::endl; // Add the first item's value to the accumulated cost and print the result

    return 0; // Return 0 to indicate successful completion
} // <END-OF-CODE>
