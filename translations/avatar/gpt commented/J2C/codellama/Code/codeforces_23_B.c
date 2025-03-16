#include <stdio.h>

int main() {
    // Declare and initialize variables
    int t, n, maxLeft;
    
    // Read the number of test cases
    scanf("%d", &t);
    
    // Loop through each test case
    for (int i = 0; i < t; i++) {
        // Read the integer n for the current test case
        scanf("%d", &n);
        
        // Call the maxLeft function and print the result
        maxLeft = maxLeft(n);
        printf("%d\n", maxLeft);
    }
    
    // Return 0 to indicate success
    return 0;
}

// Function to calculate the maximum value based on the input n
int maxLeft(int n) {
    // Return n - 2 if n is greater than 2, otherwise return 0
    return n > 2 ? n - 2 : 0;
}

