#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(ll *)b - *(ll *)a); // Sort in descending order
}

int main() {
    // Input the sizes of the three arrays and the number K
    int X, Y, Z, K; 
    scanf("%d %d %d %d", &X, &Y, &Z, &K);

    // Declare arrays to hold the input values
    ll *A = (ll *)malloc(X * sizeof(ll));
    ll *B = (ll *)malloc(Y * sizeof(ll));
    ll *C = (ll *)malloc(Z * sizeof(ll));

    // Read values into array A
<<<<<<< HEAD
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
=======
    for(int i = 0; i < X; i++)
        scanf("%lld", &A[i]);

    // Read values into array B
    for(int i = 0; i < Y; i++)
        scanf("%lld", &B[i]);

    // Read values into array C
    for(int i = 0; i < Z; i++)
        scanf("%lld", &C[i]);
>>>>>>> 98c87cb78a (data updated)

    // Sort the arrays in descending order
    qsort(A, X, sizeof(ll), compare);
    qsort(B, Y, sizeof(ll), compare);
    qsort(C, Z, sizeof(ll), compare);

    // Create an array to store the sums of elements from A and B
    ll *AB = (ll *)malloc(X * Y * sizeof(ll));
    int ab_size = 0;

    // Calculate all possible sums of elements from A and B
    for(int i = 0; i < X; i++) {
        for(int j = 0; j < Y; j++) {
            AB[ab_size++] = A[i] + B[j];
        }
    }

    // Sort the sums in descending order
    qsort(AB, ab_size, sizeof(ll), compare);

    // Create an array to store the final sums including elements from C
    ll *ABC = (ll *)malloc(K * Z * sizeof(ll));
    int abc_size = 0;

    // Calculate sums of the top K elements from AB with each element from C
    for(int i = 0; i < (K < ab_size ? K : ab_size); i++) {
        for(int j = 0; j < Z; j++) {
            ABC[abc_size++] = AB[i] + C[j];
        }
    }

    // Sort the final sums in descending order
    qsort(ABC, abc_size, sizeof(ll), compare);

    // Output the top K sums from the final array
    for(int i = 0; i < K; i++) {
        printf("%lld\n", ABC[i]);
    }

    // Free allocated memory
    free(A);
    free(B);
    free(C);
    free(AB);
    free(ABC);

    return 0;
}

// <END-OF-CODE>
