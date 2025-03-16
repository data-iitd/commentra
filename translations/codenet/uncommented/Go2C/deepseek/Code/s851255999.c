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
    scanf("%d", &w->size);
    w->array = (work *)malloc(w->size * sizeof(work));
    for (int i = 0; i < w->size; i++) {
        scanf("%d %d", &w->array[i].time, &w->array[i].limit);
    }
}

int compare(const void *a, const void *b) {
    return ((work *)a)->limit - ((work *)b)->limit;
}

void free_works(works *w) {
    free(w->array);
}

int main() {
    works w;
    read_works(&w);

    qsort(w.array, w.size, sizeof(work), compare);

    long long sum = 0;
    for (int i = 0; i < w.size; i++) {
        sum += w.array[i].time;
        if (sum > w.array[i].limit) {
            printf("No\n");
            free_works(&w);
            return 0;
        }
    }
    printf("Yes\n");
    free_works(&w);
    return 0;
}
