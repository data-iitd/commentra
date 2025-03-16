
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to solve the problem
void solve(){
    // Initialize variables
    int a, b;

    // Read input values from the user
    scanf("%d %d", &a, &b);

    // Initialize output string
    char ans[100];

    // Determine the answer based on the input values
    if (a == 1 && b == 1){
        // Both a and b are equal to 1, so the answer is a draw
        strcpy(ans, "Draw");
    } else if (a == 1){
        // a is equal to 1, so the answer is Alice
        strcpy(ans, "Alice");
    } else {
        // Neither a nor b is equal to 1, so the answer is Bob
        strcpy(ans, "Bob");
    }

    // Print the answer to the console
    printf("%s\n", ans);
}

int main(){
    // Call the solve function to solve the problem
    solve();

    return 0;
}

