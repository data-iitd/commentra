// Including necessary C++ libraries
#include <iostream>
#include <string>
#include <sstream>

// Main function is the entry point of the C++ program
int main() {
    try {
        // Creating a string variable to store the input from the console
        std::string input;

        // Reading a line of input from the console and storing it in the 'input' variable
        std::getline(std::cin, input);

        // Creating a stringstream object to parse the input string
        std::stringstream ss(input);

        // Creating two integer variables 'a' and 'b' to store the first and second elements of the input array respectively
        int a, b;

        // Parsing the first element of the input array into 'a'
        ss >> a;

        // Parsing the second element of the input array into 'b'
        ss >> b;

        // Calculate the value of 'c' by subtracting 'b' multiplied by 2 from 'a'
        int c = a - b * 2;

        // If the value of 'c' is negative, set it to zero
        if (c < 0) {
            c = 0;
        }

        // Print the value of 'c' to the console
        std::cout << c << std::endl;
    } catch (...) {
        // Handling any exceptions that might occur during the execution of the program
    }

    // End of code
    return 0;
}


