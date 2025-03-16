#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    // Create a Scanner object to read input from the console
    // Create a Scanner object to read input from the console
    int N, K;
    char *sDash;
    int step = 1;
    int firstTime = 1;
    char *S;
    char *T;
    char *revU;
    int i;
    int j;
    int tmp;
    int c;

    // Read the integer N (length of the string) and K (number of operations)
    scanf("%d %d", &N, &K);

    // Read the initial string and create a StringBuilder for manipulation
    S = (char *)malloc(N + 1);
    scanf("%s", S);

    // Loop until K operations are performed
    while (K > 0) {
        // Create a reversed copy of the current string S
        T = (char *)malloc(N + 1);
        for (i = 0; i < N; i++) {
            T[i] = S[N - i - 1];
        }
        T[N] = '\0';

        // Create a new StringBuilder that combines S and its reverse, then reverse it
        revU = (char *)malloc(2 * N + 1);
        for (i = 0; i < N; i++) {
            revU[i] = S[i];
        }
        for (i = 0; i < N; i++) {
            revU[i + N] = T[i];
        }
        revU[2 * N] = '\0';

        // Initialize a variable to keep track of the best string found so far
        sDash = (char *)malloc(N + 1);
        strcpy(sDash, S);

        // Iterate through the string revU to find the lexicographically smallest substring
        for (i = N; i >= 0; i -= step) {
            // Extract a substring from revU
            tmp = i + N;
            for (j = i; j < tmp; j++) {
                sDash[j - i] = revU[j];
            }
            sDash[tmp - i] = '\0';

            // Compare and update sDash if a smaller substring is found
            if (strcmp(sDash, S) > 0) {
                strcpy(sDash, S);
            } else {
                // If we are not in the first iteration, break the loop
                if (!firstTime) {
                    break;
                }
            }
        }

        // If this is the first iteration, check if we can print a uniform string
        if (firstTime) {
            firstTime = 0;
            // If 2^K is greater than N, print the first character of sDash N times
            if (pow(2, K) > N) {
                c = sDash[0];
                for (i = 0; i < N; i++) {
                    printf("%c", c);
                }
                printf("\n");
                exit(0);
            }
        } else {
            // Increase the step size for the next iteration
            step += step;
        }

        // Decrement K and update S for the next operation
        K--;
        strcpy(S, sDash);
    }

    // Print the final result after all operations
    printf("%s\n", S);

    // Close the scanner to free up resources
    free(S);
    free(T);
    free(revU);
    free(sDash);

    return 0;
}

