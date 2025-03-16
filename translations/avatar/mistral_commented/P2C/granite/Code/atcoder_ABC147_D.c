
#include <stdio.h>
#include <stdlib.h>

// Define the modulo operation for large numbers
#define MODULO(x) ((x) % 1000000007)

// Function to calculate the sum of bits in a given position 'b' in an array of integers 'A'
long long sum_bits(int *A, int N, int b) {
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        sum += (A[i] >> b) & 1;
    }
    return sum;
}

// Function to calculate the contribution of a given bit position 'b' to the result
long long contribution(int *A, int N, int b) {
    long long bs = sum_bits(A, N, b);
    return bs * (N - bs) * (1LL << b);
}

// Function to calculate the sum of all contributions for all bit positions
long long calculate_result(int *A, int N) {
    long long result = 0;
    for (int b = 0; b < 60; b++) {
        result = MODULO(result + contribution(A, N, b));
    }
    return result;
}

int main() {
    int N;
    scanf("%d", &N);
    int *A = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    long long result = calculate_result(A, N);
    printf("%lld\n", result);
    free(A);
    return 0;
}

