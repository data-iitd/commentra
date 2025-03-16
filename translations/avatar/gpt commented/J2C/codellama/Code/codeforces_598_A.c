#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    // Creating a variable to store the number of test cases
    int q;
    
    // Reading the number of test cases
    scanf("%d", &q);
    
    // Looping through each test case
    while (q-- > 0) {
        // Reading the integer n for the current test case
        int n;
        scanf("%d", &n);
        
        // Initializing a variable to store the result
        long s = 0;
        
        // Calculating the highest power of 2 less than or equal to n
        int x = (int) (log(n) / log(2));
        x++;
        
        // Calculating the final result using the derived formula
        s = -1 * (long) pow(2, x) + 2 + ((long) n * (long) (n + 1)) / 2 - (long) pow(2, x);
        
        // Printing the result for the current test case
        printf("%ld\n", s);
    }
    
    // Closing the scanner to prevent resource leaks
    // scanf("%d", &q);
    
    return 0;
}

