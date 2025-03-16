#include <stdio.h>
#include <stdlib.h>

int main() {
    // Read the number of test cases
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
    
    // Prevent resource leaks
    return 0;
}

int maxLeft(int n) {
    // Return n - 2 if n is greater than 2, otherwise return 0
    return n > 2? n - 2 : 0;
}

