#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int key;
    int value;
} Entry;

typedef struct {
    Entry *entries;
    int size;
    int capacity;
} TreeMap;

TreeMap* createTreeMap(int capacity) {
    TreeMap* map = (TreeMap*)malloc(sizeof(TreeMap));
    map->entries = (Entry*)malloc(capacity * sizeof(Entry));
    map->size = 0;
    map->capacity = capacity;
    return map;
}

void put(TreeMap* map, int key, int value) {
    for (int i = 0; i < map->size; i++) {
        if (map->entries[i].key == key) {
            map->entries[i].value = value;
            return;
        }
    }
    if (map->size < map->capacity) {
        map->entries[map->size].key = key;
        map->entries[map->size].value = value;
        map->size++;
    }
}

int get(TreeMap* map, int key) {
    for (int i = 0; i < map->size; i++) {
        if (map->entries[i].key == key) {
            return map->entries[i].value;
        }
    }
    return 0;
}

int lowerKey(TreeMap* map, int key) {
    for (int i = 0; i < map->size; i++) {
        if (map->entries[i].key < key) {
            return map->entries[i].key;
        }
    }
    return -1;
}

void removeEntry(TreeMap* map, int key) {
    for (int i = 0; i < map->size; i++) {
        if (map->entries[i].key == key) {
            map->entries[i] = map->entries[map->size - 1];
            map->size--;
            return;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    TreeMap* map = createTreeMap(n);

    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);

        if (lowerKey(map, num) == -1) {
            int val = get(map, num);
            put(map, num, val + 1);
        } else {
            int key = lowerKey(map, num);
            int val = get(map, key);
            if (val == 1) {
                removeEntry(map, key);
            } else {
                put(map, key, val - 1);
            }
            val = get(map, num);
            put(map, num, val + 1);
        }
    }

    int ans = 0;
    for (int i = 0; i < map->size; i++) {
        ans += map->entries[i].value;
    }

    printf("%d\n", ans);

    free(map->entries);
    free(map);
    return 0;
}
