#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Declare variables
    long a;
    char b[100]; // Assuming the input string will not exceed 99 characters
    char bStr[100]; // To hold the integer representation of b
    int bInt;
    
    // Read a long integer value from the user
    scanf("%ld", &a);
    
    // Read a string value from the user
    scanf("%s", b);
    
    // Initialize an index for bStr
    int j = 0;
    
    // Get the length of the string b
    int length = strlen(b);
    
    // Loop through each character in the string b
    for (int i = 0; i < length; i++) {
        // If the character is not a '.', append it to bStr
        if (b[i] != '.') {
            bStr[j++] = b[i];
        }
    }
    
    // Null-terminate the bStr string
    bStr[j] = '\0';
    
    // Convert the built string (bStr) to an integer
    bInt = atoi(bStr);
    
    // Calculate the result by multiplying 'a' with 'bInt' and dividing by 100
    long result = (a * bInt) / 100;
    
    // Print the result to the console
    printf("%ld\n", result);
    
    return 0;
}

// <END-OF-CODE>
