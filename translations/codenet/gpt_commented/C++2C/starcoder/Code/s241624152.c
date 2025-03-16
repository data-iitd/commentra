#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to solve the problem (currently empty)
void solve(){

}

int main(){
    // Declare variables to hold the input values
    int a, b;
    
    // Read input values for a and b
    scanf("%d %d", &a, &b);
    
    // Variable to store the result of the game
    char ans[10];

    // Determine the outcome based on the values of a and b
    if (a == 1 || b == 1){
        // Special case when either a or b is 1
        if (a == 1 && b == 1){
            // Both players have 1, result is a draw
            strcpy(ans, "Draw");
        } else if (a == 1){
            // Alice has 1, Bob wins
            strcpy(ans, "Alice");
        } else {
            // Bob has 1, Alice wins
            strcpy(ans, "Bob");
        }
    } else {
        // General case when both a and b are greater than 1
        if (a == b){
            // Both players have equal values, result is a draw
            strcpy(ans, "Draw");
        } else if (a > b){
            // Alice has a greater value, she wins
            strcpy(ans, "Alice");
        } else {
            // Bob has a greater value, he wins
            strcpy(ans, "Bob");
        }
    }

    // Output the result of the game
    printf("%s\n", ans);

    return 0;
}

