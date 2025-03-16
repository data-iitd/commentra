#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

int compare(const void *a, const void *b) {
    return (*(ll *)b - *(ll *)a); // For descending order
}

int main() {
    // Step 1: Reading Inputs
    int X, Y, Z, K;
    scanf("%d %d %d %d", &X, &Y, &Z, &K);
    
    // Step 2: Array Initialization and Input
    ll *A = (ll *)malloc(X * sizeof(ll));
    ll *B = (ll *)malloc(Y * sizeof(ll));
    ll *C = (ll *)malloc(Z * sizeof(ll));
    
<<<<<<< HEAD
    for(int i = 0; i < X; i++)
        scanf("%lld", &A[i]);
    for(int i = 0; i < Y; i++)
        scanf("%lld", &B[i]);
    for(int i = 0; i < Z; i++)
        scanf("%lld", &C[i]);
=======
    for (int i = 0; i < X; i++) {
        scanf("%lld", &A[i]);
    }
    for (int i = 0; i < Y; i++) {
        scanf("%lld", &B[i]);
    }
    for (int i = 0; i < Z; i++) {
        scanf("%lld", &C[i]);
    }
>>>>>>> 98c87cb78a (data updated)
    
    // Step 3: Sorting
    qsort(A, X, sizeof(ll), compare);
    qsort(B, Y, sizeof(ll), compare);
    qsort(C, Z, sizeof(ll), compare);
    
    // Step 4: Combining A and B
    ll *AB = (ll *)malloc(X * Y * sizeof(ll));
<<<<<<< HEAD
    int indexAB = 0;
    for(int i = 0; i < X; i++) {
        for(int j = 0; j < Y; j++) {
            AB[indexAB++] = A[i] + B[j];
=======
    int index = 0;
    for (int i = 0; i < X; i++) {
        for (int j = 0; j < Y; j++) {
            AB[index++] = A[i] + B[j];
>>>>>>> 98c87cb78a (data updated)
        }
    }
    
    // Step 5: Sorting AB
<<<<<<< HEAD
    qsort(AB, indexAB, sizeof(ll), compare);
    
    // Step 6: Combining AB and C
    ll *ABC = (ll *)malloc(K * Z * sizeof(ll));
    int indexABC = 0;
    for(int i = 0; i < (K < indexAB ? K : indexAB); i++) {
        for(int j = 0; j < Z; j++) {
            ABC[indexABC++] = AB[i] + C[j];
=======
    qsort(AB, index, sizeof(ll), compare);
    
    // Step 6: Combining AB and C
    ll *ABC = (ll *)malloc(K * Z * sizeof(ll));
    int abcIndex = 0;
    for (int i = 0; i < (K < index ? K : index); i++) {
        for (int j = 0; j < Z; j++) {
            ABC[abcIndex++] = AB[i] + C[j];
>>>>>>> 98c87cb78a (data updated)
        }
    }
    
    // Step 7: Sorting ABC
<<<<<<< HEAD
    qsort(ABC, indexABC, sizeof(ll), compare);
    
    // Step 8: Output
    for(int i = 0; i < K; i++) {
=======
    qsort(ABC, abcIndex, sizeof(ll), compare);
    
    // Step 8: Output
    for (int i = 0; i < K; i++) {
>>>>>>> 98c87cb78a (data updated)
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
