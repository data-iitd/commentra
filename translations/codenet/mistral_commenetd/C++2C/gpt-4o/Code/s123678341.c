#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(ll *)b - *(ll *)a); // Sort in descending order
}

int main() {
    // Initialize input variables
    int X, Y, Z, K; // Number of elements in arrays A, B, C and the limit for output
    scanf("%d %d %d %d", &X, &Y, &Z, &K); // Read input values for X, Y, Z, and K from standard input

    // Initialize arrays A, B, and C
    ll *A = (ll *)malloc(X * sizeof(ll)); // A array of size X
    ll *B = (ll *)malloc(Y * sizeof(ll)); // B array of size Y
    ll *C = (ll *)malloc(Z * sizeof(ll)); // C array of size Z

    // Read input values for arrays A, B, and C from standard input
    for (int i = 0; i < X; i++)
        scanf("%lld", &A[i]); // Read each element of array A
    for (int i = 0; i < Y; i++)
        scanf("%lld", &B[i]); // Read each element of array B
    for (int i = 0; i < Z; i++)
        scanf("%lld", &C[i]); // Read each element of array C

    // Sort arrays A, B, and C in descending order
    qsort(A, X, sizeof(ll), compare);
    qsort(B, Y, sizeof(ll), compare);
    qsort(C, Z, sizeof(ll), compare);

    // Create a new array AB by adding each element of A to each element of B
    ll *AB = (ll *)malloc(X * Y * sizeof(ll)); // Maximum size of AB
    int indexAB = 0;
    for (int i = 0; i < X; i++) {
        for (int j = 0; j < Y; j++) {
            AB[indexAB++] = A[i] + B[j]; // Add A[i] and B[j] and store in AB
        }
    }

    // Sort array AB in descending order
    qsort(AB, indexAB, sizeof(ll), compare);

    // Create a new array ABC by adding each element of AB to each element of C
    ll *ABC = (ll *)malloc(K * Z * sizeof(ll)); // Maximum size of ABC
    int indexABC = 0;
    for (int i = 0; i < (K < indexAB ? K : indexAB); i++) {
        for (int j = 0; j < Z; j++) {
            ABC[indexABC++] = AB[i] + C[j]; // Add AB[i] and C[j] and store in ABC
        }
    }

    // Sort array ABC in descending order
    qsort(ABC, indexABC, sizeof(ll), compare);

    // Print K smallest elements of array ABC
    for (int i = 0; i < K && i < indexABC; i++) {
        printf("%lld\n", ABC[i]); // Print each element of array ABC
    }

    // Free allocated memory
    free(A);
    free(B);
    free(C);
    free(AB);
    free(ABC);

    // Main function ends here
    return 0;
}

// <END-OF-CODE>
