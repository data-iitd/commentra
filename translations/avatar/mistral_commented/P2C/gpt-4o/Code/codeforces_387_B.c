#include <stdio.h>

void main() {
    // Initialize variables n and m with the given input
    int n, m;
    scanf("%d %d", &n, &m);

    // Initialize arrays round_complexity and george_complexity
    int round_complexity[n];
    int george_complexity[m];

    // Read the complexities for each round
    for (int i = 0; i < n; i++) {
        scanf("%d", &round_complexity[i]);
    }

    // Read George's complexities
    for (int j = 0; j < m; j++) {
        scanf("%d", &george_complexity[j]);
    }

    // Initialize variables i and j to 0
    int i = 0, j = 0;

    // Start the while loop that compares the complexity of each
    // round with George's complexity and moves the pointers accordingly
    while (i < n && j < m) {
        // Increment i if the complexity of the current round is
        // less than or equal to George's complexity at the current j
        if (round_complexity[i] <= george_complexity[j]) {
            i++;
        }
        // Increment j
        j++;
    }

    // Print the final answer
    printf("%d\n", n - i);
}

// <END-OF-CODE>
