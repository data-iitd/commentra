#include <stdio.h>

// Function to compute the greatest common divisor (GCD)
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int x;
    scanf("%d", &x); // Read an integer from input
    printf("%d\n", 360 / gcd(360, x)); // Print the result
    return 0;
}

// <END-OF-CODE>
