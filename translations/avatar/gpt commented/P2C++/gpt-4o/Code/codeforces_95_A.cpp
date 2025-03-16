#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

int main() {
    // Read an integer input which represents the number of strings to be added to the list
    int pya;
    std::cin >> pya;

    // Initialize a vector to store the input strings
    std::vector<std::string> arre;

    // Loop to collect 'pya' number of strings from user input
    std::string inputString;
    std::cin.ignore(); // To ignore the newline character after the integer input
    while (pya--) {
        std::getline(std::cin, inputString);
        // Append the lowercase version of the input string to the vector
        std::transform(inputString.begin(), inputString.end(), inputString.begin(), ::tolower);
        arre.push_back(inputString);
    }

    // Read the original string from user input
    std::string oString;
    std::getline(std::cin, oString);

    // Convert the original string to lowercase for comparison
    std::string lowString = oString;
    std::transform(lowString.begin(), lowString.end(), lowString.begin(), ::tolower);

    // Read a letter from user input and convert it to lowercase
    char letter1;
    std::cin >> letter1;
    letter1 = tolower(letter1);

    // Determine the second letter based on the first letter; if it's 'a', use 'b', otherwise use 'a'
    char letter2 = (letter1 != 'a') ? 'a' : 'b';

    // Initialize a set to store unique indices where replacements will occur
    std::set<int> setcito;

    // Loop through each string in the vector 'arre'
    for (const auto& x : arre) {
        // Check if the current string 'x' is found in the lowercase version of the original string
        size_t wat = 0; // Initialize a variable to track the search position
        while (true) {
            // Find the index of the current string 'x' starting from position 'wat'
            size_t index = lowString.find(x, wat);
            if (index == std::string::npos) {
                break; // Exit the loop if no more occurrences are found
            }
            // Add the indices of the found string to the set for replacement
            for (size_t i = index; i < index + x.length(); ++i) {
                setcito.insert(i);
            }
            wat = index + 1; // Move the search position forward
        }
    }

    // Loop through the indices stored in 'setcito' for replacement
    for (int i : setcito) {
        // Determine which letter to use for replacement based on the original character
        char letter = (lowString[i] != letter1) ? letter1 : letter2;
        // Replace the character in the original string with the chosen letter, maintaining case
        oString[i] = (islower(oString[i])) ? letter : toupper(letter);
    }

    // Print the modified string without spaces between characters
    std::cout << oString << std::endl;

    return 0;
}

// <END-OF-CODE>
