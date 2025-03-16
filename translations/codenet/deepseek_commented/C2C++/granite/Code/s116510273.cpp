
#include <iostream>
#include <string> // Include the string library for string manipulation functions

int main()
{
    std::string mes; // Declare a string variable to store the input string
    std::cin >> mes; // Read a string input from the user and store it in'mes'

    // Calculate the length of the string excluding the first and last character
    size_t length = mes.length() - 2;

    // Print the first character, the calculated length, and the last character of the string
    std::cout << mes[0] << length << mes[mes.length() - 1] << std::endl;

    return 0; // Return 0 to indicate successful execution
}

