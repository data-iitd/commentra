#include <stdio.h>

#define MAX_N 1000 // Assuming a maximum value for N

// Initialize variables
int N, K;
int d, a;
int as[MAX_N + 1]; // Array to store the frequency of each number

int main() {
    // Read input values for N and K
    scanf("%d %d", &N, &K);

    // Initialize all elements of the array with zero frequency
    for (int i = 1; i <= N; i++) {
        as[i] = 0;
    }

    // Read K queries and process them
    for (int i = 0; i < K; i++) {
        // Read the length of the query
        scanf("%d", &d);

        // Read the numbers in the query and increment their frequency in the array
        for (int j = 0; j < d; j++) {
            scanf("%d", &a);
            as[a]++;
        }
    }

    // Initialize a variable named ans to store the answer
    int ans = 0;

    // Iterate through the array and check if the frequency of any number is zero
    // If yes, increment the value of ans
    for (int i = 1; i <= N; i++) {
        if (as[i] == 0) {
            ans++;
        }
    }

    // Print the final answer
    printf("%d\n", ans);

    // End of the code
    return 0;
}
