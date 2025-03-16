

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);
    int size = 1 << N;
    int S[size];
    bool spawned[size];
    memset(spawned, 0, sizeof(spawned));
    spawned[size - 1] = true;
    for (int i = 0; i < size; i++) {
        scanf("%d", &S[i]);
    }
    qsort(S, size, sizeof(int));
    int active[size];
    int active_size = 1;
    active[0] = size - 1;
    spawned[size - 1] = true;
    for (int i = 0; i < N; i++) {
        qsort(active, active_size, sizeof(int), cmpfunc);
        int activated[size];
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
        memcpy(active, activated, activated_size * sizeof(int));
        active_size = activated_size;
    }
    printf("Yes\n");
    return 0;
}

int cmpfunc (const void * a, const void * b) {
   return (*(int*)a - *(int*)b);
}

