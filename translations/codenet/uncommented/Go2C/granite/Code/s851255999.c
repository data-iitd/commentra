
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <algorithm>

typedef struct {
    int time, limit;
} work;

typedef struct {
    int size, capacity;
    work* array;
} works;

int compareWorks(const void* a, const void* b) {
    work* w1 = (work*)a;
    work* w2 = (work*)b;
    return w1->limit - w2->limit;
}

int main() {
    // Your code here!
    int n;
    scanf("%d", &n);
    works ws;
    ws.size = 0;
    ws.capacity = n;
    ws.array = (work*)malloc(sizeof(work) * n);
    for (int i = 0; i < n; i++) {
        int a, n;
        scanf("%d %d", &a, &n);
        ws.array[i] = (work){a, n};
        ws.size++;
    }
    qsort(ws.array, ws.size, sizeof(work), compareWorks);

    long long sum = 0;
    for (int i = 0; i < ws.size; i++) {
        sum += ws.array[i].time;
        if (sum > ws.array[i].limit) {
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    return 0;
}

