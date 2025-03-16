#include <stdio.h>
#include <stdlib.h>

// Function to perform the main logic of the program
void main() {

    // Initialize variables n and m with the given input
    int n, m;
    scanf("%d %d", &n, &m);

    // Initialize lists round_complexity and george_complexity
    // with the given input
    int *round_complexity = (int *)malloc(n * sizeof(int));
    int *george_complexity = (int *)malloc(m * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &round_complexity[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &george_complexity[i]);
    }

    // Initialize variables i and j to 0
    int i = 0, j = 0;

    // Start the while loop that compares the complexity of each
    // round with George's complexity and moves the pointers accordingly
    while (i < n && j < m) {

        // Increment i if the complexity of the current round is
        // less than or equal to George's complexity at the current j
        i += 1 if (round_complexity[i] <= george_complexity[j]) else 0;

        // Increment j
        j += 1;
    }

    // Print the final answer
    printf("%d\n", n - i);
}

