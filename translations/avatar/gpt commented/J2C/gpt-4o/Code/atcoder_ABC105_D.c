#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int key;
    int value;
} HashMapEntry;

typedef struct {
    HashMapEntry *entries;
    int size;
    int capacity;
} HashMap;

HashMap* createHashMap(int capacity) {
    HashMap *map = (HashMap *)malloc(sizeof(HashMap));
    map->entries = (HashMapEntry *)malloc(sizeof(HashMapEntry) * capacity);
    map->size = 0;
    map->capacity = capacity;
    return map;
}

int hash(int key, int capacity) {
    return (key % capacity + capacity) % capacity;
}

void put(HashMap *map, int key, int value) {
    int index = hash(key, map->capacity);
    for (int i = 0; i < map->size; i++) {
        if (map->entries[i].key == index) {
            map->entries[i].value += value;
            return;
        }
    }
    map->entries[map->size].key = index;
    map->entries[map->size].value = value;
    map->size++;
}

int get(HashMap *map, int key) {
    int index = hash(key, map->capacity);
    for (int i = 0; i < map->size; i++) {
        if (map->entries[i].key == index) {
            return map->entries[i].value;
        }
    }
    return 0;
}

void freeHashMap(HashMap *map) {
    free(map->entries);
    free(map);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    int *a = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    HashMap *dp = createHashMap(m);
    long long ans = 0;
    int base = 0;

    for (int i = 0; i < n; i++) {
        base = (base - a[i] % m + m) % m;
        put(dp, (base + a[i]) % m, 1);
        ans += get(dp, base);
    }

    printf("%lld\n", ans);
    
    free(a);
    freeHashMap(dp);
    return 0;
}

// <END-OF-CODE>
