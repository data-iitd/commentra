#include <stdio.h>
#include <stdlib.h>

// Function to calculate power of a base raised to an exponent.
long long Pow(long long base, unsigned int exponent) {
    long long answer = 1;
    for (unsigned int i = 0; i < exponent; i++) {
        answer *= base;
    }
    return answer;
}

// Function to calculate combinations of n taken k at a time.
long long combi(int n, int k) {
    long long min = (long long)(k - 1) * k / 2;
    long long max = (long long)(2 * n - k + 1) * k / 2;
    return max - min + 1;
}

// Main function
int main() {
    int n, k;
    // Read n and k from standard input
    scanf("%d %d", &n, &k);

    long long total = 0;
    const long long MOD = Pow(10, 9) + 7;

    // Calculate the sum of combinations from k to n + 1
    for (int i = k; i <= n + 1; i++) {
        long long comb = combi(n, i);
        total = (total + comb) % MOD;
    }

    // Print the result
    printf("%lld\n", total);
    return 0;
}

// <END-OF-CODE>
