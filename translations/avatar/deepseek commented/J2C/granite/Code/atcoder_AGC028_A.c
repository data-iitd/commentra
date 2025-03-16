
#include <stdio.h> // Including standard input/output library
#include <math.h> // Including mathematical functions library
#include <string.h> // Including string manipulation functions library
#include <stdlib.h> // Including standard library functions

int main() {
    int n, m, gcd; // Declaring variables n, m, and gcd
    char s[100001], t[100001]; // Declaring character arrays s and t with maximum length 100001

    scanf("%d %d", &n, &m); // Reading the first and second integers from input
    scanf("%s %s", s, t); // Reading the first and second strings from input

    gcd = __gcd(n, m); // Calculating the GCD of n and m using built-in function __gcd

    for (int k = 0; k < gcd; k++) { // Iterating over the range of the GCD
        if (s[k * n / gcd]!= t[k * m / gcd]) { // Checking for character mismatches
            printf("%ld", -1); // Printing -1 if a mismatch is found
            return 0; // Exiting the program
        }
    }

    printf("%ld", (long)n * m / gcd); // Printing the result if no mismatches are found

    return 0; // Exiting the program
}

