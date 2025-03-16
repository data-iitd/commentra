#include <stdio.h>
#include <string.h>

int main()
{
    char s[100]; // Declare a character array to hold the input string
    char t[100]; // Declare a character array to hold the output string
    int length; // Variable to store the length of the string

    scanf("%s", s); // Read a string from the standard input and store it in the array s
    length = strlen(s); // Get the length of the string s

    // The following block of code creates a new string t from the string s
    t[0] = s[0]; // Copy the first character of s to t
    sprintf(t + 1, "%d", length - 2); // Convert the size of string s minus 2 to a string and store it in t
    t[1 + snprintf(NULL, 0, "%d", length - 2)] = s[length - 1]; // Append the last character of s to t
    t[2 + snprintf(NULL, 0, "%d", length - 2)] = '\0'; // Null-terminate the string t

    printf("%s\n", t); // Output the newly created string t to the standard output

    return 0; // Indicate successful termination of the program
}

// <END-OF-CODE>
