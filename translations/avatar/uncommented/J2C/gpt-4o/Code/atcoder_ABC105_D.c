#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} HashMap;

void initHashMap(HashMap *map, int capacity) {
    map->data = (int *)calloc(capacity, sizeof(int));
    map->size = 0;
    map->capacity = capacity;
}

void freeHashMap(HashMap *map) {
    free(map->data);
}

int hash(int key, int capacity) {
    return (key % capacity + capacity) % capacity;
}

void merge(HashMap *map, int key) {
    int index = hash(key, map->capacity);
    if (map->data[index] == 0) {
        map->size++;
    }
    map->data[index]++;
}

int getOrDefault(HashMap *map, int key, int defaultValue) {
    int index = hash(key, map->capacity);
    return map->data[index] ? map->data[index] : defaultValue;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    int *a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    HashMap dp;
    initHashMap(&dp, m);
    
    long long ans = 0;
    int base = 0;

    for (int i = 0; i < n; i++) {
        base = (base - a[i] % m + m) % m;
        merge(&dp, (base + a[i]) % m);
        ans += getOrDefault(&dp, base, 0);
    }

    printf("%lld\n", ans);

    free(a);
    freeHashMap(&dp);
    return 0;
}
