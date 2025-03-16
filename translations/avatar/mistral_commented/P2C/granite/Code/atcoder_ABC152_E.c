
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the greatest common divisor of two numbers a and b.
int gcd(int a, int b) {
    // Base case: if b is 0, return a.
    if (b == 0) {
        return a;
    }
    // Recursive case: return the greatest common divisor of b and a % b.
    return gcd(b, a % b);
}

// Function to calculate the least common multiple of two numbers a and b.
int lcm(int a, int b) {
    // Return the product of a and b divided by their greatest common divisor.
    return a * b / gcd(a, b);
}

int main() {
    // Setting the value of MOD to 10^9 + 7.
    const int MOD = 100000007;

    // Reading the input N and storing the list A of N integers.
    int N;
    scanf("%d", &N);
    int A[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    // Initializing the variable _lcm to 1.
    int _lcm = 1;

    // Iterating through each number a in the list A and updating the value of _lcm using the lcm function.
    for (int i = 0; i < N; i++) {
        _lcm = lcm(_lcm, A[i]);
    }

    // Calculating the answer ans using the formula _lcm * sum ( [ pow ( s, MOD - 2, MOD ) for s in A ] ) % MOD.
    int ans = _lcm;
    for (int i = 0; i < N; i++) {
        ans = (long long)ans * pow(A[i], MOD - 2, MOD) % MOD;
    }

    // Printing the final answer.
    printf("%d\n", ans);

    return 0;
}
