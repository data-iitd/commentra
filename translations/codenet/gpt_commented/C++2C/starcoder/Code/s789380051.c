#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007

// Function to compute (x^n) % MOD using modular exponentiation
long long mod_pow(long long x, long long n){
    long long ans = 1; // Initialize result
    while(n > 0){ // Loop until n becomes 0
        if((n & 1) == 1){ // If n is odd
            ans = ans * x % MOD; // Multiply ans by x and take modulo
        }
        x = x * x % MOD; // Square x and take modulo
        n >>= 1; // Divide n by 2
    }
    return ans; // Return the result
}

// Function to compute combination C(n, r) % MOD using modular arithmetic
long long comb_s(long long n, long long r){
    long long tmp_n = 1; // Temporary variable for numerator
    long long tmp_d = 1; // Temporary variable for denominator
    long long ans; // Variable to store the final answer
    for(int i = 1; i <= r; i++){ // Loop to calculate numerator and denominator
        tmp_n = (tmp_n * (n + 1 - i)) % MOD; // Calculate numerator
        tmp_d = (tmp_d * i) % MOD; // Calculate denominator
        ans = tmp_n * mod_pow(tmp_d, MOD - 2); // Calculate combination using modular inverse
    }

    return ans; // Return the combination result
}

int main() {
    long long n; // Variable to store the total number of elements
    long long n_tmp; // Temporary variable (not used in the current code)
    long long a; // Variable to store the first subset size
    long long b; // Variable to store the second subset size
    long long ans = 1; // Initialize answer variable

    // Input the values of n, a, and b
    scanf("%lld %lld %lld", &n, &a, &b);

    // Calculate 2^n - 1 (total subsets excluding the empty set)
    ans = mod_pow(2, n);
    ans--;

    long long tmp_nd; // Temporary variable to store combinations

    // Calculate C(n, a) and subtract from ans
    tmp_nd = comb_s(n, a);
    ans = (ans - tmp_nd) % MOD; // Subtract combinations of size a
    while(ans < 0){ // Ensure ans is non-negative
        ans += MOD;
    }
    //printf("%lld %lld\n", ans, tmp_ans); // Uncomment for debugging

    // Calculate C(n, b) and subtract from ans
    tmp_nd = comb_s(n, b);
    ans = (ans - tmp_nd) % MOD; // Subtract combinations of size b
    //printf("%lld %lld\n", ans, tmp_ans); // Uncomment for debugging
    while(ans < 0){ // Ensure ans is non-negative
        ans += MOD;
    }

    // Output the final result
    printf("%lld\n", ans);

    return 0; // End of the program
}

