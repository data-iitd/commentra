#include <stdio.h>

int main() {
    // Declare two integer variables 'a' and 'b'
    int a, b;

    // Read two integer values from the user input using scanf()
    scanf("%d %d", &a, &b);

    // Check if 'b' is divisible by 'a' using if statement
    if (b % a == 0) {
        // If 'b' is divisible by 'a', print the sum of 'a' and 'b'
        printf("%d\n", a + b);
    } else {
        // If 'b' is not divisible by 'a', print the difference between 'b' and 'a'
        printf("%d\n", b - a);
    }

    return 0;
}

// <END-OF-CODE>
