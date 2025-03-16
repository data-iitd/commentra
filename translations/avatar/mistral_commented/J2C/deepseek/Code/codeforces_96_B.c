#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Initialize variables for input and output
    long number, ans = -1, value = 0;

    // Read a long number as input
    scanf("%ld", &number);

    // Initialize mask variable for binary number manipulation
    int mask = 2;

    // Main loop to find the answer
    while (value < number) {
        // Convert mask to binary string and remove leading '1'
        char s[32];
        sprintf(s, "%b", mask++);
        int len = strlen(s);
        for (int i = 0; i < len; i++) {
            if (s[i] == '1') {
                memmove(&s[i], &s[i + 1], len - i);
                len--;
                i--;
            }
        }

        // Count the number of zeros in the binary string
        int zeros = 0;
        for (int i = 0; i < len; i++) {
            if (s[i] == '0') zeros++;
        }

        // If the number of zeros is not equal to the length of the binary string minus the number of zeros, continue to the next iteration
        if (zeros != len - zeros) continue;

        // Replace all zeros with '4' and all ones with '7' in the binary string
        for (int i = 0; i < len; i++) {
            if (s[i] == '0') s[i] = '4';
            else if (s[i] == '1') s[i] = '7';
        }

        // Convert the modified binary string back to a long number and update the value variable
        value = atol(s);
    }

    // Print the answer
    printf("%ld\n", value);

    return 0;
}
