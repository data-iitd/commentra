#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int key;
    int value;
} Pair;

typedef struct {
    Pair *data;
    int size;
    int capacity;
} HashMap;

HashMap* createHashMap(int capacity) {
    HashMap* map = (HashMap*)malloc(sizeof(HashMap));
    map->data = (Pair*)malloc(capacity * sizeof(Pair));
    map->size = 0;
    map->capacity = capacity;
    return map;
}

int hashCode(int key, int capacity) {
    return abs(key) % capacity;
}

void put(HashMap* map, int key, int value) {
    int hash = hashCode(key, map->capacity);
    while (map->data[hash].key != 0 && map->data[hash].key != key) {
        hash = (hash + 1) % map->capacity;
    }
    if (map->data[hash].key == 0) {
        map->size++;
    }
    map->data[hash].key = key;
    map->data[hash].value = value;
}

int get(HashMap* map, int key) {
    int hash = hashCode(key, map->capacity);
    while (map->data[hash].key != 0) {
        if (map->data[hash].key == key) {
            return map->data[hash].value;
        }
        hash = (hash + 1) % map->capacity;
    }
    return -1;
}

void remove(HashMap* map, int key) {
    int hash = hashCode(key, map->capacity);
    while (map->data[hash].key != 0) {
        if (map->data[hash].key == key) {
            map->data[hash].key = 0;
            map->data[hash].value = 0;
            map->size--;
            return;
        }
        hash = (hash + 1) % map->capacity;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    HashMap* map = createHashMap(n);

    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);

        int key = num;
        int value = get(map, key) + 1;

        if (get(map, key - 1) == -1) {
            put(map, key, value);
        } else {
            remove(map, key - 1);
            put(map, key, value);
        }
    }

    int ans = 0;
    for (int i = 0; i < map->capacity; i++) {
        if (map->data[i].key != 0) {
            ans += map->data[i].value;
        }
    }

    printf("%d\n", ans);

    free(map->data);
    free(map);

    return 0;
}
