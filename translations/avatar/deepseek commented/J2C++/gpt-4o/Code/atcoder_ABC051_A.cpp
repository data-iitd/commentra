#include <iostream> // Including iostream for input and output operations
#include <sstream> // Including sstream for string stream operations
#include <string> // Including string for string manipulations

int main() { // Main function is the entry point of the program
    std::string a; // Declaring a string variable to hold input
    std::getline(std::cin, a); // Reading a line of input from the user
    for (char &c : a) { // Iterating through each character in the string
        if (c == ',') { // If the character is a comma
            c = ' '; // Replace it with a space
        }
    }
    std::cout << a << std::endl; // Printing the manipulated string
    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
