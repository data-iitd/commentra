
#include <stdio.h>
#include <math.h>

typedef long long ll;

// Define a function to calculate the greatest common divisor (GCD) of two numbers
ll gcd(ll a, ll b) {
    return b? gcd(b, a % b) : a;  // Using the Euclidean algorithm to calculate the GCD
}

#define MOD 100000007  // Define a constant MOD for modulo operations

int main() {
    int N;  // Read the number of elements in the list A
    scanf("%d", &N);

    ll A[N];  // Read the list A as integers
    for (int i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
    }

    ll _lcm = 1;  // Initialize _lcm to 1
    for (int i = 0; i < N; i++) {
        _lcm = _lcm * A[i] / gcd(_lcm, A[i]);  // Update _lcm to be the LCM of _lcm and the current element
    }

    ll ans = _lcm;  // Initialize ans to _lcm
    for (int i = 0; i < N; i++) {
        ans = ans * pow(A[i], MOD - 2, MOD) % MOD;  // Update ans by multiplying it with the modular inverse of A[i] modulo MOD
    }

    printf("%lld\n", ans);  // Print the result, ensuring it is within the modulo range

    return 0;
}
