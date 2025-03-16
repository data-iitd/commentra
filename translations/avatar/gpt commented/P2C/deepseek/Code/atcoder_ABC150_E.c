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

    // Sort the array in descending order
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (c[i] < c[j]) {
                int temp = c[i];
                c[i] = c[j];
                c[j] = temp;
            }
        }
    }

    // Calculate the value of b as 2^(2*n - 2) modulo mod
    long long b = pow(2, 2 * n - 2);
    b %= MOD;

    // Calculate the value of a as 2 * b modulo mod
    long long a = 2 * b % MOD;

    // Initialize the answer variable
    long long ans = 0;

    // Iterate through the sorted list and calculate the answer
    for (int i = 0; i < n; i++) {
        // Update the answer by adding the product of the current element and (a + i * b)
        ans += c[i] * (a + i * b);
        // Ensure the answer remains within the modulo
        ans %= MOD;
    }

    // Print the final result
    printf("%lld\n", ans);

    return 0;
}
