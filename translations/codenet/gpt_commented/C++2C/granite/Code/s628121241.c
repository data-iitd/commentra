
#include<stdio.h>

// Function to compute the greatest common divisor (GCD) of two integers
int gcd(int a, int b) {
    // Base case: if 'a' is 0, return 'b' as the GCD
    if (a == 0) return b;
    // Recursive case: call gcd with 'b' modulo 'a' and 'a'
    return gcd(b % a, a);
}

int main() {
    int R; // Variable to store the input rating
    scanf("%d", &R); // Read the rating from standard input

    // Determine the category based on the rating value
    if (R < 1200) 
        printf("ABC\n"); // Output "ABC" for ratings less than 1200
    else if (R >= 2800) 
        printf("AGC\n"); // Output "AGC" for ratings 2800 and above
    else 
        printf("ARC\n"); // Output "ARC" for ratings between 1200 and 2800
}


