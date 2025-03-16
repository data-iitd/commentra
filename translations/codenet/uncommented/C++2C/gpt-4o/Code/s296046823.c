#include <stdio.h>

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    int v[N]; // Note: Variable Length Arrays (VLAs) are a C99 feature
    for (int i = 0; i < N; ++i)
        scanf("%d", &v[i]);

    // ceil((N-1) / (K-1))
    int count = ((N - 1) + ((K - 1) - 1)) / (K - 1);
    printf("%d\n", count);

    return 0;
}

// <END-OF-CODE>
