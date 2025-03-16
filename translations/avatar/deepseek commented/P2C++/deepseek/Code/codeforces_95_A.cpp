#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

int main() {
    int pya;
    std::cin >> pya;
    std::vector<std::string> arre;

    // Read pya number of inputs and convert them to lowercase, then append to arre
    while (pya--) {
        std::string input;
        std::cin >> input;
        std::transform(input.begin(), input.end(), input.begin(), ::tolower);
        arre.push_back(input);
    }

    std::string oString;
    std::cin >> oString;
    std::string lowString = oString;
    std::transform(lowString.begin(), lowString.end(), lowString.begin(), ::tolower);

    // Read the first letter and determine the second letter
    char letter1;
    std::cin >> letter1;
    char letter2 = (letter1 == 'a') ? 'b' : 'a';

    std::set<int> setcito;  // Initialize an empty set to store indices

    // Iterate over each string in arre and check if it exists in lowString
    for (const auto& x : arre) {
        size_t pos = 0;
        while ((pos = lowString.find(x, pos)) != std::string::npos) {
            for (size_t i = pos; i < pos + x.length(); ++i) {
                setcito.insert(i);  // Add the indices to the set
            }
            pos += x.length();
        }
    }

    // Convert oString to a vector for easy manipulation
    std::vector<char> oVector(oString.begin(), oString.end());

    // Update the characters in oString based on the setcito indices and letter rules
    for (int i : setcito) {
        char letter = (lowString[i] == letter1) ? letter2 : letter1;
        if (std::islower(oVector[i])) {
            oVector[i] = letter;
        } else {
            oVector[i] = std::toupper(letter);
        }
    }

    // Print the modified oString
    for (char x : oVector) {
        std::cout << x;
    }
    std::cout << std::endl;

    return 0;
}
