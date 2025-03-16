#include <stdio.h>

int main() {
    // Declare variables K and X to hold input values
    int K, X;
    
    // Read two integers from standard input
    scanf("%d %d", &K, &X);
    
    // Check if 500 times K is greater than or equal to X
    if (500 * K >= X) {
        // If the condition is true, print "Yes"
        printf("Yes\n");
    } else {
        // If the condition is false, print "No"
        printf("No\n");
    }
    
    return 0;
}

