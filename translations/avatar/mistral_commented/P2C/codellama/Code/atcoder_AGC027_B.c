#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    // Define input variables
    int N, X;
    scanf("%d %d", &N, &X);
    int A[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    // Create a new list S by applying the accumulate function to the list A
    int S[N];
    S[0] = A[0];
    for (int i = 1; i < N; i++) {
        S[i] = S[i - 1] + A[i];
    }

    // Initialize a variable ans with a large value
    int ans = 1000000000;

    // Iterate through each element s in the list S
    for (int k = 1; k <= N / 2; k++) {
        // Calculate the energy consumption E for the current index k
        int E = k * X + 2 * (S[N - 2 * k - 1] - S[N - k - 1]);

        // Update the minimum energy consumption ans if the current energy consumption E is smaller
        if (E < ans) {
            ans = E;
        }
    }

    // Print the result
    printf("%d\n", ans + N * X + 5 * S[N - 1]);

    return 0;
}

