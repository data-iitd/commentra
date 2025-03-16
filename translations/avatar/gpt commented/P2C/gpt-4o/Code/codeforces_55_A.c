#include <stdio.h>

int main() {
    // Read an integer input from the user
    int n;
    scanf("%d", &n);

    // Continuously divide n by 2 while it is even
    while (n % 2 == 0) {
        n /= 2;
    }

    // Check if the resulting value of n is 1
    if (n == 1) {
        // If n is 1, it means the original number was a power of 2
        printf("YES\n");
    } else {
        // If n is not 1, the original number was not a power of 2
        printf("NO\n");
    }

    return 0;
}
// <END-OF-CODE>
