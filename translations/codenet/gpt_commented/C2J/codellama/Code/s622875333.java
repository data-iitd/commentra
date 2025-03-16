#include<stdio.h>

// Declare global variables
int n, r, i, j, p, c;
int a[100], b[100];

int main() {
    // Infinite loop to continuously accept input until a termination condition is met
    while(1) {
        // Read the values of n and r from the user
        scanf("%d %d", &n, &r);
        
        // Check for the termination condition (both n and r are zero)
        if(n == 0 && r == 0) break;
        
        // Initialize array a with values from n down to 1
        for(i = 0; i < n; i++) {
            a[i] = n - i; // Fill array a with decreasing values starting from n
        }
        
        // Process r operations as specified by the user
        for(i = 0; i < r; i++) {
            // Copy current state of array a to array b
            for(j = 0; j < n; j++) {
                b[j] = a[j]; // Save the current configuration of a into b
            }
            
            // Read the values of p and c for the current operation
            scanf("%d %d", &p, &c);

            // Update the first c elements of array a based on the values from array b
            for(j = 0; j < c; j++) {
                a[j] = b[p - 1 + j]; // Move elements from b to a based on p and c
            }
            
            // Shift the remaining elements in array a
            for(j = c; j < c + p - 1; j++) {
                a[j] = b[j - c]; // Continue filling a with the remaining elements from b
            }
        }
        
        // Output the first element of array a after all operations
        printf("%d\n", a[0]);
    }
    
    return 0; // End of the program
}

