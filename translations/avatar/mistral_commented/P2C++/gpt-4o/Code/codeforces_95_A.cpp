#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

int main() {
    // Initialize variables
    int pya;
    std::cin >> pya; // Get the number of strings to be processed
    std::cin.ignore(); // Ignore the newline character after the integer input
    std::vector<std::string> arre; // Initialize an empty vector to store the strings

    // Process strings input
    while (pya--) {
        std::string x;
        std::getline(std::cin, x); // Get the next string
        std::transform(x.begin(), x.end(), x.begin(), ::tolower); // Convert to lowercase
        arre.push_back(x); // Append the string to the vector
    }

    // Get the original string and its first letter
    std::string oString;
    std::getline(std::cin, oString); // Get the original string
    char letter1 = std::tolower(std::cin.get()); // Get the first letter of the original string in lowercase
    std::cin.ignore(); // Ignore the newline character after the character input

    // Determine the second letter based on the first letter
    char letter2 = (letter1 != 'a') ? 'a' : 'b'; // If the first letter is not 'a', set the second letter to 'b'

    // Initialize a set to store the indices of the strings in the original string
    std::set<int> setcito; 

    // Find the indices of the strings in the original string
    for (const auto& x : arre) {
        size_t pos = oString.find(x); // Find the position of the string in the original string
        while (pos != std::string::npos) {
            setcito.insert(pos); // Add the index to the set
            pos = oString.find(x, pos + 1); // Find the next occurrence
        }
    }

    // Replace the letters in the original string based on the indices of the strings
    for (int i : setcito) {
        char letter = (std::islower(oString[i]) != std::islower(letter1)) ? letter1 : letter2; // Determine the letter to replace
        oString[i] = std::islower(oString[i]) ? letter : std::toupper(letter); // Replace the letter, preserving the case
    }

    // Print the modified string
    std::cout << oString << std::endl; // Print the modified string

    return 0;
}
// <END-OF-CODE>
