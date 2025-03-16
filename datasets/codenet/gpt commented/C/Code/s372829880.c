#include <stdio.h>

int main() {
    // Declare two integer variables x and a
    int x, a;

    // Read two integer values from user input and store them in x and a
    scanf("%d %d", &x, &a);

    // Check if x is greater than or equal to a
    // If true, print 10; otherwise, print 0
    printf("%d\n", (x >= a) * 10);

    // Return 0 to indicate successful completion of the program
    return 0;
}
