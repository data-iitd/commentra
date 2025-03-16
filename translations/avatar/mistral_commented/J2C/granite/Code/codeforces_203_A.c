
#include <stdio.h> // Include the C standard I/O library
#include <stdlib.h> // Include the C standard library

int main() { // Define the main function
    int x, t, a, b, da, db; // Declare integer variables x, t, a, b, da, and db
    scanf("%d %d %d %d %d %d", &x, &t, &a, &b, &da, &db); // Read integers from the standard input
    int first, second; // Declare integer variables first and second
    int ok = 0; // Declare an integer variable ok and initialize it to zero

    // Run a nested loop to find first and second
    for (int i = 0; i < t; i++) {
        first = a - (da * i); // Calculate first for the current i
        for (int j = 0; j < t; j++) {
            second = b - (db * j); // Calculate second for the current j

            // Check if second + first equals x or if either first or second equals x
            if (second + first == x || second == x || first == x || x == 0) {
                ok = 1; // Set ok to 1 if a match is found
                break; // Exit the inner loop if a match is found
            }
        }
    }

    // Print YES if ok is 1, otherwise print NO
    if (ok) {
        printf("YES");
    } else {
        printf("NO");
    }

    return 0; // Return 0 to indicate successful execution
}

