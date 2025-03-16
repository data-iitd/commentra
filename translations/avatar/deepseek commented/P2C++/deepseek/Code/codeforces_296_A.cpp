#include <iostream>
#include <sstream>
#include <unordered_set>
#include <vector>
#include <string>

int main() {
    int n;
    std::cin >> n;
    std::string input;
    std::getline(std::cin, input);  // Read the rest of the line
    std::getline(std::cin, input);
    std::stringstream ss(input);
    std::vector<std::string> m;
    std::string token;

    // Split the input string into tokens and store them in the vector `m`
    while (std::getline(ss, token, ' ')) {
        m.push_back(token);
    }

    bool possible = true;  // Initialize a boolean variable to check if the condition is possible

    // Create an unordered_set from the vector `m` to store unique elements
    std::unordered_set<std::string> unique_elements(m.begin(), m.end());

    // Iterate over the unique elements in the set `unique_elements`
    for (const auto& i : unique_elements) {
        // Check if the count of the current element is greater than or equal to n / 2 + 1
        if (std::count(m.begin(), m.end(), i) >= n / 2 + 1) {
            possible = false;  // Set possible to False if the condition is met
            break;  // Break the loop as the condition is already not possible
        }
    }

    // Print 'YES' if possible is True, otherwise print 'NO'
    std::cout << (possible ? "YES" : "NO") << std::endl;

    return 0;
}
