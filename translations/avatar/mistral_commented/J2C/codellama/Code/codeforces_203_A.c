
#include <stdio.h> // Include the standard I/O library
#include <stdlib.h> // Include the standard library
#include <string.h> // Include the string library

#define MAX_INPUT_LENGTH 100 // Define a macro named MAX_INPUT_LENGTH

int main(void) { // Define a main function
    char input[MAX_INPUT_LENGTH]; // Declare a character array named input
    int x, t, a, b, da, db; // Declare five integer variables named x, t, a, b, da, and db
    int first, second; // Declare two integer variables named first and second
    int i, j; // Declare two integer variables named i and j
    int ok; // Declare an integer variable named ok

    // Read the first integer x
    scanf("%d", &x);

    // Read the second integer t
    scanf("%d", &t);

    // Read the third integer a
    scanf("%d", &a);

    // Read the fourth integer b
    scanf("%d", &b);

    // Read the fifth integer da
    scanf("%d", &da);

    // Read the sixth integer db
    scanf("%d", &db);

    first = 0; // Initialize first to zero
    second = 0; // Initialize second to zero
    ok = 0; // Initialize ok to zero

    // Run a nested loop to find first and second
    for (i = 0; i < t; i++) {
        first = a - (da * i); // Calculate first for the current i
        for (j = 0; j < t; j++) {
            second = b - (db * j); // Calculate second for the current j

            // Check if second + first equals x or if either first or second equals x
            if (second + first == x || second == x || first == x || x == 0) {
                ok = 1; // Set ok to one if a match is found
                break; // Exit the inner loop if a match is found
            }
        }
    }

    // Print YES if ok is true, otherwise print NO
    if (ok) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0; // Return zero
}

