#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    // Create a string to read input from the user
    std::string s;
    
    // Read the input string from the user
    std::cin >> s;
    
    // Initialize an unordered_map to store the frequency of each character
    std::unordered_map<char, int> map;
    
    // Loop through each character in the string
    for (char c : s) {
        // Increment the count of the character in the map
        map[c]++;
    }
    
    // Initialize a boolean variable to check if the conditions are met
    bool ok = true;
    
    // Check if each character appears exactly twice
    for (const auto& entry : map) {
        if (entry.second != 2) {
            ok = false; // Set ok to false if any character does not appear twice
            break;
        }
    }
    
    // Check if there are exactly two unique characters that appear twice
    if (ok && map.size() == 2) {
        std::cout << "Yes" << std::endl; // Output "Yes" if conditions are satisfied
    } else {
        std::cout << "No" << std::endl; // Output "No" if conditions are not satisfied
    }
    
    return 0;
}

// <END-OF-CODE>
