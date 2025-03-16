#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int time;
    int limit;
} work;

typedef struct {
    work *array;
    int size;
} works;

void read_works(works *w) {
    for (int i = 0; i < w->size; i++) {
        scanf("%d %d", &w->array[i].time, &w->array[i].limit);
    }
}

int compare(const void *a, const void *b) {
    return ((work *)a)->limit - ((work *)b)->limit;
}

int main() {
    int n;
    scanf("%d", &n);

    works w;
    w.array = (work *)malloc(n * sizeof(work));
    w.size = n;

    read_works(&w);

    qsort(w.array, n, sizeof(work), compare);

    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += w.array[i].time;
        if (sum > w.array[i].limit) {
            printf("No\n");
            free(w.array);
            return 0;
        }
    }

    printf("Yes\n");
    free(w.array);
    return 0;
}

