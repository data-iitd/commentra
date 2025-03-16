#include <iostream> // Include the iostream library for input/output
#include <cstring>  // Include the cstring library for string manipulation

int main() // Declare the main function
{
    char str[30]; // Declare a character array str of size 30

    // Get a string input from the user using cin and store it in str array
    std::cin.getline(str, 30);

    // Assign a space character to the 6th index (index starts from 0) and 14th index of the string str
    str[5] = ' ';
    str[13] = ' ';

    // Print the modified string using cout
    std::cout << str << std::endl;

    // Return 0 to indicate successful execution of the program
    return 0;
}

// <END-OF-CODE>
