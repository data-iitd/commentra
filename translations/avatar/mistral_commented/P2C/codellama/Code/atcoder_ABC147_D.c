#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to calculate the sum of bits in position 'b' in all numbers of 'A'
int sum_of_bits(int *A, int N, int b) {
    int i, sum = 0;
    for (i = 0; i < N; i++) {
        if (A[i] & (1 << b)) {
            sum++;
        }
    }
    return sum;
}

// Function to calculate the contribution of bit position 'b' to the result
int contribution(int *A, int N, int b) {
    int bs = sum_of_bits(A, N, b);
    return (bs * (N - bs) * (1 << b)) % 1000000007;
}

// Function to calculate the final result
int final_result(int *A, int N) {
    int i, result = 0;
    for (i = 0; i < 60; i++) {
        result = (result + contribution(A, N, i)) % 1000000007;
    }
    return result;
}

int main() {
    int N, i, *A;
    scanf("%d", &N);
    A = (int *)malloc(N * sizeof(int));
    for (i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    printf("%d\n", final_result(A, N));
    free(A);
    return 0;
}

