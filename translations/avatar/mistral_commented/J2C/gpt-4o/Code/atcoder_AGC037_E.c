#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    // Initialize variables
    int N, K;
    char *S = NULL;
    size_t len = 0;

    // Read the first integer N from the standard input
    scanf("%d", &N);

    // Read the second integer K from the standard input
    scanf("%d", &K);

    // Read the string S from the standard input
    S = (char *)malloc(N + 1);
    scanf("%s", S);

    // Initialize a boolean variable firstTime to true
    int firstTime = 1;

    // Initialize an integer variable step to 1
    int step = 1;

    // Perform the main logic while K is greater than zero
    while (K > 0) {
        // Create a new string T to store the reversed version of S
        char *T = (char *)malloc(N + 1);
        for (int i = 0; i < N; i++) {
            T[i] = S[N - 1 - i];
        }
        T[N] = '\0';

        // Create a new string revU to store the concatenation of S and T reversed
        char *revU = (char *)malloc(2 * N + 1);
        strcpy(revU, S);
        strcat(revU, T);
        for (int i = 0; i < 2 * N; i++) {
            revU[i] = revU[2 * N - 1 - i];
        }
        revU[2 * N] = '\0';

        // Create a string variable sDash to store the current substring of revU
        char *sDash = (char *)malloc(N + 1);
        strcpy(sDash, S);

        // Iterate through the substrings of revU starting from the end of S
        for (int i = N; i >= 0; i -= step) {
            // Get the substring of revU starting from the current index i and of length N
            char tmp[N + 1];
            strncpy(tmp, revU + i, N);
            tmp[N] = '\0';

            // Compare the current substring tmp with the current substring sDash
            if (strcmp(sDash, tmp) > 0) {
                // Update the current substring sDash with the new substring tmp
                strcpy(sDash, tmp);
            } else {
                // If this is not the first iteration, break the loop
                if (!firstTime) {
                    break;
                }
            }
        }

        // Perform some actions based on the comparison of sDash and S
        if (firstTime) {
            firstTime = 0;
            // Check if the length of S raised to the power of K is greater than N
            if (pow(2, K) > N) {
                // Print the first character of S N times and exit the program
                char c = sDash[0];
                for (int i = 0; i < N; i++) {
                    printf("%c", c);
                }
                printf("\n");
                free(S);
                free(T);
                free(revU);
                free(sDash);
                return 0;
            }
        } else {
            // Update the value of step
            step += step;
        }

        // Decrement the value of K
        K--;

        // Update the value of S to be the current substring sDash reversed
        free(S);
        S = (char *)malloc(N + 1);
        for (int i = 0; i < N; i++) {
            S[i] = sDash[N - 1 - i];
        }
        S[N] = '\0';

        // Free allocated memory
        free(T);
        free(revU);
        free(sDash);
    }

    // Print the reversed version of the final string S
    for (int i = N - 1; i >= 0; i--) {
        printf("%c", S[i]);
    }
    printf("\n");

    // Free allocated memory
    free(S);
    return 0;
}

// <END-OF-CODE>
