#include <iostream>
#include <unordered_map>
#include <set>
#include <string>

int main() {
    // Take a string as input from the user
    std::string S;
    std::cin >> S;

    // Create a map to count the frequency of each character in the string
    std::unordered_map<char, int> c;
    for (char ch : S) {
        c[ch]++;
    }

    // Create a set to store unique characters from the string S
    std::set<char> Sa(S.begin(), S.end());

    // Check if the length of the set Sa is equal to 2
    if (Sa.size() != 2) {
        // If not, print "No" and exit the program
        std::cout << "No" << std::endl;
        return 0;
    }

    // Iterate through each character i in the set Sa
    for (char i : Sa) {
        // For each character i, check if its frequency in the string S is equal to 2
        if (c[i] != 2) {
            // If the frequency of any character is not equal to 2, print "No" and exit the program
            std::cout << "No" << std::endl;
            return 0;
        }
    }

    // If all characters have a frequency of 2, print "Yes"
    std::cout << "Yes" << std::endl;

    return 0;
}

// <END-OF-CODE>
