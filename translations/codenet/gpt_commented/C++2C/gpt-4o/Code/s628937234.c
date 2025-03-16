#include <stdio.h>  // Include the standard I/O library for input and output
#include <string.h> // Include the string library for string manipulation

int main()
{
    char s[100]; // Declare a character array for input (assuming a maximum length of 99 characters)
    char t[100]; // Declare a character array for the output format

    scanf("%s", s); // Read a string input from the user and store it in s

    // Construct the abbreviated version of the string
    int len = strlen(s); // Get the length of the input string
<<<<<<< HEAD
    if (len > 2) { // Check if the string length is greater than 2
        sprintf(t, "%c%d%c", s[0], len - 2, s[len - 1]); // Format the abbreviated string
    } else {
        strcpy(t, s); // If the string length is 2 or less, copy it directly to t
=======
    if (len > 2) {
        t[0] = s[0]; // Start with the first character of the input string
        sprintf(t + 1, "%d", len - 2); // Append the number of characters between the first and last characters
        t[1 + snprintf(NULL, 0, "%d", len - 2)] = s[len - 1]; // Append the last character of the input string
        t[2 + snprintf(NULL, 0, "%d", len - 2)] = '\0'; // Null-terminate the output string
    } else {
        strcpy(t, s); // If the string is too short, just copy it to t
>>>>>>> 98c87cb78a (data updated)
    }

    printf("%s\n", t); // Output the abbreviated string

    return 0; // Return 0 to indicate successful completion of the program
}

// <END-OF-CODE>
