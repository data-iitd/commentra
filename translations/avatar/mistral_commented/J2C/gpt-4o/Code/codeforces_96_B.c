#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Initialize variable to read input
    long number;
    scanf("%ld", &number);

    // Initialize variables for answer and current value
    long ans = -1, value = 0;

    // Initialize mask variable for binary number manipulation
    int mask = 2;

    // Main loop to find the answer
    while (value < number) {
        // Convert mask to binary string
        char s[64]; // Buffer to hold binary string (64 bits is enough for long)
        itoa(mask++, s, 2); // Convert integer to binary string

        // Remove leading '1' from the binary string
        memmove(s, s + 1, strlen(s)); // Shift left to remove the first character

        // Count the number of zeros in the binary string
        int zeros = 0;
        for (int i = 0; s[i] != '\0'; i++) {
            if (s[i] == '0') zeros++;
        }

        // If the number of zeros is not equal to the length of the binary string minus the number of zeros, continue to the next iteration
        if (zeros != strlen(s) - zeros) continue;

        // Replace all zeros with '4' and all ones with '7' in the binary string
        for (int i = 0; s[i] != '\0'; i++) {
            if (s[i] == '0') s[i] = '4';
            else if (s[i] == '1') s[i] = '7';
        }

        // Convert the modified binary string back to a long number
        value = strtol(s, NULL, 10);
    }

    // Print the answer
    printf("%ld\n", value);

    return 0;
}

// <END-OF-CODE>
