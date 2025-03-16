#include <stdio.h>

void solve() {
    int x, t, a, b, da, db;
    
    // Reading the input values
    scanf("%d", &x); // Target value x
    scanf("%d", &t); // Number of test cases (unused in this code)
    scanf("%d", &a); // Value a
    scanf("%d", &b); // Value b
    scanf("%d", &da); // Difference a (da)
    scanf("%d", &db); // Difference b (db)
    
    // Variables to store calculated values
    int first, second;
    
    // Flag to determine if a solution is found
    int ok = 0; // 0 for false, 1 for true
    
    // Nested loop to calculate possible values of first and second
    for (int i = 0; i < t; i++) {
        first = a - (da * i); // Calculate first value
        for (int j = 0; j < t; j++) {
            second = b - (db * j); // Calculate second value
            if (second + first == x || second == x || first == x || x == 0) {
                // Check if the sum of first and second equals x, or if either value equals x, or if x is zero
                ok = 1; // Set flag to true
                break; 
            }
        }
        if (ok) break; // Exit the outer loop if a solution is found
    }
    
    // Print the result based on the flag
    if (ok) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}

int main() {
    solve();
    return 0;
}

/* <END-OF-CODE> */
