#include <stdio.h>

int main() {
    // Declare two integer variables K and X
    int K, X;
    
    // Read two integers from the standard input and assign them to K and X
    scanf("%d %d", &K, &X);
    
    // Check if the product of 500 and K is greater than or equal to X
    if (500 * K >= X) {
        // If true, print "Yes"
        printf("Yes\n");
    } else {
        // If false, print "No"
        printf("No\n");
    }
    
    return 0;
}
// <END-OF-CODE>
