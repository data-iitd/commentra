#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);
    int size = 1 << N;
    int *S = (int *)malloc(size * sizeof(int));
    bool *spawned = (bool *)malloc(size * sizeof(bool));
    memset(spawned, false, size * sizeof(bool));
    spawned[size - 1] = true;

    for (int i = 0; i < size; i++) {
        scanf("%d", &S[i]);
    }

    qsort(S, size, sizeof(int), compare);
    int *active = (int *)malloc(size * sizeof(int));
    active[size - 1] = S[size - 1];
    spawned[size - 1] = true;

    for (int i = 0; i < N; i++) {
        qsort(active, size, sizeof(int), compare);
        int *activated = (int *)malloc(size * sizeof(int));
        int next = size - 1;

        for (int j = 0; j < size; j++) {
            while (next >= 0 && (S[next] >= active[j] || spawned[next])) {
                next--;
            }
            if (next < 0) {
                printf("No\n");
                return 0;
            }
            spawned[next] = true;
            activated[j] = S[next];
        }
        for (int j = 0; j < size; j++) {
            active[j] = activated[j];
        }
    }
    printf("Yes\n");
    return 0;
}

int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

