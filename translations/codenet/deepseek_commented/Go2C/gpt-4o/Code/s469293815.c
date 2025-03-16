#include <stdio.h>

int main() {
    int A, B, C;
    
    // Read three integers from standard input
    scanf("%d %d %d", &A, &B, &C);

    // Check if the sum of A and B is greater than or equal to C
    if (A + B >= C) {
        printf("Yes\n");
    } else {
        // If the sum is less than C, print "No"
        printf("No\n");
    }

    return 0;
}

// <END-OF-CODE>
