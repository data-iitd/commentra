
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// Structure to store intermediate results
typedef struct {
    int base;
    int count;
} hashmap;

// Function to solve the problem
void solve(int testNumber, FILE *inputFile, FILE *outputFile) {
    // Read input
    int n, m;
    fscanf(inputFile, "%d %d", &n, &m);
    int a[n];
    for (int i = 0; i < n; i++) {
        fscanf(inputFile, "%d", &a[i]);
    }

    // Initialize data structures
    hashmap dp[m];
    for (int i = 0; i < m; i++) {
        dp[i].base = 0;
        dp[i].count = 0;
    }

    // Initialize variables
    long ans = 0;
    int base = 0;

    // Process each element in array a
    for (int i = 0; i < n; i++) {
        // Update base value
        base = (base - a[i] % m + m) % m;

        // Update hashmap with current base and its count
        dp[base + a[i] % m].count++;

        // Update answer variable
        ans += dp[base].count;
    }

    // Print the answer
    fprintf(outputFile, "%ld\n", ans);
}

int main() {
    // Open input and output files
    FILE *inputFile = fopen("input.txt", "r");
    FILE *outputFile = fopen("output.txt", "w");

    // Read input
    int t;
    fscanf(inputFile, "%d", &t);

    // Solve each test case
    for (int i = 1; i <= t; i++) {
        solve(i, inputFile, outputFile);
    }

    // Close input and output files
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}

