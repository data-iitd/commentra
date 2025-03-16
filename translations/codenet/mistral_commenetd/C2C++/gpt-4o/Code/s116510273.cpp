#include <iostream>
#include <string>

int main()
{
    std::string mes; // Declare a string variable 'mes' to store the input string

    std::cin >> mes; // Read a string from the standard input and store it in 'mes'

    // Logic starts here

    std::cout << mes[0] << mes.length() - 2 << mes[mes.length() - 1] << std::endl; // Print the first character, length - 2 and last character of the input string

    return 0; // Indicate successful termination of the program
}

// <END-OF-CODE>
