
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>

int main() {
    // Input the sizes of the three arrays and the number K
    int X, Y, Z, K; 
    scanf("%d %d %d %d", &X, &Y, &Z, &K);

    // Declare arrays to hold the input values
    long long A[X];
    long long B[Y];
    long long C[Z];

    // Read values into array A
    for(int i = 0; i < X; i++)
        scanf("%lld", &A[i]);

    // Read values into array B
    for(int i = 0; i < Y; i++)
        scanf("%lld", &B[i]);

    // Read values into array C
    for(int i = 0; i < Z; i++)
        scanf("%lld", &C[i]);

    // Sort the arrays in descending order to facilitate maximum sum calculations
    qsort(A, X, sizeof(long long), cmpfunc);
    qsort(B, Y, sizeof(long long), cmpfunc);
    qsort(C, Z, sizeof(long long), cmpfunc);

    // Create an array to store the sums of elements from A and B
    long long AB[X * Y];

    // Calculate all possible sums of elements from A and B
    int count = 0;
    for(int i = 0; i < X; i++) {
        for(int j = 0; j < Y; j++) {
            AB[count++] = A[i] + B[j];
        }
    }

    // Sort the sums in descending order
    qsort(AB, X * Y, sizeof(long long), cmpfunc);

    // Create an array to store the final sums including elements from C
    long long ABC[min(K, X * Y) * Z];

    // Calculate sums of the top K elements from AB with each element from C
    count = 0;
    for(int i = 0; i < min(K, X * Y); i++) {
        for(int j = 0; j < Z; j++) {
            ABC[count++] = AB[i] + C[j];
        }
    }

    // Sort the final sums in descending order
    qsort(ABC, min(K, X * Y) * Z, sizeof(long long), cmpfunc);

    // Output the top K sums from the final array
    for(int i = 0; i < K; i++) {
        printf("%lld\n", ABC[i]);
    }

    return 0;
}

