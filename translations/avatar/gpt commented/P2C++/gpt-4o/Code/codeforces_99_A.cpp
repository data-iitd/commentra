#include <iostream>
#include <string>
#include <vector>

int main() {
    // Read input from the user
    std::string l;
    std::getline(std::cin, l);

    // Split the input string into two parts using '.' as the delimiter
    size_t pos = l.find('.');
    std::string s = l.substr(0, pos);
    std::string p = l.substr(pos + 1);

    // Extract the first character from the second part and convert it to an integer
    int i = p[0] - '0';

    // Check if the last character of the first part is '9'
    if (s.back() == '9') {
        // If it is '9', print the message "GOTO Vasilisa."
        std::cout << "GOTO Vasilisa." << std::endl;
    }
    // Check if the last character is not '9' and the integer i is less than 5
    else if (s.back() != '9' && i < 5) {
        // If both conditions are true, print the string
        std::cout << s << std::endl;
    } else {
        // If the last character is not '9' and i is 5 or more
        // Convert the string to an integer, increment it by 1, and convert it back to a string
        int num = std::stoi(s);
        num += 1;
        // Print the incremented value
        std::cout << num << std::endl;
    }

    return 0;
}

// <END-OF-CODE>
