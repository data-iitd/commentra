#include <stdio.h>

int main(void)
{
    // Declare two integer variables n and k
    int n, k;

    // Read two integers from user input
    scanf("%d%d", &n, &k);

    // Check if n is divisible by k
    if (n % k == 0) {
        // If n is divisible by k, print 0
        printf("0\n");
    } else {
        // If n is not divisible by k, print 1
        printf("1\n");
    }

    // Return 0 to indicate successful completion of the program
    return 0;
}
