// Including necessary C++ libraries for reading input from the console and handling exceptions
#include <iostream>
#include <string>
#include <sstream>

// Main function is the entry point of the C++ program
int main() {

    // Creating a string variable 'str' to store the input from the console
    std::string str;

    // Using getline() function to read a single line of input from the console
    getline(std::cin, str);

    // Creating a stringstream object 'ss' to parse the input string 'str'
    std::stringstream ss(str);

    // Declaring and initializing variables 'h' and 'a' to store the first two elements of the input string
    int h, a;
    ss >> h >> a;

    // Initializing a variable 'num' to keep track of the number of steps
    int num = 0;

    // Using a for loop to simulate the given condition
    for (int i = 1; h > 0; i++) {

        // Subtracting 'a' from 'h' in each iteration
        h = h - a;

        // Incrementing the 'num' variable after each successful subtraction
        num++;
    }

    // Printing the final result 'num' to the console
    std::cout << num << std::endl;

    // Ending the program with a comment "