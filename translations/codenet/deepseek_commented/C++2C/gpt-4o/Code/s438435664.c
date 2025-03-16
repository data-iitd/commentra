#include <stdio.h>

typedef long long ll;

// Computes the greatest common divisor of two numbers x and y
ll gcd(ll x, ll y) {
    ll tmp = 0;
    if (x < y) {
        tmp = x;
        x = y;
        y = tmp;
    }
    while (y > 0) {
        ll r = x % y;
        x = y;
        y = r;
    }
    return x;
}

// Computes the least common multiple of two numbers x and y
ll lcm(ll x, ll y) {
    return x / gcd(x, y) * y;
}

// Computes the factorial of a number k modulo 10^9 + 7
ll kaijo(ll k) {
    ll sum = 1;
    for (ll i = 1; i <= k; ++i) {
        sum *= i;
        sum %= 1000000000 + 7;
    }
    return sum;
}

// Utility functions to find the maximum and minimum of two numbers
ll lmax(ll s, ll t) {
    return (s > t) ? s : t;
}

ll lmin(ll s, ll t) {
    return (s < t) ? s : t;
}

// Main function
int main() {
    // Read two integers n and k
    int n, k;
    scanf("%d %d", &n, &k);
    ll sum = 0;

    // Iterate over possible values of b
    for (int b = 1; b <= n; b++) {
        // Calculate the count and remainder
        int cnt = (n + 1) / b;
        int md = (n + 1) % b;

        // Update the sum based on the conditions involving k
        sum += cnt * lmax((b - k), 0) + lmax((md - k), 0);

        // Adjust the sum if k is 0
        if (k == 0) sum--;
    }

    // Print the computed sum
    printf("%lld\n", sum);
    return 0;
}

// <END-OF-CODE>
