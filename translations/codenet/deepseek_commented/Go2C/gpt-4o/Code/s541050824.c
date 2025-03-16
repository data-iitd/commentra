#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read the next integer from input
int64_t nextInt() {
    int64_t value;
    scanf("%lld", &value);
    return value;
}

// Function to calculate the maximum of two integers
int64_t max(int64_t x, int64_t y) {
    return (x > y) ? x : y;
}

// Function to calculate the ceiling of the division of x by y
int64_t divUp(int64_t x, int64_t y) {
    return (x + y - 1) / y;
}

// Main function
int main() {
    int64_t N = nextInt();
    int64_t *T = (int64_t *)malloc(N * sizeof(int64_t));
    int64_t *A = (int64_t *)malloc(N * sizeof(int64_t));

    for (int64_t i = 0; i < N; i++) {
        T[i] = nextInt();
        A[i] = nextInt();
    }

    int64_t t = T[0], a = A[0];
    for (int64_t i = 1; i < N; i++) {
        int64_t r = max(divUp(t, T[i]), divUp(a, A[i]));
        t = T[i] * r;
        a = A[i] * r;
    }

    printf("%lld\n", t + a);

    free(T);
    free(A);
    return 0;
}

// <END-OF-CODE>
