#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    long a; // Declaring long variable 'a'
    scanf("%ld", &a); // Reading long value from the console and assigning it to 'a'

    char b[100]; // Declaring a character array 'b' to hold the input string
    scanf("%s", b); // Reading string value from the console and assigning it to 'b'

    char bStr[100]; // Declaring a character array 'bStr' to hold the processed string
    int j = 0; // Index for bStr

    // Loop to iterate through each character in 'b'
    for (int i = 0; i < strlen(b); i++) {
        // If current character is not '.', add it to 'bStr'
        if (b[i] != '.') {
            bStr[j++] = b[i]; // Add character to bStr and increment index
        }
    }
    bStr[j] = '\0'; // Null-terminate the string

    int bInt; // Declaring integer variable 'bInt'
    bInt = atoi(bStr); // Converting string 'bStr' to integer and assigning it to 'bInt'

    long result; // Declaring long variable 'result'
    result = (a * bInt) / 100; // Multiplying 'a' with 'bInt', then dividing the result by 100 and assigning it to 'result'

    printf("%ld\n", result); // Printing the value of 'result' to the console

    return 0; // Return statement
}

// <END-OF-CODE>
