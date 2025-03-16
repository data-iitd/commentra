
#include <stdio.h>
#include <math.h>

typedef long long ll;

ll gcd(ll a, ll b) {
    // Calculate the greatest common divisor (GCD) of two numbers a and b
    return b? gcd(b, a % b) : a;
}

ll lcm(ll a, ll b) {
    // Calculate the least common multiple (LCM) of two numbers a and b
    return a * b / gcd(a, b);
}

const ll MOD = 100000007;  // Define a constant MOD for modular arithmetic

int main() {
    int N;  // Read the number of elements from user input
    scanf("%d", &N);

    ll A[N];  // Read a list of integers from user input
    for (int i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
    }

    ll _lcm = 1;  // Initialize the variable to store the LCM of the list
    for (int i = 0; i < N; i++) {
        // Update the LCM by calculating the LCM of the current LCM and the next element
        _lcm = lcm(_lcm, A[i]);
    }

    ll ans = _lcm;  // Initialize the variable to store the final answer
    for (int i = 0; i < N; i++) {
        // Update the final answer by multiplying it with the modular inverse of the current element
        ans = ans * pow(A[i], MOD - 2, MOD) % MOD;
    }

    // Print the result, ensuring it is within the bounds of MOD
    printf("%lld\n", ans);

    return 0;
}
