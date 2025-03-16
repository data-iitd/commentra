#include <stdio.h>
#include <stdlib.h>

// Define a function to read multiple integers from input
int *R(int *n) {
    int *arr = (int *)malloc(sizeof(int) * *n);
    for (int i = 0; i < *n; i++) {
        scanf("%d", &arr[i]);
    }
    return arr;
}

int main() {
    // Read the values of n (total positions), m (number of obstacles), s (starting position), and f (finishing position)
    int n, m, s, f;
    scanf("%d %d %d %d", &n, &m, &s, &f);

    // Determine the direction of movement based on the starting and finishing positions
    int d;
    char c;
    if (s < f) {
        d = 1;  // Move right
        c = 'R';  // Character representing right movement
    } else {
        d = -1;  // Move left
        c = 'L';  // Character representing left movement
    }

    // Initialize the result string to store the path taken
    char *res = (char *)malloc(sizeof(char) * n);

    // Initialize the step counter and current position
    int i = 1, j = s;

    // Read the first obstacle's position and range
    int t, l, r;
    scanf("%d %d %d", &t, &l, &r);
    int k = 1;  // Counter for the number of obstacles processed

    // Loop until the current position reaches the finishing position
    while (j != f) {
        // Check if we need to read a new obstacle's position and range
        if (i > t && k < m) {
            scanf("%d %d %d", &t, &l, &r);  // Read the next obstacle's position and range
            k += 1;  // Increment the obstacle counter
        }

        // Check if the current position is at an obstacle
        if (i == t && (l <= j <= r || l <= j + d <= r)) {
            res[i - 1] = 'X';  // Mark the position with 'X' if it's blocked by an obstacle
        } else {
            res[i - 1] = c;  // Append the direction character to the result
            j += d;  // Move to the next position in the determined direction
        }

        i += 1;  // Increment the step counter
    }

    // Print the resulting path taken
    printf("%s\n", res);

    return 0;
}

