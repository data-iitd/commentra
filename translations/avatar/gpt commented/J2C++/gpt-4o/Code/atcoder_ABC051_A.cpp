#include <iostream> // Including iostream for input and output
#include <string>   // Including string for string manipulation
#include <sstream>  // Including sstream for string stream
#include <algorithm> // Including algorithm for replace functionality

int main() {
    // Creating a string to hold the input
    std::string a;
    
    // Reading a line of input from the user
    std::getline(std::cin, a);
    
    // Replacing commas in the input string with spaces
    std::replace(a.begin(), a.end(), ',', ' ');
    
    // Printing the modified string to the console
    std::cout << a << std::endl;

    return 0;
}

// <END-OF-CODE>
