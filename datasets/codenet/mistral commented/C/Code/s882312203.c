
#include <stdio.h> // Include the standard input/output library
#include <string.h> // Include the string manipulation library

int main(int argc, char *argv[]) { // The main function is the entry point of the program
    char s[26]; // Declare a character array 's' of size 26 to store the input string

    scanf("%s", s); // Read a string from the standard input and store it in the 's' array

    for (int j = 0; j < strlen(s); j++) { // Iterate through each character in the string 's' using index 'j'
        for (int i = 0; i < strlen(s); i++) { // Nested loop to compare each character with all other characters in the string
            if ((i != j) && (s[i] == s[j])) { // Check if the current characters at indices 'i' and 'j' are the same and not the same index
                puts("no"); // If duplicate characters are found, print 'no' and exit the program
                return 0;
            }
        }
    }

    puts("yes"); // If no duplicate characters are found, print 'yes'

    return 0; // Exit the program with a successful return status
}