#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    long long a,b;
    scanf("%lld %lld", &a, &b); // Read two long long integers from standard input

    // Compute the maximum value among a+b, a-b, and a*b
    printf("%lld\n", max(a+b,max(a-b,a*b))); // Print the maximum value

    return 0; // Return 0 indicating successful execution
}

