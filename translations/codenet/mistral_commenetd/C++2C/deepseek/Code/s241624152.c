#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define aliases for common data types
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

// Include necessary libraries
#include <string.h>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
#include <bitset>
#include <array>
#include <deque>
#include <queue>
#include <map>

// Function to solve the problem
void solve(){
    // Initialize variables
    int a, b;

    // Read input values from the user
    scanf("%d %d", &a, &b);

    // Initialize output string
    char ans[10];

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
