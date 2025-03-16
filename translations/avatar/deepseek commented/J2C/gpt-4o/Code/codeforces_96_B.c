#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Read a long integer input from the user
    long number;
    scanf("%ld", &number);
    
    // Initialize two variables, ans and value, to -1 and 0, respectively
    long ans = -1, value = 0;
    
    // Set a mask variable to 2
    int mask = 2;
    
    // The code enters a while loop that continues as long as value is less than the input number
    while (value < number) {
        // Convert the mask value to a binary string
        char s[64]; // Enough to hold binary representation of an integer
        itoa(mask++, s, 2); // Convert to binary string
        
        // Remove the first character (the '1' in binary representation)
        memmove(s, s + 1, strlen(s)); // Shift left to remove the first character
        
        // Count the number of zeros in the binary string
        int zeros = 0;
        for (int i = 0; s[i] != '\0'; i++) {
            if (s[i] == '0') {
                zeros++;
            }
        }
        
        // If the number of zeros is not equal to the number of ones, skip the rest of the loop
        if (zeros != strlen(s) - zeros) {
            continue;
        }
        
        // Replace all zeros with 4 and all ones with 7 in the binary string
        for (int i = 0; s[i] != '\0'; i++) {
            if (s[i] == '0') {
                s[i] = '4';
            } else {
                s[i] = '7';
            }
        }
        
        // Convert the modified string back to a long integer
        value = strtol(s, NULL, 10);
    }
    
    // Print the value variable
    printf("%ld\n", value);
    
    return 0;
}

// <END-OF-CODE>
