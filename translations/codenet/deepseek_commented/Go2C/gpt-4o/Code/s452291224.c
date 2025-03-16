#include <stdio.h>

int main() {
    // Declare three integer variables A, B, and C
    int A, B, C;
    
    // Read three integers from the standard input and assign them to A, B, and C
    scanf("%d %d %d", &A, &B, &C);
    
    // Check if the expression C-A+B is less than 0
    if (C - A + B < 0) {
        // If true, print "0"
        printf("0\n");
    } else {
        // Otherwise, print the value of C-A+B
        printf("%d\n", C - A + B);
    }
    
    return 0;
}

// <END-OF-CODE>
