#include <stdio.h>
#include <stdlib.h>  // Include the stdlib library for the abs function

int main() {
    long long x, y;
    scanf("%lld %lld", &x, &y);  // Read two integers from standard input
    if (abs(x - y) <= 1) {
        printf("Brown\n");  // Check if the absolute difference is less than or equal to 1
    } else {
        printf("Alice\n");  // Otherwise, print "Alice"
    }
    return 0;  // Return 0 to indicate successful completion
}

// <END-OF-CODE>
