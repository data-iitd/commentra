#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include <assert.h>

#define MAX_SIZE 1000000

typedef struct {
    int key;
    int value;
} pair;

typedef struct {
    pair *pairs;
    int size;
    int capacity;
} map;

map *create_map(int capacity) {
    map *m = malloc(sizeof(map));
    m->pairs = malloc(sizeof(pair) * capacity);
    m->size = 0;
    m->capacity = capacity;
    return m;
}

void put(map *m, int key, int value) {
    if (m->size == m->capacity) {
        m->capacity *= 2;
        m->pairs = realloc(m->pairs, sizeof(pair) * m->capacity);
    }
    m->pairs[m->size].key = key;
    m->pairs[m->size].value = value;
    m->size++;
}

int get(map *m, int key) {
    for (int i = 0; i < m->size; i++) {
        if (m->pairs[i].key == key) {
            return m->pairs[i].value;
        }
    }
    return -1;
}

int lower_key(map *m, int key) {
    for (int i = 0; i < m->size; i++) {
        if (m->pairs[i].key < key) {
            return m->pairs[i].key;
        }
    }
    return -1;
}

void remove(map *m, int key) {
    for (int i = 0; i < m->size; i++) {
        if (m->pairs[i].key == key) {
            m->pairs[i] = m->pairs[m->size - 1];
            m->size--;
            return;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    map *m = create_map(1000000);
    while (n-- > 0) {
        int num;
        scanf("%d", &num);
        if (lower_key(m, num) == -1) {
            put(m, num, get(m, num) + 1);
        } else {
            int key = lower_key(m, num);
            remove(m, key);
            put(m, num, get(m, num) + 1);
        }
    }
    int ans = 0;
    for (int i = 0; i < m->size; i++) {
        ans += m->pairs[i].value;
    }
    printf("%d\n", ans);
    return 0;
}

