#include <iostream>
#include <sstream>
#include <string>

int main() {
    // Create a string to read the first line of input
    std::string line;
    std::getline(std::cin, line);
    
    // Split the first line by spaces and store it in a string stream
    std::istringstream iss(line);
    std::string str[1];
    iss >> str[0]; // Read the first token into str[0]

    // Read the second line of input
    std::getline(std::cin, line);
    std::istringstream iss2(line);
    
    // Parse the first token as an integer and store it in variable 'a'
    int a;
    iss2 >> a;
    
    // Parse the second token as an integer and store it in variable 'b'
    int b;
    iss2 >> b;

    // Read another line of input and store it in variable 'u'
    std::string u;
    std::getline(std::cin, u);
    
    // Compare the string 'u' with the first element of the array 'str'
    // Print the result based on the comparison
    if (u == str[0]) {
        std::cout << (a - 1) << " " << b << std::endl;
    } else {
        std::cout << a << " " << (b - 1) << std::endl;
    }

    return 0;
}

// <END-OF-CODE>
