#include <stdio.h>

int main() {
    // Declare three integer variables A, B, and C
    int A, B, C;
    
    // Read three integer values from standard input and store them in A, B, and C
    scanf("%d %d %d", &A, &B, &C);
    
    // Check if the expression C - A + B is less than 0
    if (C - A + B < 0) {
        // If the expression is less than 0, print "0"
        printf("0\n");
    } else {
        // If the expression is 0 or greater, print the result of C - A + B
        printf("%d\n", C - A + B);
    }
    
    return 0;
}
