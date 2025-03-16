#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Create a variable to store the input number
    long number;
    
    // Read the input number from the user
    scanf("%ld", &number);
    
    // Initialize variables to store the result and the current value
    long ans = -1, value = 0;
    
    // Initialize a mask variable starting from 2
    int mask = 2;
    
    // Loop until the current value is less than the input number
    while (value < number) {
        // Convert the current mask to a binary string and remove the leading '1'
        char s[32];
        sprintf(s, "%d", mask++);
        s[0] = '0';
        
        // Initialize a counter for zeros in the binary string
        int zeros = 0;
        
        // Count the number of '0's in the binary string
        for (int i = 1; i < strlen(s); i++) {
            if (s[i] == '0') zeros++;
        }
        
        // If the number of zeros is not equal to the number of ones, skip to the next iteration
        if (zeros != strlen(s) - zeros) continue;
        
        // Replace '0's with '4's and '1's with '7's to form a new number
        for (int i = 1; i < strlen(s); i++) {
            if (s[i] == '0') s[i] = '4';
            else s[i] = '7';
        }
        
        // Parse the modified string as a long integer
        value = strtol(s, NULL, 10);
    }
    
    // Print the final value that meets the condition
    printf("%ld\n", value);
    
    return 0;
}

