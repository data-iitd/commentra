#include <stdio.h>

typedef long long ll;

<<<<<<< HEAD
// Function to calculate the greatest common divisor
=======
// Greatest Common Divisor
>>>>>>> 98c87cb78a (data updated)
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

<<<<<<< HEAD
// Function to calculate the least common multiple
=======
// Least Common Multiple
>>>>>>> 98c87cb78a (data updated)
ll lcm(ll x, ll y) {
    return x / gcd(x, y) * y;
}

<<<<<<< HEAD
// Function to calculate factorial
=======
// Factorial
>>>>>>> 98c87cb78a (data updated)
ll kaijo(ll k) {
    ll sum = 1;
    for (ll i = 1; i <= k; ++i) {
        sum *= i;
        sum %= 1000000000 + 7;
    }
    return sum;
}

<<<<<<< HEAD
// Function to return the maximum of two numbers
=======
>>>>>>> 98c87cb78a (data updated)
ll lmax(ll s, ll t) {
    return (s > t) ? s : t;
}

<<<<<<< HEAD
// Function to return the minimum of two numbers
=======
>>>>>>> 98c87cb78a (data updated)
ll lmin(ll s, ll t) {
    return (s < t) ? s : t;
}

// Main function
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    ll sum = 0;
    for (int b = 1; b <= n; b++) {
        int cnt = (n + 1) / b;
        int md = (n + 1) % b;
<<<<<<< HEAD
        sum += cnt * lmax((b - k), 0) + lmax((md - k), 0);
=======
        sum += cnt * (b - k > 0 ? b - k : 0) + (md - k > 0 ? md - k : 0);
>>>>>>> 98c87cb78a (data updated)
        if (k == 0) sum--;
    }
    printf("%lld\n", sum);
    return 0;
}

// <END-OF-CODE>
