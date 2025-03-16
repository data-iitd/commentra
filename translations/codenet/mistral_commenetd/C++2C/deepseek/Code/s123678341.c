#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define INF 1000000000
#define MOD 1000000007
#define EPS 0.00000001

// Main function starts here
int main(){
    // Initialize input variables
    int X, Y, Z, K; // Number of elements in vectors A, B, C and the limit for output
    scanf("%d %d %d %d", &X, &Y, &Z, &K); // Read input values for X, Y, Z, and K from standard input

    // Initialize vectors A, B, and C
    long long A[X]; // A vector of size X, initialized with zeroes
    long long B[Y]; // B vector of size Y, initialized with zeroes
    long long C[Z]; // C vector of size Z, initialized with zeroes

    // Read input values for vectors A, B, and C from standard input
    for(int i=0; i<X; i++){
        scanf("%lld", &A[i]); // Read each element of vector A
    }
    for(int i=0; i<Y; i++){
        scanf("%lld", &B[i]); // Read each element of vector B
    }
    for(int i=0; i<Z; i++){
        scanf("%lld", &C[i]); // Read each element of vector C
    }

    // Sort vectors A, B, and C in descending order
    qsort(A, X, sizeof(long long), (int (*)(const void *, const void *))compare_desc);
    qsort(B, Y, sizeof(long long), (int (*)(const void *, const void *))compare_desc);
    qsort(C, Z, sizeof(long long), (int (*)(const void *, const void *))compare_desc);

    // Create a new vector AB by adding each element of A to each element of B
    long long *AB = (long long *)malloc(X * Y * sizeof(long long));
    int ab_index = 0;
    for(int i=0; i<X; i++){
        for(int j=0; j<Y; j++){
            AB[ab_index++] = A[i] + B[j]; // Add A[i] and B[j] and push the sum into vector AB
        }
    }

    // Sort vector AB in descending order
    qsort(AB, X * Y, sizeof(long long), (int (*)(const void *, const void *))compare_desc);

    // Create a new vector ABC by adding each element of AB to each element of C
    long long *ABC = (long long *)malloc(K * Z * sizeof(long long));
    int abc_index = 0;
    for(int i=0; i<min(K, X * Y); i++){
        for(int j=0; j<Z; j++){
            ABC[abc_index++] = AB[i] + C[j]; // Add AB[i] and C[j] and push the sum into vector ABC
        }
    }

    // Sort vector ABC in descending order
    qsort(ABC, K * Z, sizeof(long long), (int (*)(const void *, const void *))compare_desc);

    // Print K smallest elements of vector ABC
    for(int i=0; i<K; i++){
        printf("%lld\n", ABC[i]); // Print each element of vector ABC
    }

    // Free allocated memory
    free(AB);
    free(ABC);

    // Main function ends here
    return 0;
}

int compare_desc(const void *a, const void *b) {
    return (*(long long *)b - *(long long *)a);
}
