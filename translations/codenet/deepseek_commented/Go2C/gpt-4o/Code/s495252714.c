#include <stdio.h>
#include <stdlib.h>

// Define the constant for modular arithmetic.
const int mod = 1000000007;

// Function to perform modular exponentiation.
int modpow(int a, int n) {
    int res = 1;
    while (n > 0) {
        if (n & 1) {
<<<<<<< HEAD
            res = (res * 1LL * a) % mod;
        }
        a = (a * 1LL * a) % mod;
=======
            res = (1LL * res * a) % mod;
        }
        a = (1LL * a * a) % mod;
>>>>>>> 98c87cb78a (data updated)
        n >>= 1;
    }
    return res;
}

<<<<<<< HEAD
=======
// Comparison function for qsort.
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

>>>>>>> 98c87cb78a (data updated)
int main() {
    // Read the number of elements.
    int n;
    scanf("%d", &n);

<<<<<<< HEAD
    // Allocate memory for the array of integers.
    int *c = (int *)malloc(n * sizeof(int));

    // Read n integers into the array.
=======
    // Read n integers into an array.
    int *c = (int *)malloc(n * sizeof(int));
>>>>>>> 98c87cb78a (data updated)
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }

    // Initialize the answer variable.
    long long ans = 0;

    // Sort the array of integers.
<<<<<<< HEAD
    qsort(c, n, sizeof(int), (int (*)(const void *, const void *))compare);
=======
    qsort(c, n, sizeof(int), compare);
>>>>>>> 98c87cb78a (data updated)

    // Calculate the answer based on the sorted array.
    for (int i = 0; i < n; i++) {
        ans = (ans + (long long)(n + 1 - i) * c[i] % mod) % mod;
    }

    // Print the final answer, multiplied by 4^(n-1) modulo mod.
<<<<<<< HEAD
    printf("%lld\n", ans * modpow(4, n - 1) % mod);
=======
    printf("%lld\n", (ans * modpow(4, n - 1)) % mod);
>>>>>>> 98c87cb78a (data updated)

    // Free the allocated memory.
    free(c);
    return 0;
}

<<<<<<< HEAD
// Comparison function for qsort.
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
=======
// <END-OF-CODE>
>>>>>>> 98c87cb78a (data updated)
