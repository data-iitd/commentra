#include <stdio.h>  // Include the standard input/output library
#include <string.h> // Include the string library for string manipulation

int main()
{
    char s[100], t[100]; // Declare two character arrays: s for input and t for the output format
    int i; // Declare an integer variable for looping

    scanf("%s", s); // Read a string input from the user and store it in s

    // Construct the abbreviated version of the string
    t[0] = s[0]; // Start with the first character of the input string
    t[1] = '\0'; // Null-terminate the string
    char size_str[10]; // Declare a character array to hold the size as a string
    sprintf(size_str, "%d", strlen(s) - 2); // Convert the size to a string and store it in size_str
    strcat(t, size_str); // Append the size string to t
    strcat(t, &s[strlen(s) - 1]); // Append the last character of the input string to t

    printf("%s\n", t); // Output the abbreviated string

    return 0; // Return 0 to indicate successful completion of the program
}
