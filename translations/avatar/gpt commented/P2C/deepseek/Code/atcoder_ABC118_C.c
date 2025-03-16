#include <stdio.h>
#include <stdlib.h>

// Function to calculate the greatest common divisor (GCD) of two numbers
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to calculate the GCD of all elements in the array
int calculateGCD(int *arr, int n) {
    int result = arr[0];
    for (int i = 1; i < n; i++) {
        result = gcd(arr[i], result);
        if (result == 1) {
            return 1;
        }
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

    int result = calculateGCD(A, N);
    printf("%d\n", result);

    free(A);
    return 0;
}
