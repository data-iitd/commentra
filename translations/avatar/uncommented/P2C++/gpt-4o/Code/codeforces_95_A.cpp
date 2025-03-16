#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

int main() {
    int pya;
    std::cin >> pya;
    std::cin.ignore(); // To ignore the newline character after the integer input
    std::vector<std::string> arre;

    while (pya--) {
        std::string inputStr;
        std::getline(std::cin, inputStr);
        std::transform(inputStr.begin(), inputStr.end(), inputStr.begin(), ::tolower);
        arre.push_back(inputStr);
    }

    std::string oString;
    std::getline(std::cin, oString);
    std::string lowString = oString;
    std::transform(lowString.begin(), lowString.end(), lowString.begin(), ::tolower);

    char letter1 = std::tolower(std::cin.get());
    std::cin.ignore(); // To ignore the newline character after the character input
    char letter2 = (letter1 != 'a') ? 'a' : 'b';

    std::vector<int> valid(oString.length(), 0);
    std::set<int> setcito;

    for (const auto& x : arre) {
        size_t wat = 0;
        while (true) {
            size_t index = lowString.find(x, wat);
            if (index == std::string::npos) {
                break;
            }
            for (size_t i = index; i < index + x.length(); ++i) {
                setcito.insert(i);
            }
            wat = index + 1;
        }
    }

    for (size_t i = 0; i < oString.length(); ++i) {
        if (setcito.find(i) != setcito.end()) {
            char letter = (lowString[i] != letter1) ? letter1 : letter2;
            oString[i] = (std::islower(oString[i])) ? letter : std::toupper(letter);
        }
    }

    std::cout << oString << std::endl;

    return 0;
}

// <END-OF-CODE>
