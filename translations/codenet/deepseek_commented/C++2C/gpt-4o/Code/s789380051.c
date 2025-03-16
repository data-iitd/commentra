#include <stdio.h>

typedef long long LL;

#define MOD 1000000007

// Function to calculate x^n % MOD using bitwise operations
LL mod_pow(LL x, LL n) {
    LL ans = 1;
    while (n > 0) {
        if ((n & 1) == 1) { // Check if the least significant bit is 1
            ans = ans * x % MOD; // Update ans if the bit is set
        }
        x = x * x % MOD; // Square x and take modulo MOD
        n >>= 1; // Shift n right by 1 bit (divide by 2)
    }
    return ans;
}

// Function to calculate combination C(n, r) % MOD
LL comb_s(LL n, LL r) {
    LL tmp_n = 1;
    LL tmp_d = 1;
    LL ans = 0; // Initialize ans
    for (int i = 1; i <= r; i++) {
        tmp_n = (tmp_n * (n + 1 - i)) % MOD; // Compute the numerator
        tmp_d = (tmp_d * i) % MOD; // Compute the denominator
        ans = tmp_n * mod_pow(tmp_d, MOD - 2) % MOD; // Compute the combination
    }
    return ans;    
}

int main() {
    LL n;
    LL a;
    LL b;
    LL ans = 1;

    scanf("%lld %lld %lld", &n, &a, &b); // Read input values for n, a, and b
    ans = mod_pow(2, n); // Calculate 2^n % MOD
    ans--; // Subtract 1 from ans
    LL tmp_nd = comb_s(n, a); // Calculate C(n, a) % MOD
    ans = (ans - tmp_nd) % MOD; // Subtract the combination from ans
    while (ans < 0) { // Handle negative results
        ans += MOD;
    }

    tmp_nd = comb_s(n, b); // Calculate C(n, b) % MOD
    ans = (ans - tmp_nd) % MOD; // Subtract the combination from ans
    while (ans < 0) { // Handle negative results
        ans += MOD;
    }

    printf("%lld\n", ans); // Output the final result

    return 0;
}

// <END-OF-CODE>
