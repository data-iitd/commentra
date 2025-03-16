#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int find(int *li, int size, int from, int target) {
    int low = from;
    int upp = size - 1;
    int mid;

    if (upp < low) {
        return 0;
    } else if (li[from] >= target) {
        return 0;
    } else if (li[upp] < target) {
        return upp - low + 1;
    }

    while (upp - low > 1) {
        mid = (low + upp) / 2;
        if (li[mid] >= target) {
            upp = mid;
        } else {
            low = mid;
        }
    }
    return low - from + 1;
}

int main() {
    int N;
    scanf("%d", &N);
    int *L = (int *)malloc(N * sizeof(int));

    for (int i = 0; i < N; i++) {
        scanf("%d", &L[i]);
    }

    qsort(L, N, sizeof(int), compare);

    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int a = L[i];
            int b = L[j];
            int res = find(L, N, j + 1, a + b);
            count += res;
        }
    }

    printf("%d\n", count);
    free(L);
    return 0;
}

// <END-OF-CODE>
