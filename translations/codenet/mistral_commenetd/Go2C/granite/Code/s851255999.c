
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int time;
    int limit;
} work;

typedef struct {
    work *ws;
    int n;
} works;

int cmpfunc(const void *a, const void *b) {
    return (*(work*)a).limit - (*(work*)b).limit;
}

int main() {
    int n;
    scanf("%d", &n);

    work *ws = (work*)malloc(n * sizeof(work));
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &ws[i].time, &ws[i].limit);
    }

    qsort(ws, n, sizeof(work), cmpfunc);

    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += ws[i].time;
        if (sum > ws[i].limit) {
            printf("No\n");
            free(ws);
            return 0;
        }
    }

    printf("Yes\n");
    free(ws);
    return 0;
}

