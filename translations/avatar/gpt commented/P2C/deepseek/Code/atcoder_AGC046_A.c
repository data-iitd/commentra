#include <stdio.h>
#include <stdlib.h>

// Function to calculate the greatest common divisor (gcd)
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    // Take an integer input from the user
    int x;
    scanf("%d", &x);

    // Calculate and print the number of equal parts in a full circle (360 degrees) 
    // that can be formed with the given angle x using the gcd
    printf("%d\n", 360 / gcd(360, x));

    return 0;
}
