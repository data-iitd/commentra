
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Initialize scanner to read input from standard input
    scanf("%ld", &number);

    // Initialize variables for answer and current value
    long ans = -1, value = 0;

    // Initialize mask variable for binary number manipulation
    int mask = 2;

    // Main loop to find the answer
    while (value < number) {
        // Convert mask to binary string and remove leading '1'
        char s[1000];
        sprintf(s, "%d", mask++);
        s[0] = '\0';
        strstr(s, "1");

        // Count the number of zeros in the binary string
        int zeros = 0;
        for (int i = 0; i < strlen(s); i++)
            if (s[i] == '0') zeros++;

        // If the number of zeros is not equal to the length of the binary string minus the number of zeros, continue to the next iteration
        if (zeros!= strlen(s) - zeros) continue;

        // Replace all zeros with '4' and all ones with '7' in the binary string
        for (int i = 0; i < strlen(s); i++)
            if (s[i] == '0') s[i] = '4';
            else s[i] = '7';

        // Convert the modified binary string back to a long number and update the value variable
        value = atol(s);
    }

    // Print the answer
    printf("%ld", value);

    return 0;
}

