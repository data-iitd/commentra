#include <stdio.h>
#include <string.h> // Include the string library for string manipulation functions

int main()
{
    char mes[101]; // Declare a character array to store the input string
    scanf("%s", mes); // Read a string input from the user and store it in 'mes'

    # Calculate the length of the string excluding the first and last character
    length = len(mes) - 2

    # Print the first character, the calculated length, and the last character of the string
    print(mes[0], length, mes[len(mes) - 1])

    return 0; // Return 0 to indicate successful execution
}

