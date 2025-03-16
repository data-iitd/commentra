#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declare three integer variables to hold input values
    int a, b, c;

    // Read three integers from standard input
    scanf("%d %d %d", &a, &b, &c);

    // Check if the sum of a and b is greater than or equal to c
    if (a + b >= c) {
        // If the condition is true, print "Yes"
        printf("Yes\n");
    } else {
        // If the condition is false, print "No"
        printf("No\n");
    }
    
    // Return 0 to indicate successful completion of the program
    return 0;
}

