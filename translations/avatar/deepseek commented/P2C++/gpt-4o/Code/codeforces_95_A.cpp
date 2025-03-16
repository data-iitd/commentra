#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

int main() {
    int pya;
    std::cin >> pya;  // Read the number of inputs to be taken
    std::cin.ignore(); // Ignore the newline character after the integer input
    std::vector<std::string> arre;  // Initialize an empty vector to store the inputs

    // Read pya number of inputs and convert them to lowercase, then append to arre
    while (pya--) {
        std::string inputStr;
        std::getline(std::cin, inputStr);
        std::transform(inputStr.begin(), inputStr.end(), inputStr.begin(), ::tolower);
        arre.push_back(inputStr);
    }

    std::string oString;
    std::getline(std::cin, oString);  // Read the original string
    std::string lowString = oString;   // Copy original string for manipulation
    std::transform(lowString.begin(), lowString.end(), lowString.begin(), ::tolower);  // Convert to lowercase

    char letter1;
    std::cin >> letter1;  // Read the first letter
    letter1 = tolower(letter1);
    char letter2 = (letter1 != 'a') ? 'a' : 'b';  // Determine the second letter

    std::vector<int> valid(oString.length(), 0);  // Initialize a vector of zeros with the length of oString
    std::set<int> setcito;  // Initialize an empty set to store indices

    // Iterate over each string in arre and check if it exists in lowString
    for (const auto& x : arre) {
        size_t wat = 0;
        while (true) {
            size_t index = lowString.find(x, wat);  // Find the index of the substring
            if (index == std::string::npos) {
                break;
            }
            for (size_t i = index; i < index + x.length(); ++i) {
                setcito.insert(i);  // Add the indices to the set
            }
            wat = index + 1;
        }
    }

    // Update the characters in oString based on the setcito indices and letter rules
    for (int i : setcito) {
        char letter = (lowString[i] != letter1) ? letter1 : letter2;
        oString[i] = (islower(oString[i])) ? letter : toupper(letter);
    }

    // Print the modified oString
    std::cout << oString << std::endl;

    return 0;
}

// <END-OF-CODE>
