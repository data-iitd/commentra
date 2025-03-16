#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <sstream>

int main() {
    int n;
    std::cin >> n;  // Take an integer input representing the threshold
    std::cin.ignore();  // Ignore the newline character after the integer input
    std::string line;
    std::getline(std::cin, line);  // Take a whole line input
    std::istringstream iss(line);
    std::unordered_map<std::string, int> countMap;  // To count occurrences of each element
    std::string element;

    // Count occurrences of each element in the input
    while (iss >> element) {
        countMap[element]++;
    }

    bool possible = true;  // Initialize a boolean variable to check if the condition is possible

    // Iterate over the unique elements in the countMap
    for (const auto& pair : countMap) {
        // Check if the count of the current element is greater than or equal to n / 2 + 1
        if (pair.second >= n / 2 + 1) {
            possible = false;  // Set possible to False if the condition is met
            break;  // Break the loop as the condition is already not possible
        }
    }

    // Print 'YES' if possible is True, otherwise print 'NO'
    std::cout << (possible ? "YES" : "NO") << std::endl;

    return 0;
}

// <END-OF-CODE>
