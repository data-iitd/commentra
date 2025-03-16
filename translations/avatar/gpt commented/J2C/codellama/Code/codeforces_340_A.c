#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    // Create a Scanner object to read input from the user
    int x, y, a, b, j = 2, i, x1 = 0, y1 = 0, c = 0; 
    int ans = 1; // Flag to check if a valid solution exists
    
    // Read four long integer inputs from the user
    scanf("%d %d %d %d", &x, &y, &a, &b);
    
    // Determine the maximum of x and y
    c = (x > y) ? x : y;
    
    // Check if the maximum value exceeds the upper bound b
    if (c > b) {
        printf("0\n"); // Output 0 if no valid multiples exist
        ans = 0; // Set answer flag to false
    }
    
    // Loop to find the least common multiple (LCM) of x and y
    while (c % ((x < y) ? x : y) != 0 && ans) {
        // Multiply by j to find the next multiple
        if (x > y) {
            c = x * j; // Calculate next multiple of x
            j++;
        } else {
            c = y * j; // Calculate next multiple of y
            j++;
        }
        
        // Check if the calculated multiple exceeds the upper bound b
        if (c > b) {
            printf("0\n"); // Output 0 if no valid multiples exist
            ans = 0; // Set answer flag to false
            break; // Exit the loop
        }
    }
    
    // If a valid multiple was found within the bounds
    if (ans) {
        int count = 0; // Initialize count of valid multiples
        // Find the first multiple of c within the range [a, b]
        for (i = a; i <= b; i++) {
            if (i % c == 0) break; // Break when a multiple is found
        }
        
        // Check if a valid multiple was found within the range
        if (i != b + 1) {
            // Calculate the number of multiples of c in the range [a, b]
            printf("%d\n", ((b - i) / c) + 1);
        } else {
            printf("0\n"); // Output 0 if no multiples found
        }
    }
    
    return 0;
}

