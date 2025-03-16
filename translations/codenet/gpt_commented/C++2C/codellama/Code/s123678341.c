#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <limits.h>
#include <ctype.h>
#include <float.h>
#include <stdint.h>
#include <inttypes.h>
#include <assert.h>
#include <complex.h>
#include <errno.h>
#include <fenv.h>
#include <iso646.h>
#include <setjmp.h>
#include <signal.h>
#include <stdalign.h>
#include <stdarg.h>
#include <stdatomic.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tgmath.h>
#include <wchar.h>
#include <wctype.h>

// Type definitions for convenience
typedef long long ll;
typedef struct {
    int x;
    int y;
} PII;
typedef struct {
    ll x;
    ll y;
} PLL;

// Constants for large values and precision
#define fs first
#define sc second
#define INF 1000000000
#define MOD 1000000007
#define EPS 0.00000001

int main() {
    // Input the sizes of the three arrays and the number K
    int X, Y, Z, K; 
    scanf("%d %d %d %d", &X, &Y, &Z, &K);

    // Declare vectors to hold the input values
    ll *A = (ll *)malloc(X * sizeof(ll));
    ll *B = (ll *)malloc(Y * sizeof(ll));
    ll *C = (ll *)malloc(Z * sizeof(ll));

    // Read values into vector A
    for(int i = 0; i < X; i++) {
        scanf("%lld", &A[i]);
    }

    // Read values into vector B
    for(int i = 0; i < Y; i++) {
        scanf("%lld", &B[i]);
    }

    // Read values into vector C
    for(int i = 0; i < Z; i++) {
        scanf("%lld", &C[i]);
    }

    // Sort the vectors in descending order to facilitate maximum sum calculations
    qsort(A, X, sizeof(ll), compare_ll);
    qsort(B, Y, sizeof(ll), compare_ll);
    qsort(C, Z, sizeof(ll), compare_ll);

    // Create a vector to store the sums of elements from A and B
    ll *AB = (ll *)malloc((X * Y) * sizeof(ll));

    // Calculate all possible sums of elements from A and B
    for(int i = 0; i < X; i++) {
        for(int j = 0; j < Y; j++) {
            AB[i * Y + j] = A[i] + B[j];
        }
    }

    // Sort the sums in descending order
    qsort(AB, X * Y, sizeof(ll), compare_ll);

    // Create a vector to store the final sums including elements from C
    ll *ABC = (ll *)malloc((X * Y * Z) * sizeof(ll));

    // Calculate sums of the top K elements from AB with each element from C
    for(int i = 0; i < min(K, (int)(X * Y)); i++) {
        for(int j = 0; j < Z; j++) {
            ABC[i * Z + j] = AB[i] + C[j];
        }
    }

    // Sort the final sums in descending order
    qsort(ABC, X * Y * Z, sizeof(ll), compare_ll);

    // Output the top K sums from the final vector
    for(int i = 0; i < K; i++) {
        printf("%lld\n", ABC[i]);
    }

    return 0;
}

int compare_ll(const void *a, const void *b) {
    ll *A = (ll *)a;
    ll *B = (ll *)b;
    return (*A > *B) - (*A < *B);
}

