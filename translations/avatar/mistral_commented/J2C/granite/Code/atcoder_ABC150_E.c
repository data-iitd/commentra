
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the power of a number x raised to the power n
long long power(long long x, long long n) {
    if (n == 0) { // Base case when n is 0
        return 1;
    }

    int mod = 1000000007; // Defining a constant value for modulus
    long long val = power(x, n / 2); // Recursively calculating the square of x raised to the power n/2

    // If n is odd, multiplying the result with x
    if (n % 2 == 1) {
        val = val * x % mod;
    }

    // Returning the final result
    return val;
}

int main() {
    int n; // Size of the array
    scanf("%d", &n); // Reading the size of the array from the user

    int c[n]; // Array of size n to store the input values
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]); // Reading the input values and storing them in the array c
    }

    int mod = 1000000007; // Defining a constant value for modulus

    // Checking if the size of the array is 1
    if (n == 1) {
        // Printing the result for the case when the size of the array is 1
        printf("%d\n", (c[0] * 2) % mod);
        return 0; // Exiting the program after printing the result
    }

    // Sorting the array c in parallel using qsort() function
    qsort(c, n, sizeof(int), cmpfunc);

    // Calculating the values of b and a
    long long b = power(2, n);
    long long a = power(2, n - 2);

    // Initializing the variable ans to 0
    long long ans = 0;

    // Iterating through the array from index 2 to n+1
    for (int i = 2; i <= n + 1; i++) {
        // Calculating the value of val using the current index i and the previously calculated value a
        long long val = a * i % mod;

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
    printf("%lld\n", ans);

    return 0; // Exiting the program after printing the result
}

// Function to compare two integers for sorting
int cmpfunc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// End of code
