#include <stdio.h>

// Function to calculate the greatest common divisor (gcd) using the Euclidean algorithm
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

    // Ask the user for an integer input and assign it to the variable x
    scanf("%d", &x);

    // Calculate the greatest common divisor (gcd) of 360 and the user input x
    int gcd_value = gcd(360, x);

    // Print the result of the division of 360 by the gcd
    printf("%d\n", 360 / gcd_value);

    return 0;
}
