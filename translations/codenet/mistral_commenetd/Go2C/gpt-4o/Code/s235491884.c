// Include standard input/output library
#include <stdio.h>
// Include string manipulation library
#include <string.h>

// Main function is the entry point of the program
int main() {
    // Declare a variable 's' of type char array with a size of 100
    char s[100];
    // Use 'scanf' to read a string input from the standard input
    scanf("%s", s);

    // Initialize a variable 'n' to count occurrences of 'o'
    int n = 0;
    // Use 'strlen' to get the length of the string and iterate through it
    for (int i = 0; i < strlen(s); i++) {
        // Increment 'n' for each occurrence of 'o'
        if (s[i] == 'o') {
            n++;
        }
    }

    // Calculate the result by adding 700 to the product of 100 and the number of occurrences of 'o' in the string
    int result = 700 + n * 100;
    // Use 'printf' to print the result to the standard output
    printf("%d\n", result);

    return 0; // Return 0 to indicate successful completion
}

// <END-OF-CODE>
