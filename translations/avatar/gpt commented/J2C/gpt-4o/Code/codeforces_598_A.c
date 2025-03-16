#include <stdio.h>
#include <math.h> // For log and pow functions

int main() {
    // Reading the number of test cases
    int q;
    scanf("%d", &q);
    
    // Looping through each test case
    while (q-- > 0) {
        // Reading the integer n for the current test case
        int n;
        scanf("%d", &n);
        
        // Initializing a variable to store the result
        long long s = 0;
        
        // Calculating the highest power of 2 less than or equal to n
        int x = (int) (log(n) / log(2));
        x++;
        
        // Calculating the final result using the derived formula
        s = -1 * (long long) pow(2, x) + 2 + ((long long) n * (long long) (n + 1)) / 2 - (long long) pow(2, x);
        
        // Printing the result for the current test case
        printf("%lld\n", s);
    }
    
    return 0;
}

// <END-OF-CODE>
