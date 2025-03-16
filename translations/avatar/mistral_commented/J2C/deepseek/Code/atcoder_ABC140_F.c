#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1048576 // 2^20

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int N;
    scanf("%d", &N);

    int size = 1 << N;
    int S[MAX_SIZE];
    bool spawned[MAX_SIZE] = {false};

    spawned[size - 1] = true;

    for (int i = 0; i < size; i++) {
        scanf("%d", &S[i]);
    }

    qsort(S, size, sizeof(int), compare);

    int active[MAX_SIZE];
    int active_size = 0;
    active[active_size++] = size - 1;
    spawned[size - 1] = true;

    for (int i = 0; i < N; i++) {
        qsort(active, active_size, sizeof(int), compare);

        int activated[MAX_SIZE];
        int activated_size = 0;
        int next = size - 1;

        for (int j = active_size - 1; j >= 0; j--) {
            while (next >= 0 && (S[next] >= active[j] || spawned[next])) {
                next--;
            }
            if (next < 0) {
                printf("No\n");
                return 0;
            }
            spawned[next] = true;
            activated[activated_size++] = S[next];
        }

        for (int j = 0; j < activated_size; j++) {
            active[active_size++] = activated[j];
        }
    }

    printf("Yes\n");
    return 0;
}
