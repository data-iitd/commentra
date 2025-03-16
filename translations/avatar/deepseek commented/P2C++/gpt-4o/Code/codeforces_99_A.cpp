#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string l;  // Taking an input from the user
    std::getline(std::cin, l);  // Read the entire line of input

    size_t pos = l.find('.');  // Find the position of the period
    std::string firstPart = l.substr(0, pos);  // Get the first part
    std::string secondPart = l.substr(pos + 1);  // Get the second part

    std::vector<char> s(firstPart.begin(), firstPart.end());  // Convert the first part into a vector of characters
    int i = secondPart[0] - '0';  // Convert the first character of the second part into an integer

    // Checking if the last character of the first part is '9'
    if (s.back() == '9') {
        std::cout << "GOTO Vasilisa." << std::endl;  // Printing "GOTO Vasilisa." if the last character is '9'
    }
    // Checking if the last character of the first part is not '9' and the integer from the second part is less than 5
    else if (s.back() != '9' && i < 5) {
        std::cout << firstPart << std::endl;  // Printing the first part
    }
    // If the last character of the first part is not '9' and the integer from the second part is 5 or more
    else {
        int incrementedValue = std::stoi(firstPart) + 1;  // Incrementing the first part by 1
        std::cout << incrementedValue << std::endl;  // Printing the incremented value
    }

    return 0;
}

// <END-OF-CODE>
