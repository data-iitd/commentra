#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

int main() {
    // Read an integer input n which represents the threshold for majority
    int n;
    std::cin >> n;

    // Read a line of input, split it into a vector of strings, and store it in m
    std::vector<std::string> m;
    std::string input;
    std::cin.ignore(); // To ignore the newline character after reading n
    std::getline(std::cin, input);
    
    std::string word;
    std::istringstream iss(input);
    while (iss >> word) {
        m.push_back(word);
    }

    // Initialize a variable to track if a majority element is possible
    bool possible = true;

    // Create a frequency map to count occurrences of each unique element
    std::unordered_map<std::string, int> countMap;
    for (const auto& elem : m) {
        countMap[elem]++;
    }

    // Iterate through each unique element in the map
    for (const auto& pair : countMap) {
        // Check if the count of the current element is greater than or equal to n/2 + 1
        if (pair.second >= n / 2 + 1) {
            // If it is, set possible to false and break the loop
            possible = false;
            break;
        }
    }

    // Print 'YES' if a majority element is not found, otherwise print 'NO'
    std::cout << (possible ? "YES" : "NO") << std::endl;

    return 0;
}

// <END-OF-CODE>
