#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

typedef struct {
    char key[MAX_LEN];
    int value;
} Entry;

typedef struct {
    Entry *entries;
    size_t size;
    size_t capacity;
} HashMap;

HashMap* createHashMap(size_t capacity) {
    HashMap* map = (HashMap*)malloc(sizeof(HashMap));
    map->entries = (Entry*)calloc(capacity, sizeof(Entry));
    map->size = 0;
    map->capacity = capacity;
    return map;
}

void freeHashMap(HashMap* map) {
    free(map->entries);
    free(map);
}

unsigned int hash(const char* key, size_t capacity) {
    unsigned int hash = 0;
    while (*key) {
        hash = (hash * 31) + *key++;
    }
    return hash % capacity;
}

void put(HashMap* map, const char* key) {
    size_t index = hash(key, map->capacity);
    while (map->entries[index].value != 0) {
        index = (index + 1) % map->capacity;
    }
    strcpy(map->entries[index].key, key);
    map->entries[index].value = 1;
    map->size++;
}

int get(HashMap* map, const char* key) {
    size_t index = hash(key, map->capacity);
    while (map->entries[index].value != 0) {
        if (strcmp(map->entries[index].key, key) == 0) {
            return map->entries[index].value;
        }
        index = (index + 1) % map->capacity;
    }
    return 0;
}

int main() {
    size_t n;
    scanf("%zu", &n);

    HashMap* s = createHashMap(n);
    char** l = (char**)malloc(n * sizeof(char*));
    for (size_t i = 0; i < n; i++) {
        l[i] = (char*)malloc(MAX_LEN * sizeof(char));
        scanf("%s", l[i]);
    }

    char* f = "Yes";
    for (size_t i = 0; i < n; i++) {
        put(s, l[i]);
        if (get(s, l[i]) >= 2) {
            f = "No";
        }
        if (i > 0 && l[i - 1][strlen(l[i - 1]) - 1] != l[i][0]) {
            f = "No";
        }
    }

    printf("%s\n", f);

    freeHashMap(s);
    for (size_t i = 0; i < n; i++) {
        free(l[i]);
    }
    free(l);

    return 0;
}
