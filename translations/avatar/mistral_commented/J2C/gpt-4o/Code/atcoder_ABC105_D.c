#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100000 // Assuming a maximum size for the array

// Function to read an integer from input
int readInt() {
    int x;
    scanf("%d", &x);
    return x;
}

// Function to read an array of integers
void readIntArray(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = readInt();
    }
}

// Function to solve the problem
long long solve(int n, int m) {
    int a[MAX_N];
    readIntArray(a, n); // Read the array a

    long long ans = 0; // Answer variable
    int base = 0; // Base value for hashmap key
    int dp[MAX_N] = {0}; // Hashmap to store intermediate results, assuming a maximum size

    // Process each element in array a
    for (int i = 0; i < n; i++) {
        // Update base value
        base = (base - (a[i] % m) + m) % m;

        // Update hashmap with current base and its count
        dp[base + (a[i] % m)]++;

        // Update answer variable
        ans += dp[base];
    }

    return ans; // Return the answer
}

// Main function
int main() {
    int n = readInt(); // Number of elements in array a
    int m = readInt(); // Modulus value

    long long result = solve(n, m); // Solve the problem
    printf("%lld\n", result); // Print the answer

    return 0; // Return success
}

// <END-OF-CODE>
