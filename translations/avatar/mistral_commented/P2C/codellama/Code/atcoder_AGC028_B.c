#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define constant value
#define MOD 1000000007

// Define function to calculate factorial
long long factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1) % MOD;
}

// Define function to calculate inverse of a number
long long inverse(int n) {
    return pow(n + 1, MOD - 2) % MOD;
}

// Define function to calculate cumulative sum of an array
void cumulative_sum(int *arr, int n) {
    for (int i = 1; i < n; i++) {
        arr[i] += arr[i - 1];
        arr[i] %= MOD;
    }
}

// Define function to calculate the answer
long long calculate(int *arr, int n) {
    // Calculate factorial of each element in the array
    long long fact[n];
    for (int i = 0; i < n; i++) {
        fact[i] = factorial(i);
    }

    // Calculate inverse of each element in the array
    int inv[n];
    for (int i = 0; i < n; i++) {
        inv[i] = inverse(i);
    }

    // Calculate cumulative sum of the array inv
    cumulative_sum(inv, n);

    // Calculate temporary array temp using elements from j and inv
    int temp[n];
    for (int i = 0; i < n; i++) {
        temp[i] = inv[i] + inv[n - 1 - i] - 1;
        temp[i] %= MOD;
    }

    // Calculate the answer ans using given formula
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += arr[i] * temp[i];
        ans %= MOD;
    }

    // Multiply the answer ans with the last element of fact array
    ans *= fact[n - 1];

    // Modulo the answer ans with given constant value MOD
    ans %= MOD;

    return ans;
}

int main() {
    // Read input number of elements N
    int n;
    scanf("%d", &n);

    // Define a constant value for the size of the 2D array A
    int m = 1000000;

    // Initialize 2D array A with given size and input data
    int a[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Calculate the answer ans using given formula
    long long ans = calculate(a[0], n);

    // Print the answer ans
    printf("%lld\n", ans);

    return 0;
}

