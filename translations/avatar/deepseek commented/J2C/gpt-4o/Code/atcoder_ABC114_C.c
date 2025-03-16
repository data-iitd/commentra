#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int contains_digits(const char *s) {
    return strchr(s, '3') && strchr(s, '5') && strchr(s, '7');
}

int main() {
    long N;
    printf("Enter an integer N: ");
    scanf("%ld", &N); // Reading an integer N from the user

    long i = 357; // Initializing the starting number
    int c = 0; // Initializing the counter for valid numbers

    // Main loop to find numbers containing '3', '5', and '7'
    while (i <= N) {
        char s[20]; // Buffer to hold the string representation of the number
        sprintf(s, "%ld", i); // Converting the current number to a string

        if (contains_digits(s)) {
            c++; // Incrementing the counter if all required digits are present
        }

        // Building a new number by replacing the last digit
        char sb[20]; // Buffer for the new number
        int f = 0; // Flag to check if a replacement was made
        int len = strlen(s);

        for (int j = 0; j < len; j++) {
            char a = s[len - 1 - j];
            if (f) {
                sb[j] = a; // Appending characters after the replacement
            } else {
                if (a == '3') {
                    sb[j] = '5'; // Replacing '3' with '5'
                    f = 1;
                } else if (a == '5') {
                    sb[j] = '7'; // Replacing '5' with '7'
                    f = 1;
                } else {
                    sb[j] = '3'; // Replacing other digits with '3'
                }
            }
        }
        if (!f) sb[len] = '3'; // Appending '3' if no replacements were made
        sb[len + (f ? 0 : 1)] = '\0'; // Null-terminate the string

        // Reversing the new number and converting it back to a long
        long new_i = 0;
        for (int j = strlen(sb) - 1; j >= 0; j--) {
            new_i = new_i * 10 + (sb[j] - '0');
        }
        i = new_i; // Update i with the new number
    }

    // Output the result
    printf("%d\n", c); // Printing the count of valid numbers
    return 0;
}

// <END-OF-CODE>
