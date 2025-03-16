#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read an integer from input
int nextInt() {
    int value;
    scanf("%d", &value);
    return value;
}

// Function to read a string from input
void nextStr(char *buffer, int size) {
    scanf("%s", buffer);
}

// Function to count occurrences of colors
void countColors(const char *S, int N, int *nr, int *nb, int *ng) {
    *nr = *nb = *ng = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'R') (*nr)++;
        else if (S[i] == 'B') (*nb)++;
        else if (S[i] == 'G') (*ng)++;
    }
}

<<<<<<< HEAD
// Function to calculate the result
int calculateResult(const char *S, int N) {
    if (N < 4) return 0; // If there are fewer than 4 elements, return 0

    int nr, nb, ng;
    countColors(S, N, &nr, &nb, &ng);
=======
// Function to run the main logic
int run() {
    int N = nextInt(); // Read the number of elements
    if (N == 0) return 0; // Handle case where there are no elements

    char S[100000]; // Assuming a maximum length of 100000 for the string
    nextStr(S, sizeof(S)); // Read the string of colors

    // If there are fewer than 4 elements, output 0
    if (N < 4) {
        printf("0\n");
        return 0;
    }

    int nr, nb, ng;
    countColors(S, N, &nr, &nb, &ng); // Count occurrences of each color
>>>>>>> 98c87cb78a (data updated)

    int same = 0; // Counter for same color combinations

    // Iterate through possible combinations of indices
    for (int a = 1; a < N; a++) {
        int i = 0;
        int j = 1 * a;
        int k = 2 * a;
        if (k >= N) break; // Exit if index exceeds string length
        while (k < N) {
            // Check if the colors at the indices are different
            if (S[i] != S[j] && S[i] != S[k] && S[j] != S[k]) {
                same++; // Increment same color combination counter
            }
<<<<<<< HEAD
            i++;
=======
            i++; // Move to the next index
>>>>>>> 98c87cb78a (data updated)
            j++;
            k++;
        }
    }

    // Calculate total combinations of different colors
    int tot = nr * nb * ng;

<<<<<<< HEAD
    // Return the result by subtracting same combinations from total
    return tot - same;
}

// Main function to execute the program
int main() {
    int N;
    scanf("%d", &N); // Read the number of elements

    char S[100000]; // Assuming a maximum length for the string
    nextStr(S, sizeof(S)); // Read the string of colors

    int result = calculateResult(S, N);
    printf("%d\n", result); // Output the result
=======
    // Output the result by subtracting same combinations from total
    printf("%d\n", tot - same);
>>>>>>> 98c87cb78a (data updated)

    return 0; // Return success
}

<<<<<<< HEAD
=======
// Main function to execute the program
int main() {
    return run(); // Run the program
}

>>>>>>> 98c87cb78a (data updated)
// <END-OF-CODE>
