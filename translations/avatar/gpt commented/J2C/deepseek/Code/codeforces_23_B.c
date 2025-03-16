#include <stdio.h>

// Function to calculate the maximum value based on the input n
int maxLeft(int n) {
    // Return n - 2 if n is greater than 2, otherwise return 0
    return n > 2 ? n - 2 : 0;
}

int main() {
    // Create a Scanner object to read input from the console
    int t;
    scanf("%d", &t);
    
    // Loop through each test case
    for (int i = 0; i < t; i++) {
        // Read the integer n for the current test case
        int n;
        scanf("%d", &n);
        
        // Call the maxLeft function and print the result
        printf("%d\n", maxLeft(n));
    }
    
    return 0;
}
