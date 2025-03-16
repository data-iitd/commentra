#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int *L = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &L[i]);
    }

    qsort(L, N, sizeof(int), compare);

    for (int i = 0; i < M; i++) {
        int max_L = L[N - 1];
        if (max_L == 0) {
            break;
        }

        max_L /= 2;

        // Insert max_L into the sorted array L
        int *new_L = (int *)malloc((N + 1) * sizeof(int));
        int j = 0, inserted = 0;

        for (int k = 0; k < N; k++) {
            if (!inserted && (k == N - 1 || L[k] >= max_L)) {
                new_L[j++] = max_L;
                inserted = 1;
            }
            new_L[j++] = L[k];
        }
        if (!inserted) {
            new_L[j++] = max_L;
        }

        free(L);
        L = new_L;
        N++; // Increase the size of the array

<<<<<<< HEAD
        // Remove the last element (which is the maximum)
=======
        // Remove the last element (which is the original max_L)
>>>>>>> 98c87cb78a (data updated)
        N--;
    }

    long long ans = 0;
    for (int i = 0; i < N; i++) {
        ans += L[i];
    }

    printf("%lld\n", ans);
<<<<<<< HEAD

=======
>>>>>>> 98c87cb78a (data updated)
    free(L);
    return 0;
}

// <END-OF-CODE>
