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

void initTreeMap(TreeMap *map, int capacity) {
    map->entries = (Entry *)malloc(capacity * sizeof(Entry));
    map->size = 0;
    map->capacity = capacity;
}

void clearTreeMap(TreeMap *map) {
    map->size = 0;
}

void put(TreeMap *map, int key, int value) {
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

int get(TreeMap *map, int key) {
    for (int i = 0; i < map->size; i++) {
        if (map->entries[i].key == key) {
            return map->entries[i].value;
        }
    }
    return 0; // Default value if key not found
}

void removeKey(TreeMap *map, int key) {
    for (int i = 0; i < map->size; i++) {
        if (map->entries[i].key == key) {
            map->entries[i] = map->entries[map->size - 1]; // Replace with last entry
            map->size--;
            return;
        }
    }
}

int isPossible(int *a, int n, int k, TreeMap *s) {
    clearTreeMap(s);
    int current = 0;

    for (int i = 0; i < n; i++) {
        int ai = a[i];
        if (ai <= current) {
            if (k == 1) return 0;

            while (s->size > 0 && s->entries[s->size - 1].key >= ai) {
                removeKey(s, s->entries[s->size - 1].key);
            }

            int p = ai - 1;
            while (1) {
                if (p < 0) return 0;

                int sp = get(s, p) + 1;
                put(s, p, sp);

                if (sp == k) {
                    removeKey(s, p);
                    p--;
                } else {
                    break;
                }
            }
        }
        current = ai;
    }
    return 1;
}

int main() {
    int n;
    scanf("%d", &n);
    int *a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    TreeMap s;
    initTreeMap(&s, n);

    int ng = 0;
    int ok = n;

    while (ok - ng > 1) {
        int k = (ng + ok) / 2;
        if (isPossible(a, n, k, &s)) {
            ok = k;
        } else {
            ng = k;
        }
    }

    printf("%d\n", ok);

    free(a);
    free(s.entries);
    return 0;
}

// <END-OF-CODE>
