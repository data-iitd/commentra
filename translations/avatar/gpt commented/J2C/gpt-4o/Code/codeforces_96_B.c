#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Read a long integer from user input
    long number;
    scanf("%ld", &number);
    
    // Initialize variables to store the result and the current value
    long ans = -1, value = 0;
    
    // Initialize a mask variable starting from 2
    int mask = 2;
    
    // Loop until the current value is less than the input number
    while (value < number) {
        // Convert the current mask to a binary string
        char s[64]; // Enough to hold binary representation of an integer
        itoa(mask++, s, 2); // Convert to binary string
        
        // Remove the leading '1' by shifting the string
        memmove(s, s + 1, strlen(s)); // Shift left to remove the first character
        s[strlen(s) - 1] = '\0'; // Null-terminate the string
        
        // Initialize a counter for zeros in the binary string
        int zeros = 0;
        
        // Count the number of '0's in the binary string
        for (int i = 0; s[i] != '\0'; i++) {
            if (s[i] == '0') zeros++;
        }
        
        // If the number of zeros is not equal to the number of ones, skip to the next iteration
        if (zeros != strlen(s) - zeros) continue;
        
        // Replace '0's with '4's and '1's with '7's to form a new number
        for (int i = 0; s[i] != '\0'; i++) {
            if (s[i] == '0') s[i] = '4';
            else if (s[i] == '1') s[i] = '7';
        }
        
        // Parse the modified string as a long integer
        value = strtol(s, NULL, 10);
    }
    
    // Print the final value that meets the condition
    printf("%ld\n", value);
    
    return 0;
}

// <END-OF-CODE>
