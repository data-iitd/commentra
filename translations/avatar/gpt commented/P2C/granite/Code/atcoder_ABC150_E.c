
#include <stdio.h>
#include <stdlib.h>

// Define the modulo constant
#define mod 100000007

int main() {
    // Read the number of elements
    int n;
    scanf("%d", &n);

    // Read the list of integers and convert them to an array of integers
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
    long long b = 1;
    for (int i = 0; i < 2 * n - 2; i++) {
        b = (b * 2) % mod;
    }

    // Calculate the value of a as 2 * b modulo mod
    long long a = (2 * b) % mod;

    // Initialize the answer variable
    long long ans = 0;

    // Iterate through the sorted array and calculate the answer
    for (int i = 0; i < n; i++) {
        // Update the answer by adding the product of the current element and (a + i * b)
        ans = (ans + c[i] * ((a + i * b) % mod)) % mod;
    }

    // Print the final result
    printf("%lld\n", ans);

    return 0;
}
