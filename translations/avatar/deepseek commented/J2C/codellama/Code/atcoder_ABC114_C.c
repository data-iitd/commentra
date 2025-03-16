#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N; // Declaring an integer N to read input
    long i = 357; // Initializing the starting number
    int c = 0; // Initializing the counter for valid numbers

    // Reading an integer N from the user
    scanf("%d", &N);

    // Main loop to find numbers containing '3', '5', and '7'
    while (i <= N) {
        char s[100]; // Declaring a character array to store the current number
        sprintf(s, "%ld", i); // Converting the current number to a string
        int f = 0; // Initializing a flag to check if all required digits are present

        // Checking if all required digits are present
        if (strstr(s, "3") && strstr(s, "5") && strstr(s, "7")) {
            f = 1; // Setting the flag if all required digits are present
        }

        // Building a new number by replacing the last digit
        char sb[100]; // Declaring a character array to store the new number
        int j = 0; // Initializing a counter for the new number
        for (int k = strlen(s) - 1; k >= 0; k--) {
            if (f) {
                sb[j++] = s[k]; // Appending characters after the replacement
            } else {
                if (s[k] == '3') {
                    sb[j++] = '5'; // Replacing '3' with '5'
                    f = 1;
                } else if (s[k] == '5') {
                    sb[j++] = '7'; // Replacing '5' with '7'
                    f = 1;
                } else {
                    sb[j++] = '3'; // Replacing other digits with '3'
                }
            }
        }
        if (!f) sb[j++] = '3'; // Appending '3' if no replacements were made
        sb[j] = '\0'; // Terminating the new number

        // Reversing the new number and converting it back to a long
        char sb2[100]; // Declaring a character array to store the reversed number
        for (int k = 0; k < j; k++) {
            sb2[k] = sb[j - k - 1]; // Reversing the new number
        }
        sb2[j] = '\0'; // Terminating the reversed number
        i = atol(sb2); // Converting the reversed number back to a long
        c++; // Incrementing the counter if all required digits are present
    }

    // Output the result
    printf("%d\n", c); // Printing the count of valid numbers

    return 0;
}

