#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    std::string s;
    std::cin >> s;  // Read the input string
    bool x = true;  // Initialize a boolean variable to track the result
    std::unordered_map<char, int> dt;  // Initialize an empty dictionary to store character frequencies

    // Iterate over each character in the input string and update the frequency count in the dictionary
    for (char i : s) {
        dt[i]++;
    }

    int cnt = 0;  // Initialize a counter to keep track of characters with an odd frequency
    x = true;  // Reset the boolean variable to track the result

    // Iterate over the items in the dictionary to determine if there is more than one character with an odd frequency
    for (const auto& pair : dt) {
        if (pair.second % 2 != 0 && cnt < 1) {
            cnt++;
        } else if (pair.second % 2 != 0 && cnt >= 1) {
            x = false;
            break;
        }
    }

    // Determine the output based on the value of cnt and the length of the input string
    if (x) {
        std::cout << "First" << std::endl;  // Print "First" if there is at most one character with an odd frequency
    } else if (!x && s.length() % 2 == 0) {
        std::cout << "Second" << std::endl;  // Print "Second" if there is more than one character with an odd frequency and the length of the input string is even
    } else if (!x && s.length() % 2 != 0) {
        std::cout << "First" << std::endl;  // Print "First" if there is more than one character with an odd frequency and the length of the input string is odd
    }

    return 0;
}

// <END-OF-CODE>
