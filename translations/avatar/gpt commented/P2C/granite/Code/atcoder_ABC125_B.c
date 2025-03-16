
#include <stdio.h>

int main() {
    // Read the number of elements
    int N;
    scanf("%d", &N);

    // Read the values into an array
    int V[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &V[i]);
    }

    // Read the costs into an array
    int C[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &C[i]);
    }

    // Initialize a variable to hold the total profit
    int ans = 0;

    // Initialize variables to hold current value and cost
    int X = 0;
    int Y = 0;

    // Iterate through each item
    for (int i = 0; i < N; i++) {
        // Check if the value is greater than the cost
        if (V[i] - C[i] > 0) {
            // Assign the current value and cost to X and Y
            X = V[i];
            Y = C[i];
            // Calculate the profit and add it to the total profit
            ans += X - Y;
        }
    }

    // Print the total profit
    printf("%d\n", ans);

    return 0;
}
