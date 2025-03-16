#include <stdio.h>
#include <stdlib.h>

int main() {
    // Taking input for number of test cases and time limit
    int n, t;
    scanf("%d %d", &n, &t);

    // Initializing an array to store the jumps
    int *s = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &s[i]);
    }

    // Initializing the current cell position to 0
    int current_cell = 0;

    // Main logic of the program starts here
    while (current_cell < t) {
        // Incrementing the current cell position by the jump from the previous cell
        current_cell += s[current_cell];

        // Checking if the current cell position is equal to the target position
        if (current_cell == t) {
            // If yes, then print "YES" and exit the program
            printf("YES\n");
            free(s);
            return 0;
        }
    }

    // If the loop terminates without finding the target position, then print "NO"
    printf("NO\n");
    free(s);
    return 0;
}

// <END-OF-CODE>
