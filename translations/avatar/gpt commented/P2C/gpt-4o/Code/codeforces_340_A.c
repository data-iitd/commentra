#include <stdio.h>

// Function to compute the Greatest Common Divisor (GCD) of two numbers
int G(int a, int b) {
    // Continue looping until b becomes 0
    while (b != 0) {
        // Update a and b using the Euclidean algorithm
        int temp = b;
        b = a % b;
        a = temp;
    }
    // Return the GCD
    return a;
}

// Function to compute the Least Common Multiple (LCM) of two numbers
int L(int a, int b) {
    // Calculate LCM using the relationship between GCD and LCM
    return (a * b) / G(a, b);
}

int main() {
    // Read input values
    int x, y, a, b;
    scanf("%d %d %d %d", &x, &y, &a, &b);

    // Calculate the LCM of x and y
    int lcm = L(x, y);

    // Calculate and print the count of multiples of LCM in the range [a, b]
    printf("%d\n", b / lcm - (a - 1) / lcm);

    return 0;
}

// <END-OF-CODE>
