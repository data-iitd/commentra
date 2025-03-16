#include<stdio.h>
#include<stdlib.h>

// Function to calculate the greatest common divisor (GCD) using recursion
int gcd(int a, int b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}

int main() {
    // Take an integer input from the user
    int R;
    scanf("%d", &R);

    // Check the value of R and print the corresponding output
    if (R < 1200)
        printf("ABC\n"); // If R is less than 1200, print "ABC"
    else if (R >= 2800)
        printf("AGC\n"); // If R is 2800 or more, print "AGC"
    else
        printf("ARC\n"); // Otherwise, print "ARC"
}
