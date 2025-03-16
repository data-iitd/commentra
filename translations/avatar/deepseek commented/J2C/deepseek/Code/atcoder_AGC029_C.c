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
} TreeMap;

TreeMap* createTreeMap(int capacity) {
    TreeMap* map = (TreeMap*)malloc(sizeof(TreeMap));
    map->data = (Pair*)malloc(capacity * sizeof(Pair));
    map->size = 0;
    map->capacity = capacity;
    return map;
}

void clearTreeMap(TreeMap* map) {
    map->size = 0;
}

void putTreeMap(TreeMap* map, int key, int value) {
    for (int i = 0; i < map->size; i++) {
        if (map->data[i].key == key) {
            map->data[i].value = value;
            return;
        }
    }
    if (map->size < map->capacity) {
        map->data[map->size].key = key;
        map->data[map->size].value = value;
        map->size++;
    }
}

int getTreeMap(TreeMap* map, int key) {
    for (int i = 0; i < map->size; i++) {
        if (map->data[i].key == key) {
            return map->data[i].value;
        }
    }
    return 0;
}

void removeTreeMap(TreeMap* map, int key) {
    for (int i = 0; i < map->size; i++) {
        if (map->data[i].key == key) {
            for (int j = i; j < map->size - 1; j++) {
                map->data[j] = map->data[j + 1];
            }
            map->size--;
            break;
        }
    }
}

int comparePairs(const void *a, const void *b) {
    return ((Pair*)a)->key - ((Pair*)b)->key;
}

void sortTreeMap(TreeMap* map) {
    qsort(map->data, map->size, sizeof(Pair), comparePairs);
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    TreeMap* s = createTreeMap(n);

    int ng = 0;
    int ok = n;
    while (ok - ng > 1) {
        int k = (ng + ok) / 2;
        clearTreeMap(s);
        int current = 0;
        int possible = 1;
        for (int i = 0; i < n; i++) {
            if (a[i] <= current) {
                if (k == 1) {
                    possible = 0;
                    break;
                }
                while (s->size > 0 && s->data[s->size - 1].key >= a[i]) {
                    s->size--;
                }
                int p = a[i] - 1;
                while (1) {
                    if (p < 0) {
                        possible = 0;
                        break;
                    }
                    int sp = getTreeMap(s, p) + 1;
                    putTreeMap(s, p, sp);
                    if (sp == k) {
                        removeTreeMap(s, p);
                        p--;
                    } else {
                        break;
                    }
                }
            }
            current = a[i];
        }
        if (possible) {
            ok = k;
        } else {
            ng = k;
        }
    }
    printf("%d\n", ok);

    free(s->data);
    free(s);
    return 0;
}

