#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define INF (1 << 29)
#define LL long long int

LL const MOD = 1000000007; // Constants definition

int main() {
    // Input section
    LL n, c; // Declare variables n and c for number of elements and capacity
    scanf("%lld %lld", &n, &c); // Read input values for n and c from standard input

    LL *x = (LL *)malloc((n + 1) * sizeof(LL)); // Allocate memory for x
    LL *v = (LL *)malloc((n + 1) * sizeof(LL)); // Allocate memory for v

    for (int i = 1; i <= n; i++) { // Loop through each element in the array
        scanf("%lld %lld", &x[i], &v[i]); // Read input values for x[i] and v[i] from standard input
    }

    // Calculate left prefix sums
    LL *lefttotal = (LL *)malloc((n + 1) * sizeof(LL)); // Allocate memory for lefttotal
    LL *maxlefttotal = (LL *)malloc((n + 1) * sizeof(LL)); // Allocate memory for maxlefttotal
    memset(lefttotal, 0, (n + 1) * sizeof(LL)); // Initialize lefttotal to 0
    memset(maxlefttotal, 0, (n + 1) * sizeof(LL)); // Initialize maxlefttotal to 0

    for (int i = 1; i <= n; i++) {
        lefttotal[i] = lefttotal[i - 1] + v[i]; // Calculate prefix sums of vector v
        maxlefttotal[i] = (maxlefttotal[i - 1] > (lefttotal[i] - x[i])) ? maxlefttotal[i - 1] : (lefttotal[i] - x[i]); // Calculate maximum prefix sums excluding current element
    }

    // Calculate right prefix sums
    LL *righttotal = (LL *)malloc((n + 1) * sizeof(LL)); // Allocate memory for righttotal
    LL *maxrighttotal = (LL *)malloc((n + 1) * sizeof(LL)); // Allocate memory for maxrighttotal
    memset(righttotal, 0, (n + 1) * sizeof(LL)); // Initialize righttotal to 0
    memset(maxrighttotal, 0, (n + 1) * sizeof(LL)); // Initialize maxrighttotal to 0

    for (int i = 1; i <= n; i++) {
        righttotal[i] = righttotal[i - 1] + v[n - i + 1]; // Calculate prefix sums of reversed vector v
        maxrighttotal[i] = (maxrighttotal[i - 1] > (righttotal[i] - (c - x[n + 1 - i]))) ? maxrighttotal[i - 1] : (righttotal[i] - (c - x[n + 1 - i])); // Calculate maximum prefix sums excluding current element
    }

    // Calculate answer
    LL ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = (ans > (lefttotal[i] - x[i])) ? ans : (lefttotal[i] - x[i]); // Calculate maximum sum by including current element in left sum
        ans = (ans > (lefttotal[i] - 2 * x[i] + maxrighttotal[n - i])) ? ans : (lefttotal[i] - 2 * x[i] + maxrighttotal[n - i]); // Calculate maximum sum by excluding current element in left sum and including it in right sum
        ans = (ans > (righttotal[i] - (c - x[n + 1 - i]))) ? ans : (righttotal[i] - (c - x[n + 1 - i])); // Calculate maximum sum by including current element in right sum
        ans = (ans > (righttotal[i] - 2 * (c - x[n + 1 - i]) + maxlefttotal[n - i])) ? ans : (righttotal[i] - 2 * (c - x[n + 1 - i]) + maxlefttotal[n - i]); // Calculate maximum sum by excluding current element in right sum and including it in left sum
    }

    // Output answer
    printf("%lld\n", ans);

    // Free allocated memory
    free(x);
    free(v);
    free(lefttotal);
    free(maxlefttotal);
    free(righttotal);
    free(maxrighttotal);

    return 0;
}

// <END-OF-CODE>
