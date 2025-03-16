#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Define a large constant for infinity
#define INF 10000000000000000000LL

// Define a modulus value commonly used in competitive programming
#define MOD 1000000007

// Function to read a line of input and return it as an array of integers
void read_ints(int *a, int *b, int *c, int *d) {
    scanf("%d %d %d %d", a, b, c, d);
}

// Main function to execute the core logic of the program
int main() {
    int a, b, c, d;
    
    // Read four integers from input
    read_ints(&a, &b, &c, &d);
    
    // Calculate the maximum value from the products of the pairs and return it
    long long result = (long long)a * c;
    if ((long long)b * d > result) result = (long long)b * d;
    if ((long long)a * d > result) result = (long long)a * d;
    if ((long long)b * c > result) result = (long long)b * c;

    // Print the result
    printf("%lld\n", result);
    
    return 0;
}

// <END-OF-CODE>
