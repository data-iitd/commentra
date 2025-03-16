#include <iostream>
#include <sstream>
#include <string>

int main() {
    // Create a string to read the first line of input
    std::string line;
    std::getline(std::cin, line);
    
    // Split the first line by spaces and store in a string stream
    std::istringstream iss(line);
    std::string str[1];
    iss >> str[0]; // Read the first token into str[0]

    // Read the second line of input
    std::getline(std::cin, line);
    std::istringstream iss2(line);
    
    // Parse the first integer from the tokenized input
    int a, b;
    iss2 >> a >> b; // Read two integers

    // Read another string from the input
    std::string u;
    std::getline(std::cin, u);

    // Check if the read string is equal to the first element of the array and print accordingly
    if (u == str[0]) {
        std::cout << (a - 1) << " " << b << std::endl;
    } else {
        std::cout << a << " " << (b - 1) << std::endl;
    }

    return 0;
}

// <END-OF-CODE>
