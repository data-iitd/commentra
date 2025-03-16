#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define long long type as ll for convenience
typedef long long ll;

// Define constants for large values and mathematical constants
const int inf = 1e9 + 7;
const ll mod = 1e9 + 7;
const ll mod1 = 998244353;
const ll big = 1e18;
const double PI = 2 * asin(1);

int compare(const void *a, const void *b) {
    return (*(ll *)b - *(ll *)a); // Sort in descending order
}

int main() {
    // Read the number of elements
    int N;
    scanf("%d", &N);

    // Initialize an array to store the elements
    ll *A = (ll *)malloc(N * sizeof(ll));

    // Input the elements into the array
    for (int i = 0; i < N; ++i) {
        scanf("%lld", &A[i]);
    }

    // Sort the array in descending order
    qsort(A, N, sizeof(ll), compare);

    // Initialize variables to track the minimum difference and the corresponding index
<<<<<<< HEAD
    int index = -1;
=======
    int index = 0;
>>>>>>> 98c87cb78a (data updated)
    ll max_diff = inf;

    // Find the element in the array that minimizes the difference with twice the second largest element
    for (int i = 1; i < N; ++i) {
        // Calculate the absolute difference and update if it's smaller than the current max
        ll diff = llabs(A[0] - 2 * A[i]);
        if (max_diff > diff) {
            max_diff = diff;
            index = i; // Store the index of the element that gives the minimum difference
        }
    }

    // Output the largest element and the element that minimizes the difference
    printf("%lld %lld\n", A[0], A[index]);

    // Free the allocated memory
    free(A);

    return 0;
}

// <END-OF-CODE>
