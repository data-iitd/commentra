
#include <stdio.h> // Include the standard input/output library

int maxLeft(int n) {
    // Return n - 2 if n is greater than 2, otherwise return 0
    return n > 2? n - 2 : 0;
}

int main() {
    // Create a variable to store the number of test cases
    int t;
    
    // Read the number of test cases from the console
    scanf("%d", &t);
    
    // Loop through each test case
    for (int i = 0; i < t; i++) {
        // Read the integer n for the current test case
        int n;
        scanf("%d", &n);
        
        // Call the maxLeft function and print the result
        printf("%d\n", maxLeft(n));
    }
    
    // Return 0 to indicate successful execution
    return 0;
}

