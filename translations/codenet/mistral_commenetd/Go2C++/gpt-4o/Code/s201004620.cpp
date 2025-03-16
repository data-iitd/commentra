// Include necessary header files
#include <iostream>
#include <string>

// Entry point of the program
int main() {
    // Declare a variable named S of type string
    std::string S;

    // Read a string input from the standard input
    std::cin >> S;

    // Switch statement to check the value of the string S and print the corresponding weather condition
    if (S == "Sunny") { // If the input string is "Sunny"
        std::cout << "Cloudy" << std::endl; // Print "Cloudy" as the output
    } else if (S == "Cloudy") { // If the input string is "Cloudy"
        std::cout << "Rainy" << std::endl; // Print "Rainy" as the output
    } else if (S == "Rainy") { // If the input string is "Rainy"
        std::cout << "Sunny" << std::endl; // Print "Sunny" as the output
    }

    return 0; // End of the program
}

// <END-OF-CODE>
