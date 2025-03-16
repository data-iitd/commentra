#include <stdio.h>
#include <stdbool.h>

typedef long long ll;
#define MOD 1000000007

// Function to check if a number is prime
bool is_prime(ll x) {
    // Check for edge cases
    if (x <= 1) return false;
    if (x == 2) return true;

    // Check for composite numbers up to the square root of x
    for (ll i = 2; i * i <= x; i++) {
        // If x is divisible by i, it's not prime
        if (x % i == 0) return false;
    }

    // If we've made it this far, x is prime
    return true;
}

int main() {
    // Read the input number N
    int N;
    scanf("%d", &N);

    // Initialize answer to 1
    ll ans = 1;

    // Iterate through all numbers from 2 to N
    for (int i = 2; i <= N; i++) {
        // If the number is prime, calculate its contribution to the answer
        if (is_prime((ll)i)) {
            // Initialize variables for counting prime factors and total count
            int NN = N;
            int cnt = 0;

            // Count the number of occurrences of i as a factor in N
            while (NN) {
                // Increment the count
                cnt += NN / i;

                // Update NN to the next number without the current factor
                NN /= i;
            }

            // Multiply the answer by the count and update it modulo MOD
            ans *= (cnt + 1);
            ans %= MOD;
        }
    }

    // Print the final answer
    printf("%lld\n", ans);

    // Return 0 to indicate successful execution
    return 0;
}

// <END-OF-CODE>
