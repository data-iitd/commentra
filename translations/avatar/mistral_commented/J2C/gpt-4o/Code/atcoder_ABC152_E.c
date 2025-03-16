#include <stdio.h>
#include <stdlib.h>

typedef long long BigInteger;

// Function to calculate gcd of two numbers
BigInteger gcd(BigInteger a, BigInteger b) {
    while (b != 0) {
        BigInteger temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to calculate lcm of two numbers
BigInteger lcm(BigInteger a, BigInteger b) {
    return (a / gcd(a, b)) * b;
}

// Function to calculate modular exponentiation
long long modPow(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Function to calculate modular inverse
long long modInv(long long x, long long mod) {
    return modPow(x, mod - 2, mod);
}

// Function to perform modular division
long long modDiv(long long a, long long b, long long mod) {
    return (a % mod) * modInv(b, mod) % mod;
}

int main() {
    int N;
    scanf("%d", &N); // Reading the number of integers N
    int *A = (int *)malloc(N * sizeof(int)); // Dynamically allocating memory for array A

    // Reading each integer in the array A
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    BigInteger lcmValue = 1; // Initializing lcm as 1
    long long mod = 1000000007; // Setting the modulus value

    // Calculating the least common multiple (lcm) of all integers in array A
    for (int i = 0; i < N; i++) {
        lcmValue = lcm(lcmValue, A[i]);
    }

    long long modLcm = lcmValue % mod; // Calculating the remainder of lcm modulo mod
    long long ans = 0; // Initializing answer variable as 0

    // Calculating the answer using modular arithmetic
    for (int i = 0; i < N; i++) {
        ans = (ans + modDiv(modLcm, A[i], mod)) % mod;
    }

    // Printing the answer
    printf("%lld\n", ans);

    // Freeing the allocated memory
    free(A);
    return 0;
}

// <END-OF-CODE>
