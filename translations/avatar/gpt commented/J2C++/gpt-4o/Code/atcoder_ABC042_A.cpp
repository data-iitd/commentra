#include <iostream>
#include <sstream>
#include <string>

int main() {
    // Create a string to hold the input line
    std::string line;
    
    // Read a line of input from the console
    std::getline(std::cin, line);
    
    // Create a string stream to parse the input
    std::istringstream iss(line);
    
    // Declare variables to hold the parsed integers
    int x, a, y;
    
    // Parse the first three elements of the input into integers
    iss >> x >> a >> y;
    
    // Initialize a variable to hold the result, defaulting to "NO"
    std::string h = "NO";
    
    // Check if any of the numbers x, a, or y are either 5 or 7
    if (x == 5 || x == 7 || a == 5 || a == 7 || y == 5 || y == 7) {
        // If the sum of x, a, and y equals 17, set the result to "YES"
        if (x + y + a == 17) {
            h = "YES";
        }
    }
    
    // Output the result
    std::cout << h << std::endl;

    return 0;
}

// <END-OF-CODE>
