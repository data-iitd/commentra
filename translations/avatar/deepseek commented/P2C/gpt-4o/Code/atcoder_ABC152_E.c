#include <stdio.h>

// Function to calculate the greatest common divisor (GCD) using the Euclidean algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to calculate the least common multiple (LCM) of two numbers
long long lcm(int a, int b) {
    return (long long)a * b / gcd(a, b);
}

// Function to perform modular exponentiation
long long mod_pow(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    const long long MOD = 1000000007;  // Define a constant MOD for modulo operations
    int N;  // Number of elements in the list A
    scanf("%d", &N);  // Read the number of elements
    int A[N];  // Declare an array A of size N

    // Read the list A as integers
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    long long _lcm = 1;  // Initialize _lcm to 1
    for (int i = 0; i < N; i++) {
        _lcm = lcm(_lcm, A[i]);  // Update _lcm to be the LCM of _lcm and the current element
    }

    // Calculate ans as _lcm multiplied by the sum of modular inverses of each element in A modulo MOD
    long long sum_of_inverses = 0;
    for (int i = 0; i < N; i++) {
        sum_of_inverses = (sum_of_inverses + mod_pow(A[i], MOD - 2, MOD)) % MOD;  // Modular inverse using Fermat's little theorem
    }

    long long ans = (_lcm * sum_of_inverses) % MOD;  // Final answer

    printf("%lld\n", ans);  // Print the result

    return 0;
}  // <END-OF-CODE>
