// Include standard input-output library
#include <stdio.h>
#include <string.h>

int main() {
    // Declare a variable named S of type char array (string)
    char S[100];

    // Read a string input from the standard input using scanf
    scanf("%s", S);

    // Switch statement to check the value of the string S and print the corresponding weather condition
    if (strcmp(S, "Sunny") == 0) { // If the input string is "Sunny"
        printf("Cloudy\n"); // Print "Cloudy" as the output
    } else if (strcmp(S, "Cloudy") == 0) { // If the input string is "Cloudy"
        printf("Rainy\n"); // Print "Rainy" as the output
    } else if (strcmp(S, "Rainy") == 0) { // If the input string is "Rainy"
        printf("Sunny\n"); // Print "Sunny" as the output
    }

    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
