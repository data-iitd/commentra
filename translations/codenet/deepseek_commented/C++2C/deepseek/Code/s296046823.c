#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, K;
    scanf("%d %d", &N, &K); // 1. Reading the values of N and K from the standard input.

    int *v = (int *)malloc(N * sizeof(int)); // 2. Allocating memory for a vector of size N to store N integers.
    for (int i = 0; i < N; ++i)
        scanf("%d", &v[i]); // 3. Reading N integers from the standard input and storing them in the vector v.

    // 4. Calculating the number of groups that can be formed using the formula ceil((N-1) / (K-1)).
    int count = ((N - 1) + ((K - 1) - 1)) / (K - 1);
    printf("%d\n", count); // 5. Outputting the calculated count.

    free(v); // Free the allocated memory
}
