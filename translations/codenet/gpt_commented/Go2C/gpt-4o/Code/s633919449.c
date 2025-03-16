#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

<<<<<<< HEAD
=======
#define INITIAL_BUF_SIZE 10000
#define MAX_BUF_SIZE 1000000
>>>>>>> 98c87cb78a (data updated)
#define MOD 1000000007

// Function to read an integer from input
int getInt() {
    int n;
    scanf("%d", &n);
    return n;
}

// Function to calculate the absolute value of an integer
int abs(int a) {
    return a < 0 ? -a : a;
}

// Function to calculate p raised to the power of q
int pow(int p, int q) {
    return (int)pow((double)p, (double)q);
}

// Function to calculate n raised to the power of p modulo mod
int powMod(int n, int p) {
    if (p == 0) return 1;
    if (p % 2 == 0) {
        int t = powMod(n, p / 2);
        return (t * t) % MOD;
    } else {
        return (n * powMod(n, p - 1)) % MOD;
    }
}

<<<<<<< HEAD
// Function to calculate the minimum value among a list of integers
=======
// Function to find the minimum value among a list of integers
>>>>>>> 98c87cb78a (data updated)
int min(int count, ...) {
    va_list args;
    va_start(args, count);
    int res = va_arg(args, int);
    for (int i = 1; i < count; i++) {
        int num = va_arg(args, int);
        if (num < res) res = num;
    }
    va_end(args);
    return res;
}

<<<<<<< HEAD
// Function to calculate the maximum value among a list of integers
=======
// Function to find the maximum value among a list of integers
>>>>>>> 98c87cb78a (data updated)
int max(int count, ...) {
    va_list args;
    va_start(args, count);
    int res = va_arg(args, int);
    for (int i = 1; i < count; i++) {
        int num = va_arg(args, int);
        if (num > res) res = num;
    }
    va_end(args);
    return res;
}

// Function to check if a number is prime
bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    int sqrtN = (int)sqrt((double)n);
    for (int i = 3; i <= sqrtN; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

// Function to calculate the greatest common divisor (GCD) of two integers
int calcGcd(int x, int y) {
    if (y == 0) return x;
    return calcGcd(y, x % y);
}

// Function to get all divisors of a number
int* getDivisor(int n, int* size) {
    int* divisors = malloc(n * sizeof(int));
    *size = 0;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            divisors[(*size)++] = i;
            if (i != n / i) {
                divisors[(*size)++] = n / i;
            }
        }
    }
    return divisors;
}

// Main function
int main() {
<<<<<<< HEAD
    // Read an integer input
=======
>>>>>>> 98c87cb78a (data updated)
    int N = getInt();

    // Determine the output based on the last digit of N
    switch (N % 10) {
        case 2: case 4: case 5: case 7: case 9:
            printf("hon\n");
            break;
        case 0: case 1: case 6: case 8:
            printf("pon\n");
            break;
        case 3:
            printf("bon\n");
            break;
    }

    return 0;
}

<<<<<<< HEAD
// Note: Other functions from the Go code can be implemented similarly if needed.
// <END-OF-CODE>
=======
// Note: The graph-related functions, heap implementation, and other utility functions have been omitted for brevity.
// You can implement them similarly in C if needed.

>>>>>>> 98c87cb78a (data updated)
