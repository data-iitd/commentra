
#include <stdio.h> // Include the necessary header files
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>

#define MOD 1000000007 // Define the modulo value

typedef long long ll; // Define a 64-bit integer type

ll power(ll x, ll n) { // Function to calculate x^n % MOD
    if (n == 0) {
        return 1; // Base case: x^0 is 1
    }
    ll val = power(x, n / 2); // Recursive call to calculate x^(n/2)
    val = val * val % MOD; // Squaring the result
    if (n % 2 == 1) {
        val = val * x % MOD; // Multiplying by x if n is odd
    }
    return val; // Returning the result
}

int main() {
    int n; // Define the variable n
    scanf("%d", &n); // Read the value of n from input
    int c[n]; // Define an array of size n to store the integers
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]); // Read each integer and store it in the array c
    }

    ll b = power(2, n); // Calculate 2^n
    ll a = power(2, n - 2); // Calculate 2^(n-2)
    ll ans = 0; // Initialize the answer variable

    // Calculate the final answer
    for (int i = 2; i <= n + 1; i++) {
        ll val = a * i % MOD; // Intermediate calculation
        val = val * c[n + 1 - i] % MOD; // Intermediate calculation
        ans = (ans + val) % MOD; // Adding to the answer
    }
    ans = ans * b % MOD; // Multiplying the answer by b
    printf("%lld\n", ans); // Print the final result

    return 0; // Return 0 to indicate successful execution
}

