#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::string line;
    
    // Read the first line and split it
    std::getline(std::cin, line);
    std::istringstream iss(line);
    std::string str[1];
    iss >> str[0];

    // Read the second line and parse integers
    std::getline(std::cin, line);
    std::istringstream iss2(line);
    int a, b;
    iss2 >> a >> b;

    // Read the third line
    std::string u;
    std::getline(std::cin, u);

    // Output the result based on the condition
    if (u == str[0]) {
        std::cout << (a - 1) << " " << b << std::endl;
    } else {
        std::cout << a << " " << (b - 1) << std::endl;
    }

    return 0;
}

// <END-OF-CODE>
