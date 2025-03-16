#include <iostream> // Include iostream for input and output
#include <sstream>  // Include sstream for string stream
#include <string>   // Include string for string manipulation

int main() {
    // Initialize a string variable to read input from console
    std::string line;

    // Read a line of input from the console
    std::getline(std::cin, line);

    // Create a string stream from the input line
    std::istringstream iss(line);

    // Declare variables to hold the integers
    int x, a, y;

    // Read the integers from the string stream
    iss >> x >> a >> y;

    // Initialize a string variable h with the value "NO"
    std::string h = "NO";

    // Check if any of the numbers x, a, or y are equal to 5 or 7
    if (x == 5 || x == 7 || a == 5 || a == 7 || y == 5 || y == 7) {
        // If any of the numbers satisfy the condition, check if their sum is equal to 17
        if (x + y + a == 17) {
            // If the sum is equal to 17, set the value of h to "YES"
            h = "YES";
        }
    }

    // Print the value of h to the console
    std::cout << h << std::endl;

    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
