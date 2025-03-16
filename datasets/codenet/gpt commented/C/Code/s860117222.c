#include <stdio.h>

int main() {
    // Declare three long long integer variables to hold input values
    long long int a, b, c;

    // Read three long long integers from standard input
    scanf("%lld %lld %lld", &a, &b, &c);

    // Calculate the value of d as the difference between c and the sum of a and b
    long long int d = c - a - b;

    // Check if d is positive and if 4 times the product of a and b is less than d squared
    if ((d > 0) && ((4 * a * b) < d * d)) {
        // If the condition is true, print "Yes"
        printf("Yes\n");
    } else {
        // If the condition is false, print "No"
        printf("No\n");
    }

    // Return 0 to indicate successful completion of the program
    return 0;
}
