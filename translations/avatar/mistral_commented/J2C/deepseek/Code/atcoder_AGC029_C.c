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

void initTreeMap(TreeMap *map, int capacity) {
    map->data = (Pair *)malloc(capacity * sizeof(Pair));
    map->size = 0;
    map->capacity = capacity;
}

void putTreeMap(TreeMap *map, int key, int value) {
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

int getTreeMap(TreeMap *map, int key) {
    for (int i = 0; i < map->size; i++) {
        if (map->data[i].key == key) {
            return map->data[i].value;
        }
    }
    return -1;
}

void clearTreeMap(TreeMap *map) {
    map->size = 0;
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n;
    int a[100000];
    TreeMap s;
    initTreeMap(&s, 100000);

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int ng = 0;
    int ok = n;

    while (ok - ng > 1) {
        int k = (ng + ok) / 2;
        if (isPossible(k, a, n, &s)) {
            ok = k;
        } else {
            ng = k;
        }
    }

    printf("%d\n", ok);

    free(s.data);
    return 0;
}

int isPossible(int k, int *a, int n, TreeMap *s) {
    clearTreeMap(s);
    int current = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] <= current) {
            if (k == 1) return 0;

            while (s->size > 0 && s->data[s->size - 1].key >= a[i]) {
                s->size--;
            }

            int p = a[i] - 1;
            while (true) {
                if (p < 0) return 0;

                int sp = getTreeMap(s, p) + 1;
                putTreeMap(s, p, sp);

                if (sp == k) {
                    s->size--;
                    p--;
                } else {
                    break;
                }
            }
        }
        current = a[i];
    }

    return 1;
}
