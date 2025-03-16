#include <stdio.h>

int main() {
    int n, m, s, f;
    scanf("%d %d %d %d", &n, &m, &s, &f);  // Read values of n, m, s, and f

    int d;  // Direction
    char c; // Character for direction
    if (s < f) {
        d = 1;  // Set direction to right (R)
        c = 'R';
    } else {
        d = -1; // Set direction to left (L)
        c = 'L';
    }

    char res[100000]; // Initialize a result array (assuming max length)
    int i = 1; // Initialize step counter
    int j = s; // Initialize current position
    int t, l, r; // Variables for time and range
    int k = 1; // Initialize the current time step

    scanf("%d %d %d", &t, &l, &r); // Read initial values of t, l, and r

    // Loop until the current position reaches the finishing point
    while (j != f) {
        if (i > t && k < m) { // Check if it's time to update the time step and there are more steps
            scanf("%d %d %d", &t, &l, &r); // Read new values for t, l, and r
            k++; // Increment the time step counter
        }

        if (i == t && (l <= j && j <= r || l <= j + d && j + d <= r)) { // Check conditions
            res[i - 1] = 'X'; // Append 'X' to the result array
        } else {
            res[i - 1] = c; // Append the direction character to the result array
            j += d; // Update the current position
        }
        i++; // Increment the step counter
    }

    res[i - 1] = '\0'; // Null-terminate the result string
    printf("%s\n", res); // Print the result string

    return 0;
} // <END-OF-CODE>
