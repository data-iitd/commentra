
// Importing necessary C++ libraries for reading input from the console and handling exceptions
#include <iostream>
#include <string>
#include <sstream>

// Main function is the entry point of the C++ application
int main() {

    // Creating a string variable 'input' to store the input from the console
    std::string input;

    // Reading a single line of input from the console and storing it in the 'input' variable
    std::getline(std::cin, input);

    // Creating a stringstream object'ss' to parse the input string
    std::stringstream ss(input);

    // Creating two integer variables 'h' and 'a' to store the parsed values
    int h, a;

    // Extracting the first integer value from the stringstream and storing it in 'h'
    ss >> h;

    // Extracting the second integer value from the stringstream and storing it in 'a'
    ss >> a;

    // Initializing an integer variable 'num' to keep track of the number of steps
    int num = 0;

    // Using a while loop to simulate the given condition
    while (h > 0) {

        // Subtracting 'a' from 'h' in each iteration
        h = h - a;

        // Incrementing the 'num' variable after each successful subtraction
        num++;
    }

    // Printing the final result 'num' to the console
    std::cout << num << std::endl;

    // Ending the C++ program
    return 0;
}
