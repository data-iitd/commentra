

#include <stdio.h> // Standard input/output library
#include <stdlib.h> // Standard library for memory allocation and other functions
#include <string.h> // Standard library for string manipulation functions

int main() {
    // Read input
    int n, m; // Number of elements in array a and modulus value
    scanf("%d %d", &n, &m); // Read n and m from standard input

    // Initialize data structures
    int a[n]; // Array a to store input elements
    int dp[m]; // Hashmap to store intermediate results
    memset(dp, 0, sizeof(dp)); // Initialize hashmap with zeros

    // Read array a
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]); // Read each element of array a from standard input
    }

    // Initialize variables
    long long ans = 0; // Answer variable
    int base = 0; // Base value for hashmap key

    // Process each element in array a
    for (int i = 0; i < n; i++) {
        // Update base value
        base = (base - a[i] % m + m) % m;

        // Update hashmap with current base and its count
        dp[(base + a[i] % m) % m]++;

        // Update answer variable
        ans += dp[base];
    }

    // Print the answer
    printf("%lld\n", ans); // Print the answer to standard output

    return 0; // Return 0 to indicate successful execution
}

