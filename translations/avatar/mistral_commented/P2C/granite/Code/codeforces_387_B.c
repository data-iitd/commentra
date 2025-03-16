
#include <stdio.h>

// Function to perform the main logic of the program
void main() {

    // Initialize variables n and m with the given input
    int n, m;
    scanf("%d %d", &n, &m);

    // Initialize arrays round_complexity and george_complexity
    // with the given input
    int round_complexity[n], george_complexity[m];
    for (int i = 0; i < n; i++) {
        scanf("%d", &round_complexity[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &george_complexity[i]);
    }

    // Initialize variables i and j to 0
    int i = j = 0;

    // Start the while loop that compares the complexity of each
    // round with George's complexity and moves the pointers accordingly
    while (i < n && j < m) {

        // Increment i if the complexity of the current round is
        // less than or equal to George's complexity at the current j
        i += (round_complexity[i] <= george_complexity[j])? 1 : 0;

        // Increment j
        j += 1;
    }

    // Print the final answer
    printf("%d\n", n - i);
}

// End of code
