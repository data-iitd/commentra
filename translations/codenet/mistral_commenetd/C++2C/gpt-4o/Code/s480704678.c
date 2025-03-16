#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007LL

// Function to read an integer
int read_int() {
    int x;
    scanf("%d", &x);
    return x;
}

// Function to read a long long integer
long long read_long_long() {
    long long x;
    scanf("%lld", &x);
    return x;
}

int main() {
    // Read the number of elements in the array 'a'
    int n = read_int();

    // Initialize an array 'a' of size 'n'
    long long *a = (long long *)malloc(n * sizeof(long long));

    // Initialize an array 'acc' of size 'n+1' with zero as initial value
    long long *acc = (long long *)malloc((n + 1) * sizeof(long long));
    acc[0] = 0;

    // Read the elements of the array 'a' and calculate the cumulative sum
    for (int i = 0; i < n; i++) {
        a[i] = read_long_long();

        // Update the cumulative sum 'acc' for the current index 'i+1'
        acc[i + 1] = (acc[i] + a[i]) % MOD;
    }

    // Initialize the answer 'ans' to zero
    long long ans = 0;

    // Calculate the answer using the formula
    for (int i = 0; i < n; i++) {
        // Calculate the contribution of the current element 'a[i]' to the answer
        long long temp = (a[i] % MOD) * ((MOD + acc[n] - acc[i + 1]) % MOD) % MOD;

        // Add the contribution to the answer
        ans = (ans + temp) % MOD;
    }

    // Print the answer
    printf("%lld\n", ans);

    // Free allocated memory
    free(a);
    free(acc);

    // Terminate the program
    return 0;
}

// <END-OF-CODE>
