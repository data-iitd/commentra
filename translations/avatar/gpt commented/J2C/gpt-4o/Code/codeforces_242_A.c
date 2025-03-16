#include <stdio.h> // Include standard input-output library

int main() {
    // Declare variables to hold the input values
    int x, y, a, b;
    
    // Read four integers from the user
    scanf("%d", &x); // Upper limit for the first variable
    scanf("%d", &y); // Upper limit for the second variable
    scanf("%d", &a); // Lower limit for the first variable
    scanf("%d", &b); // Lower limit for the second variable
    
    // Initialize a counter to keep track of valid pairs
    int count = 0;
    
    // First nested loop to iterate through the range [a, x]
    for (int i = a; i <= x; i++) {
        // Second nested loop to iterate through the range [b, y]
        for (int j = b; j <= y; j++) {
            // Skip the iteration if i is less than or equal to j
            if (i <= j) continue;
            
            // Increment the count for each valid pair (i, j)
            count++;
        }
    }
    
    // Output the total count of valid pairs
    printf("%d\n", count);
    
    // Second set of nested loops to print the valid pairs
    for (int i = a; i <= x; i++) {
        for (int j = b; j <= y; j++) {
            // Skip the iteration if i is less than or equal to j
            if (i <= j) continue;
            
            // Print the valid pair (i, j)
            printf("%d %d\n", i, j);
        }
    }
    
    return 0; // Return 0 to indicate successful completion
}

// <END-OF-CODE>
