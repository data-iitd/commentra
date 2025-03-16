#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

int main() {
    // Take an integer 'n' as input from the user
    int n;
    std::cin >> n;

    // Take a list 'm' as input from the user, where each element is a single character
    std::vector<char> m(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> m[i];
    }

    // Initialize a boolean variable 'possible' with a default value of true
    bool possible = true;

    // Create a frequency map to count occurrences of each character
    std::unordered_map<char, int> frequency;
    for (char c : m) {
        frequency[c]++;
    }

    // Iterate through each unique character in the frequency map
    for (const auto& pair : frequency) {
        char i = pair.first;
        // Check if the character 'i' appears more than 'n/2 + 1' times in the list 'm'
        if (pair.second >= n / 2 + 1) {
            // If the condition is true, set 'possible' to false and break the loop
            possible = false;
            break;
        }
    }

    // Print 'YES' if 'possible' is still true, otherwise print 'NO'
    std::cout << (possible ? "YES" : "NO") << std::endl;

    return 0;
}

// <END-OF-CODE>
