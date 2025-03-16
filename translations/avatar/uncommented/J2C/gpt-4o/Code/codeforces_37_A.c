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

void initHashMap(HashMap *map, int capacity) {
    map->entries = (HashMapEntry *)malloc(sizeof(HashMapEntry) * capacity);
    map->size = 0;
    map->capacity = capacity;
}

int hash(int key, int capacity) {
    return abs(key) % capacity;
}

void put(HashMap *map, int key) {
    int index = hash(key, map->capacity);
    while (index < map->capacity) {
        if (map->entries[index].key == key || map->entries[index].key == 0) {
            if (map->entries[index].key == key) {
                map->entries[index].value++;
            } else {
                map->entries[index].key = key;
                map->entries[index].value = 1;
                map->size++;
            }
            return;
        }
        index++;
    }
}

int getMaxValue(HashMap *map) {
    int max = 0;
    for (int i = 0; i < map->capacity; i++) {
        if (map->entries[i].value > max) {
            max = map->entries[i].value;
        }
    }
    return max;
}

int main() {
    int n;
    scanf("%d", &n);
    
    HashMap map;
    initHashMap(&map, n);
    
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        put(&map, val);
    }
    
    int max = getMaxValue(&map);
    printf("%d %d\n", max, map.size);
    
    free(map.entries);
    return 0;
}

// <END-OF-CODE>
