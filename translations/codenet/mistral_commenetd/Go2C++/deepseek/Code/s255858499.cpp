#include <iostream>
#include <string>
#include <sstream>

int main() {
    std::string line;
    int a, b;

    // Read the first line from stdin
    std::getline(std::cin, line);
    std::istringstream iss(line);
    iss >> a; // Convert the first line read from stdin to an integer and store it in variable a

    // Read the second line from stdin
    std::getline(std::cin, line);
    iss.str(line);
    iss.clear();
    iss >> b; // Convert the second line read from stdin to an integer and store it in variable b

    // Check if the product of a and b is odd or even
    if (a * b % 2 != 0) {
        // If the product is odd, print "Odd" to stdout
        std::cout << "Odd" << std::endl;
    } else {
        // If the product is even, print "Even" to stdout
        std::cout << "Even" << std::endl;
    }

    return 0;
}
