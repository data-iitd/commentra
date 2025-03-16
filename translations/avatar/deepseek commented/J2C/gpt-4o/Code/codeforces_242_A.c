#include <stdio.h>

int main() {
    int x, y, a, b; 
    scanf("%d", &x); // Read first integer input
    scanf("%d", &y); // Read second integer input
    scanf("%d", &a); // Read third integer input
    scanf("%d", &b); // Read fourth integer input

    int count = 0; // Initialize counter to keep track of valid pairs

    // Nested loops to iterate through possible pairs (i, j)
    for (int i = a; i <= x; i++) { 
        for (int j = b; j <= y; j++) { 
            if (i <= j) continue; // Skip pairs where i is not greater than j
            count++; // Increment counter for each valid pair
        } 
    } 

    printf("%d\n", count); // Print the total count of valid pairs

    // Print each valid pair
    for (int i = a; i <= x; i++) { 
        for (int j = b; j <= y; j++) { 
            if (i <= j) continue; // Skip pairs where i is not greater than j
            printf("%d %d\n", i, j); // Print each valid pair
        } 
    } 

    return 0; // Return 0 to indicate successful completion
}

// <END-OF-CODE>
