#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char s[100], t[100]; // Declare two character arrays, s and t, with a maximum size of 100

    scanf("%s", s); // Read a string from the standard input and store it in the array s

    // The following block of code creates a new string t from the string s
    t[0] = s[0]; // Extract the first character from string s and store it in variable t
    int size = strlen(s) - 2; // Calculate the size of string s minus 2
    char sizeStr[20]; // Declare a character array to hold the size as a string
    sprintf(sizeStr, "%d", size); // Convert the size to a string and store it in sizeStr
    strcat(t, sizeStr); // Concatenate the size string to t
    t[strlen(t)] = s[strlen(s) - 1]; // Concatenate the last character of string s to t
    t[strlen(t) + 1] = '\0'; // Null-terminate the new string t

    // Output the newly created string t to the standard output
    printf("%s\n", t);

    return 0; // Indicate successful termination of the program
}
