#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

int compare(const void *a, const void *b) {
    return (*(ll *)b - *(ll *)a); // For descending order
}

int main() {
    int X, Y, Z, K;
    scanf("%d %d %d %d", &X, &Y, &Z, &K);
    
    ll *A = (ll *)malloc(X * sizeof(ll));
    ll *B = (ll *)malloc(Y * sizeof(ll));
    ll *C = (ll *)malloc(Z * sizeof(ll));
    
    for (int i = 0; i < X; i++) {
        scanf("%lld", &A[i]);
    }
    for (int i = 0; i < Y; i++) {
        scanf("%lld", &B[i]);
    }
    for (int i = 0; i < Z; i++) {
        scanf("%lld", &C[i]);
    }
    
    qsort(A, X, sizeof(ll), compare);
    qsort(B, Y, sizeof(ll), compare);
    qsort(C, Z, sizeof(ll), compare);
    
    ll *AB = (ll *)malloc(X * Y * sizeof(ll));
    int ab_size = 0;
    
    for (int i = 0; i < X; i++) {
        for (int j = 0; j < Y; j++) {
            AB[ab_size++] = A[i] + B[j];
        }
    }
    
    qsort(AB, ab_size, sizeof(ll), compare);
    
    ll *ABC = (ll *)malloc(K * Z * sizeof(ll));
    int abc_size = 0;
    
    for (int i = 0; i < (K < ab_size ? K : ab_size); i++) {
        for (int j = 0; j < Z; j++) {
            ABC[abc_size++] = AB[i] + C[j];
        }
    }
    
    qsort(ABC, abc_size, sizeof(ll), compare);
    
    for (int i = 0; i < K; i++) {
        printf("%lld\n", ABC[i]);
    }
    
    free(A);
    free(B);
    free(C);
    free(AB);
    free(ABC);
    
    return 0;
}

// <END-OF-CODE>
