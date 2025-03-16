#include <stdio.h> // Include standard input/output library for basic input/output operations
#include <stdlib.h> // Include standard library for general utilities such as dynamic memory allocation, conversions, and others
#include <string.h> // Include string library for string manipulation

#define FOR(i,b,e) for(int i=(b);i<(e);++i) // Define a macro for a for loop

int main() {
    int n, m;
    scanf("%d %d", &n, &m); // Read the number of digits and the number of constraints
<<<<<<< HEAD
    int s[m], c[m]; // Declare arrays to store the positions and values of constraints
=======
    int s[10], c[10]; // Declare arrays to store the positions and values of constraints
>>>>>>> 98c87cb78a (data updated)
    FOR(i, 0, m) {
        scanf("%d %d", &s[i], &c[i]); // Read the position and value of each constraint
        s[i]--; // Decrement the position by 1 to convert to 0-based index
    }
    
    FOR(i, 0, 1000) {
<<<<<<< HEAD
        char st[4]; // Create a string to hold the number (max 3 digits + null terminator)
=======
        char st[4]; // Array to hold the string representation of the number
>>>>>>> 98c87cb78a (data updated)
        sprintf(st, "%d", i); // Convert the current number to a string
        if (strlen(st) != n) { // Check if the length of the string is equal to the number of digits
            continue; // If not, continue to the next iteration
        }
        
        int f = 1; // Initialize a flag to 1 (true)
        FOR(j, 0, m) {
            if (st[s[j]] == c[j] + '0') { // Check if the digit at the constraint position matches the constraint value
                // Do nothing (continue to the next iteration)
            } else {
                f = 0; // If any constraint is not met, set the flag to 0 (false)
            }
        }
        
        if (f) { // Check if all constraints are met
            printf("%d\n", i); // Print the valid number
            return 0; // Exit the program
        }
    }
    
    printf("-1\n"); // If no valid number is found, print -1
    return 0; // Return 0 to indicate successful completion
}

// <END-OF-CODE>
