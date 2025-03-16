#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the modulo constant
const int mod = 1000000007;

// Read the number of elements
int n;
scanf("%d", &n);

// Read the list of integers and convert them to a list of integers
int *c = (int *)malloc(n * sizeof(int));
for (int i = 0; i < n; i++) {
    scanf("%d", &c[i]);
}

// Sort the list in descending order
qsort(c, n, sizeof(int), compare);

// Calculate the value of b as 2^(2*n - 2) modulo mod
int b = pow(2, 2 * n - 2, mod);

// Calculate the value of a as 2 * b modulo mod
int a = 2 * b % mod;

// Initialize the answer variable
int ans = 0;

// Iterate through the sorted list and calculate the answer
for (int i = 0; i < n; i++) {
    // Update the answer by adding the product of the current element and (a + i * b)
    ans += c[i] * (a + i * b);
    // Ensure the answer remains within the modulo
    ans %= mod;
}

// Print the final result
printf("%d\n", ans);

// Free the memory allocated for the list
free(c);

// End of code
