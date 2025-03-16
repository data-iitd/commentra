#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    int *v = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; ++i)
        scanf("%d", &v[i]);

    // ceil((N-1) / (K-1))
    int count = ((N - 1) + ((K - 1) - 1)) / (K - 1);
    printf("%d\n", count);

    free(v);
    return 0;
}

