
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    // Initialize variables
    long long int a, b;

    // Read input values from standard input
    scanf("%lld %lld", &a, &b);

    // Calculate the maximum value among a+b, a-b, and a*b
    long long int result = fmax(fmax(a+b, a-b), a*b);

    // Output the result to standard output
    printf("%lld\n", result);

    // End of the program
    return 0;
}


