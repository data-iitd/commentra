#include <stdio.h>
#include <math.h>

#define MOD 1000000007

int main() {
    int n;
    scanf("%d", &n);

    int c[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }

    // Sort c in descending order
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (c[i] < c[j]) {
                int temp = c[i];
                c[i] = c[j];
                c[j] = temp;
            }
        }
    }

    // Calculate the value of b using the formula 2^(2*n-2) modulo MOD
    long long b = pow(2, 2 * n - 2);
    b %= MOD;

    // Calculate the value of a as 2*b modulo MOD
    long long a = 2 * b % MOD;

    // Initialize the variable ans to zero
    long long ans = 0;

    // Iterate through each index i from 0 to n-1 in the list c
    for (int i = 0; i < n; i++) {
        // Add the product of the current element c[i] and the sum of a and i*b to the variable ans
        ans += c[i] * (a + i * b);
        // Update the value of ans by taking the modulo of the current sum with MOD
        ans %= MOD;
    }

    // Print the value of ans as the output
    printf("%lld\n", ans);

    return 0;
}
