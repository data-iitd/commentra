#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N); // Read the first integer from input

    if (N < 4) { // Check if N is less than 4
        printf("0\n"); // Print 0 if N is less than 4
        return 0; // Return 0
    }

    char S[1000000]; // Assuming a maximum length for the string S
    scanf("%s", S); // Read the string S

    int nr = 0, nb = 0, ng = 0; // Declare and initialize variables for red, blue, and green balls

    for (int i = 0; i < N; i++) { // Iterate through each character in the string S
        if (S[i] == 'R') { // If the character is 'R'
            nr++; // Increment the nr counter
        } else if (S[i] == 'B') { // If the character is 'B'
            nb++; // Increment the nb counter
        } else if (S[i] == 'G') { // If the character is 'G'
            ng++; // Increment the ng counter
        }
    }

    int same = 0; // Initialize a counter for the number of same-colored groups of three balls

    // Outer loop
    for (int a = 1; a < N; a++) { // Iterate through each index a from 1 to N-1
        int i = 0; // Initialize index i to 0
        int j = 1 * a; // Initialize index j to a multiplied by 1
        int k = 2 * a; // Initialize index k to a multiplied by 2

        // Inner loop
        while (k < N) { // Iterate through each index k from a*2 to N-1
            // Check if the balls at indices i, j, and k have different colors
            if (S[i] != S[j] && S[i] != S[k] && S[j] != S[k]) {
                same++; // If so, increment the same counter
            }

            // Update indices
            i += 1; // Increment index i
            j += 1; // Increment index j
            k += 1; // Increment index k
        }
    }

    int tot = nr * nb * ng; // Calculate the total number of balls

    printf("%d\n", tot - same); // Print the result, which is the total number of balls minus the number of same-colored groups of three balls

    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
