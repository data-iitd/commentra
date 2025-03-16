

#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    int n;  // Declare an integer variable to store the threshold
    std::string m;  // Declare a string variable to store the input
    std::unordered_map<char, int> count;  // Declare an unordered_map to store the count of each character in the string

    // Take an integer input representing the threshold
    std::cin >> n;

    // Take a space-separated string input and store it in the variable `m`
    std::cin >> m;

    // Iterate over the characters in the string `m`
    for (char c : m) {
        // Increment the count of the current character in the unordered_map
        count[c]++;
    }

    // Check if the condition is possible by iterating over the unique elements in the unordered_map
    bool possible = true;
    for (auto const& [key, value] : count) {
        // Check if the count of the current element is greater than or equal to n / 2 + 1
        if (value >= n / 2 + 1) {
            possible = false;  // Set possible to False if the condition is met
            break;  // Break the loop as the condition is already not possible
        }
    }

    // Print 'YES' if possible is True, otherwise print 'NO'
    std::cout << (possible? "YES" : "NO") << std::endl;

    return 0;
}
