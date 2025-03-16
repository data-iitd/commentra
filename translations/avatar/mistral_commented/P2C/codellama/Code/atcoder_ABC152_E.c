#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Importing the fractions module and defining a function lcm to calculate the least common multiple of two numbers a and b.
long gcd(long a, long b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

long lcm(long a, long b) {
    // Calculate the greatest common divisor of a and b using the gcd function.
    long g = gcd(a, b);
    // Return the product of a and b divided by their greatest common divisor.
    return a * b / g;
}

// Setting the value of MOD to 10^9 + 7.
long MOD = 1000000007;

// Reading the input N and storing the list A of N integers.
int main() {
    int N;
    scanf("%d", &N);
    int A[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    // Initializing the variable _lcm to 1.
    long _lcm = 1;

    // Iterating through each number a in the list A and updating the value of _lcm using the lcm function.
    for (int i = 0; i < N; i++) {
        // Update the value of _lcm using the lcm function.
        _lcm = lcm(_lcm, A[i]);
    }

    // Calculating the answer ans using the formula _lcm * sum ( [ pow ( s , MOD - 2 , MOD ) for s in A ] ) % MOD.
    long ans = _lcm * sum([pow(s, MOD - 2, MOD) for s in A]) % MOD;

    // Printing the final answer.
    printf("%ld", ans);

    return 0;
}

