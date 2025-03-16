#include <stdio.h>

int main() {
    int n, k;

    // Read the first two integers from the standard input
    scanf("%d %d", &n, &k);

    // Check if n is divisible by k
    if (n % k == 0) {
        // If it is, print 0
        printf("0\n");
    } else {
        // If not, print 1
        printf("1\n");
    }

    return 0;
}

// <END-OF-CODE>
