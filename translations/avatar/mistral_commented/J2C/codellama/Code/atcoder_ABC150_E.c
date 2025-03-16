#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Defining a constant value for modulus
#define mod 1000000007

// Static method to calculate the power of a number x raised to the power n
long power(long x, long n) {
    if (n == 0) { // Base case when n is 0
        return 1;
    }

    long val = power(x, n / 2); // Recursively calculating the square of x raised to the power n/2

    // If n is odd, multiplying the result with x
    if (n % 2 == 1) {
        val = val * x % mod;
    }

    // Returning the final result
    return val;
}

// Main method to start the execution of the program
int main() {
    // Declaring and initializing variables
    int n;
    int *c;
    long b;
    long a;
    long ans;

    // Reading the first line of input and parsing the first element as an integer representing the size of the array
    scanf("%d", &n);

    // Allocating memory for the array c
    c = (int *)malloc(n * sizeof(int));

    // Reading the second line of input and parsing the elements as integers
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }

    // Checking if the size of the array is 1
    if (n == 1) {
        // Printing the result for the case when the size of the array is 1
        printf("%d\n", c[0] * 2 % mod);
        return 0; // Exiting the method after printing the result
    }

    // Sorting the array c in parallel using Arrays.parallelSort() method
    qsort(c, n, sizeof(int), compare);

    // Calculating the values of b and a
    b = power(2, n);
    a = power(2, n - 2);

    // Initializing the variable ans to 0
    ans = 0;

    // Iterating through the array from index 2 to n+1
    for (int i = 2; i <= n + 1; i++) {
        // Calculating the value of val using the current index i and the previously calculated value a
        long val = a * i % mod;

        // Multiplying the value of val with the current element of the array c[n+1-i]
        val *= c[n + 1 - i];

        // Taking the modulus of the product to ensure the result is within the range of modulus
        val %= mod;

        // Adding the value of val to the variable ans
        ans += val;

        // Taking the modulus of the sum of ans and val to ensure the result is within the range of modulus
        ans %= mod;
    }

    // Multiplying the value of ans with the value of b
    ans *= b;

    // Taking the modulus of the product to ensure the result is within the range of modulus
    ans %= mod;

    // Printing the final result
    printf("%ld\n", ans);

    // Freeing up memory allocated for the array c
    free(c);

    // Returning 0 to indicate successful execution
    return 0;
}

// Static method to compare two integers
int compare(const void *a, const void *b) {
    // Casting the void pointers to int pointers
    int *ia = (int *)a;
    int *ib = (int *)b;

    // Returning the difference between the two integers
    return *ia - *ib;
}

// End of code
