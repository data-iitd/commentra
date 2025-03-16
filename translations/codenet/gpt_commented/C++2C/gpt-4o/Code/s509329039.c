#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FOR(i,b,e) for(int i=(b);i<(e);++i)

int main() {
    // Read the number of constraints (n) and the number of conditions (m)
    int n, m;
    scanf("%d %d", &n, &m);

    // Initialize arrays to store the positions (s) and corresponding values (c)
    int s[m], c[m];
    
    // Read the constraints into the arrays
    FOR(i, 0, m) {
        scanf("%d %d", &s[i], &c[i]);
        s[i]--; // Adjust for 0-based indexing
    }

    // Iterate through all possible numbers from 0 to 999
    FOR(i, 0, 1000) {
        char st[4]; // Buffer to hold the string representation of the number
        sprintf(st, "%d", i); // Convert the number to a string
        
        // Skip numbers that do not have the required length
        if (strlen(st) != n) {
            continue;
        }

        // Flag to check if the current number satisfies all conditions
        int f = 1;

        // Check each condition against the current number
        FOR(j, 0, m) {
            if (st[s[j]] == c[j] + '0') {
                // Condition is satisfied
            } else {
                // Condition is not satisfied, set flag to 0
                f = 0;
                break; // No need to check further if one condition fails
            }
        }

        // If all conditions are satisfied, print the number and exit
        if (f) {
            printf("%d\n", i);
            return 0;
        }
    }

    // If no valid number is found, output -1
    printf("-1\n");
    return 0;
}

// <END-OF-CODE>
