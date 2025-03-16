#include <stdio.h> // Include standard input-output library

// Function to calculate the maximum value based on the input n
int maxLeft(int n) {
    // Return n - 2 if n is greater than 2, otherwise return 0
    return n > 2 ? n - 2 : 0;
}

int main() {
    int t; // Variable to store the number of test cases

    // Read the number of test cases
    scanf("%d", &t);
    
    // Loop through each test case
    for (int i = 0; i < t; i++) {
        int n; // Variable to store the integer for the current test case
        
        // Read the integer n for the current test case
        scanf("%d", &n);
        
        // Call the maxLeft function and print the result
        printf("%d\n", maxLeft(n));
    }

    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
