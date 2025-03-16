#include <stdio.h>

int main() {
    int n, m, s, f;
    scanf("%d %d %d %d", &n, &m, &s, &f);

    int d; // Direction of movement
    char c; // Character representing movement direction

    if (s < f) {
        d = 1; // Move right
        c = 'R'; // Character for right movement
    } else {
        d = -1; // Move left
        c = 'L'; // Character for left movement
    }

    char res[1000]; // Result string to store the path taken
    int i = 1; // Step counter
    int j = s; // Current position

    int t, l, r; // Obstacle position and range
    scanf("%d %d %d", &t, &l, &r);
    int k = 1; // Counter for the number of obstacles processed

    while (j != f) {
        // Check if we need to read a new obstacle's position and range
        if (i > t && k < m) {
            scanf("%d %d %d", &t, &l, &r); // Read the next obstacle's position and range
            k++; // Increment the obstacle counter
        }

        // Check if the current position is at an obstacle
        if (i == t && (l <= j && j <= r || l <= j + d && j + d <= r)) {
            res[i - 1] = 'X'; // Mark the position with 'X' if it's blocked by an obstacle
        } else {
            res[i - 1] = c; // Append the direction character to the result
            j += d; // Move to the next position in the determined direction
        }

        i++; // Increment the step counter
    }

    res[i - 1] = '\0'; // Null-terminate the result string

    // Print the resulting path taken
    printf("%s\n", res);

    return 0;
}

// <END-OF-CODE>
