#include <iostream>
#include <unordered_map>
#include <set>
#include <string>

int main() {
    // Take input string from the user
    std::string S;
    std::cin >> S;

    // Create a map to count the frequency of each character in the string
    std::unordered_map<char, int> charCount;

    // Count occurrences of each character
    for (char c : S) {
        charCount[c]++;
    }

    // Create a set of unique characters from the input string
    std::set<char> uniqueChars(S.begin(), S.end());

    // Check if the number of unique characters is not equal to 2
    if (uniqueChars.size() != 2) {
        // If there are not exactly 2 unique characters, print "No" and exit
        std::cout << "No" << std::endl;
        return 0;
    }

    // Iterate over each unique character in the set
    for (char i : uniqueChars) {
        // Check if the count of the current character is not equal to 2
        if (charCount[i] != 2) {
            // If any character does not appear exactly twice, print "No" and exit
            std::cout << "No" << std::endl;
            return 0;
        }
    }

    // If both conditions are satisfied, print "Yes"
    std::cout << "Yes" << std::endl;

    return 0;
}

// <END-OF-CODE>
