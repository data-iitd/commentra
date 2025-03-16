#include <stdio.h>
#include <stdlib.h>

// Function to calculate the power of a base raised to an exponent
long long Pow(long long base, unsigned int exponent) {
    long long answer = 1;
    for (unsigned int i = 0; i < exponent; i++) {
        answer *= base;
    }
    return answer;
}

// Function to calculate combinations
long long combi(int n, int k) {
    long long min = (long long)(k - 1) * (long long)k / 2; // Calculate the minimum value of the binomial coefficient
    long long max = (long long)(2 * n - k + 1) * (long long)k / 2; // Calculate the maximum value of the binomial coefficient
    return max - min + 1; // Return the number of combinations
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k); // Read the integers n and k

    long long total = 0; // Initialize the total sum of combinations
    for (int i = k; i <= n + 1; i++) {
        total += combi(n, i); // Calculate the combination and add it to the total
        total = total % (Pow(10, 9) + 7); // Apply modulo operation to prevent overflow
    }
    printf("%lld\n", total); // Print the final result

    return 0;
}
