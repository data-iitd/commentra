
#include <stdio.h> // Include the standard input/output library

int main() {
    // Create a variable to store the input number
    long number;
    
    // Read a long integer from user input
    scanf("%ld", &number);
    
    // Initialize variables to store the result and the current value
    long ans = -1, value = 0;
    
    // Initialize a mask variable starting from 2
    int mask = 2;
    
    // Loop until the current value is less than the input number
    while (value < number) {
        // Convert the current mask to a binary string and remove the leading '1'
        char s[64]; // Define a character array to store the binary string
        sprintf(s, "%d", mask++); // Convert the mask to a string and store it in s
        char *p = s; // Initialize a pointer to the beginning of the string
        while (*p == '1') p++; // Skip over the leading '1's
        
        // Count the number of '0's in the binary string
        int zeros = 0;
        while (*p!= '\0') {
            if (*p == '0') zeros++;
            p++;
        }
        
        // If the number of zeros is not equal to the number of ones, skip to the next iteration
        if (zeros!= strlen(s) - zeros) continue;
        
        // Replace '0's with '4's and '1's with '7's to form a new number
        for (int i = 0; i < strlen(s); i++) {
            if (s[i] == '0') s[i] = '4';
            else if (s[i] == '1') s[i] = '7';
        }
        
        // Parse the modified string as a long integer
        sscanf(s, "%ld", &value);
    }
    
    // Print the final value that meets the condition
    printf("%ld\n", value);
    
    // End the program
    return 0;
}
