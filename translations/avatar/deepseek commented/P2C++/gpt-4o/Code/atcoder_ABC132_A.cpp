#include <iostream>
#include <unordered_map>
#include <set>
#include <string>

int main() {
    std::string S;  // Declare a string variable to hold the input
    std::cin >> S;  // Take a string input from the user

    std::unordered_map<char, int> c;  // Create a map to count the frequency of each character
    for (char ch : S) {
        c[ch]++;  // Increment the count for each character
    }

    std::set<char> Sa(S.begin(), S.end());  // Create a set of unique characters from the string S

    // Check if the number of unique characters is not equal to 2
    if (Sa.size() != 2) {
        std::cout << "No" << std::endl;  // Print "No" and exit if the condition is true
        return 0;  // Exit the program
    }

    // Iterate over the set of unique characters and check if the frequency of each character is not equal to 2
    for (char i : Sa) {
        if (c[i] != 2) {
            std::cout << "No" << std::endl;  // Print "No" and exit if the condition is true
            return 0;  // Exit the program
        }
    }

    std::cout << "Yes" << std::endl;  // Print "Yes" if all characters have a frequency of 2
    return 0;  // Exit the program
}

// <END-OF-CODE>
