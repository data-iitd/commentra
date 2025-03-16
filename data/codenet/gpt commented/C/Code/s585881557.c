#include <stdio.h>

int main(void) {
    // Declare two integer variables h and r
    int h, r;

    // Read two integers from standard input
    scanf("%d%d", &h, &r);

    // Compare the value of r with -h
    if (r > -h) {
        // If r is greater than -h, print "1"
        printf("1\n");
    }
    else if (r == -h) {
        // If r is equal to -h, print "0"
        printf("0\n");
    }
    else {
        // If r is less than -h, print "-1"
        printf("-1\n");
    }

    // Return 0 to indicate successful completion of the program
    return 0;
}
