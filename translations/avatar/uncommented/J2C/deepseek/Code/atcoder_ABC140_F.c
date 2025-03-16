#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int compare(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

int main() {
    int N;
    scanf("%d", &N);
    int size = (1 << N);
    int S[size];
    bool spawned[size];
    spawned[size - 1] = true;
    for (int i = 0; i < size; i++) {
        scanf("%d", &S[i]);
    }
    qsort(S, size, sizeof(int), compare);
    int active_size = 1;
    int active[active_size];
    active[0] = S[size - 1];
    spawned[size - 1] = true;
    for (int i = 0; i < N; i++) {
        qsort(active, active_size, sizeof(int), compare);
        int activated[active_size];
        int next = size - 1;
        for (int j = 0; j < active_size; j++) {
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
        for (int j = 0; j < active_size; j++) {
            active[j] = activated[j];
        }
        active_size *= 2;
    }
    printf("Yes\n");
    return 0;
}
