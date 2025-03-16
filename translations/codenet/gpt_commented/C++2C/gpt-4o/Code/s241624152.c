#include <stdio.h>

// Function to solve the problem (currently empty)
void solve() {
<<<<<<< HEAD
    // This function is not used in the C version
=======
    // No implementation needed
>>>>>>> 98c87cb78a (data updated)
}

int main() {
    // Declare variables to hold the input values
    int a, b;
    
    // Read input values for a and b
    scanf("%d %d", &a, &b);
    
    // Variable to store the result of the game
<<<<<<< HEAD
    const char* ans;
=======
    char ans[10]; // Sufficient size for "Alice", "Bob", or "Draw"
>>>>>>> 98c87cb78a (data updated)

    // Determine the outcome based on the values of a and b
    if (a == 1 || b == 1) {
        // Special case when either a or b is 1
        if (a == 1 && b == 1) {
            // Both players have 1, result is a draw
<<<<<<< HEAD
            ans = "Draw";
        } else if (a == 1) {
            // Alice has 1, Bob wins
            ans = "Alice";
        } else {
            // Bob has 1, Alice wins
            ans = "Bob";
=======
            sprintf(ans, "Draw");
        } else if (a == 1) {
            // Alice has 1, Bob wins
            sprintf(ans, "Alice");
        } else {
            // Bob has 1, Alice wins
            sprintf(ans, "Bob");
>>>>>>> 98c87cb78a (data updated)
        }
    } else {
        // General case when both a and b are greater than 1
        if (a == b) {
            // Both players have equal values, result is a draw
<<<<<<< HEAD
            ans = "Draw";
        } else if (a > b) {
            // Alice has a greater value, she wins
            ans = "Alice";
        } else {
            // Bob has a greater value, he wins
            ans = "Bob";
=======
            sprintf(ans, "Draw");
        } else if (a > b) {
            // Alice has a greater value, she wins
            sprintf(ans, "Alice");
        } else {
            // Bob has a greater value, he wins
            sprintf(ans, "Bob");
>>>>>>> 98c87cb78a (data updated)
        }
    }

    // Output the result of the game
    printf("%s\n", ans);

    return 0;
}

// <END-OF-CODE>
