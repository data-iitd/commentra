#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

int main() {
    // Take a string input from the user and store it in the variable `s`
    std::string s;
    std::cin >> s;

    // Create unordered_map to count occurrences of characters at even and odd indices
    std::unordered_map<char, int> even, odd;

    // Count occurrences of characters at even and odd indices
    for (size_t i = 0; i < s.length(); ++i) {
        if (i % 2 == 0) {
            even[s[i]]++;
        } else {
            odd[s[i]]++;
        }
    }

    // Calculate the number of flips needed for both scenarios
    int flips1 = s.length() - (even['0'] + odd['1']);
    int flips2 = s.length() - (even['1'] + odd['0']);

    // Print the minimum of the two outcomes
    std::cout << std::min(flips1, flips2) << std::endl;

    return 0;
}

// <END-OF-CODE>
