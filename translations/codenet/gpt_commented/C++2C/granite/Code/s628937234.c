
#include <stdio.h> // Include the standard input/output library
#include <string.h> // Include the string library for string manipulation

int main()
{
    char s[100], t[100]; // Declare two character arrays: s for input and t for the output format

    scanf("%s", s); // Read a string input from the user and store it in s

    // Construct the abbreviated version of the string
    t[0] = s[0]; // Start with the first character of the input string
    sprintf(t + 1, "%d", strlen(s) - 2); // Append the number of characters between the first and last characters
    t[strlen(s) - 1] = s[strlen(s) - 1]; // Append the last character of the input string

    printf("%s\n", t); // Output the abbreviated string

    return 0; // Return 0 to indicate successful completion of the program
}
