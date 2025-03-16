#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

// Method to solve the problem
void solve() { 
    // Read input values
    int x, t, a, b, da, db; // Target value, maximum number of steps, initial positions, step sizes
    scanf("%d %d %d %d %d %d", &x, &t, &a, &b, &da, &db); 
    
    int first; // Position of first entity after i steps
    int second; // Position of second entity after j steps
    int ok = 0; // Flag to indicate if the target can be reached

    // Iterate through possible steps for the first entity
    for (int i = 0; i < t; i++) { 
        first = a - (da * i); // Calculate position of first entity
        
        // Iterate through possible steps for the second entity
        for (int j = 0; j < t; j++) { 
            second = b - (db * j); // Calculate position of second entity
            
            // Check if any of the conditions to reach target x are met
            if (second + first == x || second == x || first == x || x == 0) { 
                ok = 1; // Set flag to true if target is reachable
                break; // Exit inner loop if target is found
            } 
        } 
    } 
    
    // Output result based on whether the target can be reached
    if (ok) 
        printf("YES\n"); // Target can be reached
    else 
        printf("NO\n"); // Target cannot be reached
} 

// Main method to run the program
int main() { 
    solve(); // Call the solve method to process the input
    return 0; // Return 0 to indicate successful execution
} 

