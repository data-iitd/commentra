#include <stdio.h>

int main() {
    // Declare variables to hold input values
    int x, a, b;
    
    // Read three integer values from standard input
    scanf("%d %d %d", &x, &a, &b);
    
    // Evaluate the difference between b and a to determine the output
    if (b - a <= 0) {
        printf("delicious\n"); // Output "delicious" if b is less than or equal to a
    } else if (b - a <= x) {
        printf("safe\n"); // Output "safe" if the difference is within the limit x
    } else {
        printf("dangerous\n"); // Output "dangerous" if the difference exceeds x
    }

    return 0;
}

// <END-OF-CODE>
