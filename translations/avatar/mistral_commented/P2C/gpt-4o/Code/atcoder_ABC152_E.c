#include <stdio.h>

// Function to calculate the greatest common divisor (GCD) using the Euclidean algorithm.
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to calculate the least common multiple (LCM) of two numbers a and b.
int lcm(int a, int b) {
    return (a / gcd(a, b)) * b; // LCM(a, b) = (a * b) / GCD(a, b)
}

int main() {
    // Setting the value of MOD to 10^9 + 7.
    const int MOD = 1000000007;
    
    // Reading the input N.
    int N;
    scanf("%d", &N);
    
    // Declaring an array A to store N integers.
    int A[N];
    
    // Reading the N integers into the array A.
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    
    // Initializing the variable _lcm to 1.
    long long _lcm = 1;
    
    // Iterating through each number a in the array A and updating the value of _lcm using the lcm function.
    for (int i = 0; i < N; i++) {
        _lcm = lcm(_lcm, A[i]);
    }
    
    // Calculating the answer ans using the formula _lcm * sum ( [ pow ( s , MOD - 2 , MOD ) for s in A ] ) % MOD.
    long long ans = _lcm;
    for (int i = 0; i < N; i++) {
        // Using modular exponentiation to calculate pow(A[i], MOD - 2, MOD)
        long long inv = 1, base = A[i], exp = MOD - 2;
        while (exp > 0) {
            if (exp % 2 == 1) {
                inv = (inv * base) % MOD;
            }
            base = (base * base) % MOD;
            exp /= 2;
        }
        ans = (ans + inv) % MOD;
    }
    
    // Final answer calculation
    ans = (_lcm * ans) % MOD;
    
    // Printing the final answer.
    printf("%lld\n", ans);
    
    return 0;
}

// <END-OF-CODE>
