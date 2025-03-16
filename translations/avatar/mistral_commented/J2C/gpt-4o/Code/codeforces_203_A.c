#include <stdio.h> // Include standard input/output library
#include <stdbool.h> // Include library for boolean type

void solve() { // Define a function named solve
    int x, t, a, b, da, db; // Declare variables
    scanf("%d %d %d %d %d %d", &x, &t, &a, &b, &da, &db); // Read input values

    int first = 0; // Initialize first to zero
    int second = 0; // Initialize second to zero
    bool ok = false; // Initialize ok to false

    // Run a nested loop to find first and second
    for (int i = 0; i < t; i++) {
        first = a - (da * i); // Calculate first for the current i
        for (int j = 0; j < t; j++) {
            second = b - (db * j); // Calculate second for the current j

            // Check if second + first equals x or if either first or second equals x
            if (second + first == x || second == x || first == x || x == 0) {
                ok = true; // Set ok to true if a match is found
                break; // Exit the inner loop if a match is found
            }
        }
        if (ok) break; // Exit the outer loop if a match is found
    }

    // Print YES if ok is true, otherwise print NO
    if (ok) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}

int main() { // Define the main function
    solve(); // Call the solve function
    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
