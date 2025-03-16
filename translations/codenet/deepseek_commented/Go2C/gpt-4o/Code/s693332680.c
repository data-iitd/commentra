#include <stdio.h>

int main() {
    // Declare three integer variables x, a, and b to store input values.
    int x, a, b;
    
    // Read three integers from the standard input and assign them to x, a, and b.
    scanf("%d %d %d", &x, &a, &b);
    
    // Use a series of if-else statements to evaluate the condition b-a and execute the corresponding block of code.
    if (b - a <= 0) {
        // If b-a is less than or equal to 0, print "delicious".
        printf("delicious\n");
    } else if (b - a <= x) {
        // If b-a is greater than 0 but less than or equal to x, print "safe".
        printf("safe\n");
    } else {
        // If b-a is greater than x, print "dangerous".
        printf("dangerous\n");
    }

    return 0;
}

// <END-OF-CODE>
