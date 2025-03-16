#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

// Type definitions for convenience
typedef long long ll;
typedef struct {
    int first;
    int second;
} PII;

typedef struct {
    long long first;
    long long second;
} PLL;

// Constants for large values and precision
#define fs first
#define sc second
#define INF 1000000000
#define MOD 1000000007
#define EPS 0.00000001

int compare_long_long(const void *a, const void *b) {
    long long l = *(long long *)a;
    long long r = *(long long *)b;
    if (l < r) return 1;
    if (l > r) return -1;
    return 0;
}

int main() {
    // Input the sizes of the three arrays and the number K
    int X, Y, Z, K; 
    scanf("%d %d %d %d", &X, &Y, &Z, &K);

    // Declare arrays to hold the input values
    ll A[X];
    ll B[Y];
    ll C[Z];

    // Read values into array A
    for(int i = 0; i < X; i++) {
        scanf("%lld", &A[i]);
    }

    // Read values into array B
    for(int i = 0; i < Y; i++) {
        scanf("%lld", &B[i]);
    }

    // Read values into array C
    for(int i = 0; i < Z; i++) {
        scanf("%lld", &C[i]);
    }

    // Sort the arrays in descending order to facilitate maximum sum calculations
    qsort(A, X, sizeof(ll), compare_long_long);
    qsort(B, Y, sizeof(ll), compare_long_long);
    qsort(C, Z, sizeof(ll), compare_long_long);

    // Create an array to store the sums of elements from A and B
    ll AB[X * Y];
    int ab_index = 0;

    // Calculate all possible sums of elements from A and B
    for(int i = 0; i < X; i++) {
        for(int j = 0; j < Y; j++) {
            AB[ab_index++] = A[i] + B[j];
        }
    }

    // Sort the sums in descending order
    qsort(AB, X * Y, sizeof(ll), compare_long_long);

    // Create an array to store the final sums including elements from C
    ll ABC[K * Z];
    int abc_index = 0;

    // Calculate sums of the top K elements from AB with each element from C
    for(int i = 0; i < (X * Y < K ? X * Y : K); i++) {
        for(int j = 0; j < Z; j++) {
            ABC[abc_index++] = AB[i] + C[j];
        }
    }

    // Sort the final sums in descending order
    qsort(ABC, K * Z, sizeof(ll), compare_long_long);

    // Output the top K sums from the final array
    for(int i = 0; i < K; i++) {
        printf("%lld\n", ABC[i]);
    }

    return 0;
}
