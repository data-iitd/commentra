#include <stdio.h> // Include necessary headers

int main() { // Start the main function
    int N, S; // Declare variables for number of elements and current element
    while (scanf("%d", &N) == 1 && N > 0) { // Read the number of elements (N)
        int M = -1, m = 1001, addup = 0; // Initialize variables for maximum, minimum, and sum
        for (int i = 0; i < N; i++) { // Loop through each element and update the maximum, minimum, and sum
            scanf("%d", &S);
            addup += S;
            if (S > M) M = S;
            if (S < m) m = S;
        }
        printf("%d\n", (addup - M - m) / (N - 2)); // Calculate the average of the remaining numbers
    } // End the loop
    return 0; // Return success
} // End the main function
// <END-OF-CODE>
