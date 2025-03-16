#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 1001001001001001LL
#define inf 1000000007
#define MOD 1000000007LL
#define PI 3.1415926535897932

// Function to update the minimum value
void chmin(long long int *a, long long int b) {
    if (*a > b) *a = b;
}

// Function to update the maximum value
void chmax(long long int *a, long long int b) {
    if (*a < b) *a = b;
}

// Macros for convenience in iterating through containers
#define ALL(a, size) a, a + size
#define RALL(a, size) a + size - 1, a - 1

/* do your best */

int main() {
    // Read the number of elements
    int n;
    scanf("%d", &n);

    // Initialize a vector to store the input values and a vector for prefix sums
    long long int a[n];
    long long int acc[n + 1];
    memset(acc, 0, sizeof(acc));

    // Read input values and compute prefix sums modulo MOD
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        acc[i + 1] = acc[i] + a[i]; // Update prefix sum
        acc[i + 1] %= MOD; // Ensure the prefix sum is within MOD
    }

    // Initialize the answer variable
    long long int ans = 0;

    // Calculate the final answer using the prefix sums
    for (int i = 0; i < n; i++) {
        ans += a[i] % MOD * (MOD + acc[n] - acc[i + 1]) % MOD; // Update answer based on current element and remaining sum
        ans %= MOD; // Ensure the answer is within MOD
    }

    // Output the final result
    printf("%lld\n", ans);

    return 0; // End of the program
}
