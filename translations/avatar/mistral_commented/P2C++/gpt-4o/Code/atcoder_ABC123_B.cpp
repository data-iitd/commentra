#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main() {
    // Initialize an empty vector called menu
    std::vector<std::pair<int, int>> menu;

    // Use a for loop to iterate 5 times
    for (int i = 0; i < 5; ++i) {
        std::string m;
        std::cin >> m;

        // Extract the last character of the string m to determine the exponent e
        int e = m.back() - '0';

        // If e is 0, set it to 10
        if (e == 0) {
            e = 10;
        }

        // Append a pair containing the integer value of m and the exponent e to the menu vector
        menu.push_back({std::stoi(m), e});
    }

    // Sort the menu vector based on the exponent value using a lambda function as the comparator
    std::sort(menu.begin(), menu.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.second < b.second;
    });

    // Initialize a variable called ans to 0
    int ans = 0;

    // Use a for loop to iterate through the menu vector starting from the second element (index 1)
    for (size_t i = 1; i < menu.size(); ++i) {
        // Calculate the number of full 10s that can be obtained by dividing the integer value by 10 and rounding up
        int num_full_10s = std::ceil(menu[i].first / 10.0);

        // Multiply this value by 10 and add it to the ans variable
        ans += num_full_10s * 10;
    }

    // Finally, print the sum of the first element in the menu vector (which is the initial number) and the value of ans
    std::cout << menu[0].first + ans << std::endl;

    return 0;
}

// <END-OF-CODE>
