#include <iostream>
#include <cstring>

int main()
{
    // Declare a character array to hold the input string with a maximum length of 100 characters
    char mes[101];

    // Read a string from standard input and store it in the 'mes' array
    std::cin >> mes;

    // Print the first character of the string, the length of the string minus 2, and the last character of the string
    std::cout << mes[0] << strlen(mes) - 2 << mes[strlen(mes) - 1] << std::endl;

    // Return 0 to indicate successful completion of the program
    return 0;
}

// <END-OF-CODE>
