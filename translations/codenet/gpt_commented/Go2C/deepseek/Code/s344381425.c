#include <stdio.h>

int main() {
    // Declare three integer variables to hold the input values
    int a, b, c;
    
    // Read three integers from standard input
    scanf("%d %d %d", &a, &b, &c);
    
    // Check if the integers are in strictly increasing order
    if (a < b && b < c) {
        // If they are in increasing order, print "Yes"
        printf("Yes\n");
    } else {
        // If they are not in increasing order, print "No"
        printf("No\n");
    }
    
    // End of the main function
    return 0;
}

