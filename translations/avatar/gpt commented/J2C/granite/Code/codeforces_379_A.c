
#include <stdio.h>

int main() {
    int a, b, res; // Declare the variables
    
    // Read two integers from the user
    scanf("%d %d", &a, &b);
    
    // Initialize the result with the value of 'a'
    res = a;
    
    // Loop to perform the division and accumulate the result
    while (a >= b) {
        // Add the quotient of a divided by b to the result
        res += (a / b);
        
        // Update 'a' to be the sum of the quotient and the remainder
        a = (a / b) + (a % b);
    }
    
    // Output the final result
    printf("%d\n", res);
    
    return 0;
}
// END-OF-CODE