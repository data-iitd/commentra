

#include <stdio.h>

int main() {
    // Initialize variables for answer and current value
    long long ans = -1, value = 0;

    // Initialize mask variable for binary number manipulation
    int mask = 2;

    // Main loop to find the answer
    while (value < number) {
        // Convert mask to binary string and remove leading '1'
        char s[64];
        sprintf(s, "%d", mask++);
        char *p = s;
        while (*p == '1') p++;

        // Count the number of zeros in the binary string
        int zeros = 0;
        while (*p) {
            if (*p == '0') zeros++;
            p++;
        }

        // If the number of zeros is not equal to the length of the binary string minus the number of zeros, continue to the next iteration
        if (zeros!= strlen(s) - zeros) continue;

        // Replace all zeros with '4' and all ones with '7' in the binary string
        for (int i = 0; s[i]; i++) {
            if (s[i] == '0') s[i] = '4';
            else if (s[i] == '1') s[i] = '7';
        }

        // Convert the modified binary string back to a long number and update the value variable
        sscanf(s, "%lld", &value);
    }

    // Print the answer
    printf("%lld\n", value);

    return 0;
}

This code should perform the same functionality as the Java code. Let me know if you need any further clarification or modification.