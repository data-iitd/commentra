#include <iostream>
#include <sstream>
#include <string>

int main() {
    // Create a string to read input from the user
    std::string line;
    
    // Read a line of input from the user
    std::getline(std::cin, line);
    
    // Create a string stream to parse the input
    std::istringstream iss(line);
    
    // Declare variables to store the integers
    int x, a, y;
    
    // Parse the first three integers from the input
    iss >> x >> a >> y;
    
    // Initialize a variable to store the result
    std::string h = "NO";
    
    // Check if any of the integers is either 5 or 7
    if (x == 5 || x == 7 || a == 5 || a == 7 || y == 5 || y == 7) {
        // Check if the sum of the integers is 17
        if (x + y + a == 17) {
            h = "YES";
        }
    }
    
    // Print the result
    std::cout << h << std::endl;
    
    return 0;
}

// <END-OF-CODE>
