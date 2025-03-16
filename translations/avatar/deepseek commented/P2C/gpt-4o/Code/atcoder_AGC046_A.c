#include <stdio.h>

// Function to calculate the greatest common divisor (GCD)
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

    // Take an integer input x
    scanf("%d", &x);

    // Calculate the number of distinct cyclic permutations of a string of length x
    printf("%d\n", 360 / gcd(360, x));

    return 0;
}

// <END-OF-CODE>
