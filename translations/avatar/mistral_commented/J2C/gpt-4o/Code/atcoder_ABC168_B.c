#include <stdio.h>  // Include standard input/output library
#include <string.h> // Include string library for string manipulation

int main() { // Define the main function as the entry point of the program
    int K; // Declare an integer variable K
    char S[100]; // Declare a character array (string) S with a maximum length of 99 characters (+1 for null terminator)

    scanf("%d", &K); // Read the integer K from the input
    scanf("%s", S); // Read the string S from the input

    if (strlen(S) <= K) { // Check if the length of the string S is less than or equal to K
        printf("%s\n", S); // If true, print the string S
    } else { // If false
        for (int i = 0; i < K; i++) { // Loop to print the first K characters of S
            putchar(S[i]); // Print each character
        }
        printf("...\n"); // Print "..." after the first K characters
    }

    return 0; // Return 0 to indicate successful completion
}

// <END-OF-CODE>
