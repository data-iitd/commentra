#include <stdio.h>
#include <string.h>

// Include necessary libraries for standard input/output and string manipulation

int main()
{
    char mes[101]; // Declare a character array 'mes' of size 101 to store the input string

    scanf("%s", mes); // Read a string from the standard input and store it in 'mes' array

    // Logic starts here

    printf("%c%lu%c\n", mes[0], strlen(mes)-2, mes[strlen(mes)-1]); // Print the first character, length - 2 and last character of the input string

    return 0; // Indicate successful termination of the program
}
