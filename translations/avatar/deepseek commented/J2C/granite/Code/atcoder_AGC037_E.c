
#include <stdio.h> // Include the standard input/output library
#include <string.h> // Include the string library

int main() {
    int N, K; // Declare the variables N and K
    char S[100001]; // Declare the character array S with a maximum length of 100000
    scanf("%d %d", &N, &K); // Read the integers N and K from the input
    scanf("%s", S); // Read the string S from the input

    // Main loop to manipulate the string based on the value of K
    while (K > 0) {
        char T[100001]; // Declare the character array T with a maximum length of 100000
        char revU[200001]; // Declare the character array revU with a maximum length of 200000
        int i; // Declare the variable i

        // Reverse the string S and store it in the array T
        for (i = 0; i < N; i++) {
            T[i] = S[N - 1 - i];
        }
        T[N] = '\0'; // Null-terminate the string T

        // Concatenate the string S with its reverse and store it in the array revU
        strcpy(revU, S);
        strcat(revU, T);

        // Reverse the concatenated string revU
        for (i = 0; i < 2 * N - 1; i++) {
            revU[i] = revU[2 * N - 2 - i];
        }
        revU[2 * N] = '\0'; // Null-terminate the string revU

        // Find the best substring of length N in the reversed concatenated string revU
        char sDash[100001]; // Declare the character array sDash with a maximum length of 100000
        strcpy(sDash, S); // Initialize sDash with the original string S
        for (i = N; i >= 0; i -= (i + 1) / 2) {
            char tmp[100001]; // Declare the character array tmp with a maximum length of 100000
            strncpy(tmp, revU + i, N); // Get a substring of length N from revU starting at index i
            tmp[N] = '\0'; // Null-terminate the string tmp
            if (strcmp(sDash, tmp) > 0) { // Compare lexicographically
                strcpy(sDash, tmp); // Update sDash if a better substring is found
            } else {
                break; // If a better substring is not found, break the loop
            }
        }

        // Check if it's the first time through the loop
        if (K == 1) {
            if (pow(2, K) > N) { // Check the power of 2 of K
                for (i = 0; i < N; i++) { // Print the first character of sDash N times
                    putchar(sDash[0]);
                }
                putchar('\n'); // Print a newline
                return 0; // Exit the program
            }
        }

        // Update S with the best substring found
        strcpy(S, sDash);

        // Reverse S
        for (i = 0; i < N / 2; i++) {
            char tmp = S[i];
            S[i] = S[N - 1 - i];
            S[N - 1 - i] = tmp;
        }

        K--; // Decrement K
    }

    // Print the final reversed string S
    for (i = 0; i < N; i++) {
        putchar(S[N - 1 - i]);
    }
    putchar('\n'); // Print a newline

    return 0; // End the program
}

