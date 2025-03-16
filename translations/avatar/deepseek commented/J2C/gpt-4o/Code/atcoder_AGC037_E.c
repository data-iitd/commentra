#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    int N, K;
    scanf("%d %d", &N, &K); // Read the integers N and K
    char S[1001]; // Assuming the maximum length of S is 1000
    scanf("%s", S); // Read the string S

    int firstTime = 1; // Initialize a flag to check if it's the first time through the loop
    int step = 1; // Initialize the step size

    // Main loop to manipulate the string based on the value of K
    while (K > 0) {
        char T[1001]; // To hold the reversed string
        for (int i = 0; i < N; i++) {
            T[i] = S[N - 1 - i]; // Reverse the string S into T
        }
        T[N] = '\0'; // Null-terminate the reversed string

        char revU[2002]; // To hold the concatenated string S + T
        strcpy(revU, S); // Copy S to revU
        strcat(revU, T); // Concatenate T to revU
        int revULen = strlen(revU);

        char sDash[1001]; // To hold the best substring found
        strcpy(sDash, S); // Initialize sDash with the original string S

        // Iterate over the reversed concatenated string to find the best substring
        for (int i = revULen - N; i >= 0; i -= step) {
            char tmp[1001]; // To hold the substring of length N
            strncpy(tmp, revU + i, N);
            tmp[N] = '\0'; // Null-terminate the substring

            if (strcmp(sDash, tmp) > 0) { // Compare lexicographically
                strcpy(sDash, tmp); // Update sDash if a better substring is found
            } else {
                if (!firstTime) { // If it's not the first time, break the loop
                    break;
                }
            }
        }

        // Check if it's the first time through the loop
        if (firstTime) {
            firstTime = 0; // Set the flag to false
            if (pow(2, K) > N) { // Check the power of 2 of K
                char c = sDash[0]; // Get the first character of sDash
                for (int i = 0; i < N; i++) { // Print the character N times
                    printf("%c", c);
                }
                printf("\n"); // Print a newline
                return 0; // Exit the program
            }
        } else {
            step += step; // Double the step size
        }
        K--; // Decrement K
        strcpy(S, sDash); // Update S with the best substring found
        for (int i = 0; i < N / 2; i++) { // Reverse S
            char temp = S[i];
            S[i] = S[N - 1 - i];
            S[N - 1 - i] = temp;
        }
    }
    printf("%s\n", S); // Print the final reversed string S
    return 0;
}

// <END-OF-CODE>
