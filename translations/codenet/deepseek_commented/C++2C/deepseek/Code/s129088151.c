#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    char key[10];
    bool value;
} MapEntry;

#define INITIAL_CAPACITY 10

typedef struct {
    MapEntry *entries;
    size_t size;
    size_t capacity;
} HashMap;

void initHashMap(HashMap *map) {
    map->size = 0;
    map->capacity = INITIAL_CAPACITY;
    map->entries = (MapEntry *)malloc(map->capacity * sizeof(MapEntry));
}

void freeHashMap(HashMap *map) {
    free(map->entries);
}

unsigned int hash(const char *key) {
    unsigned int hash = 0;
    while (*key) {
        hash = (hash * 31) + *key++;
    }
    return hash;
}

void set(HashMap *map, const char *key, bool value) {
    unsigned int index = hash(key) % map->capacity;
    while (map->entries[index].key[0] != '\0' && strcmp(map->entries[index].key, key) != 0) {
        index = (index + 1) % map->capacity;
    }
    strcpy(map->entries[index].key, key);
    map->entries[index].value = value;
    if (map->size >= map->capacity / 2) {
        map->capacity *= 2;
        map->entries = (MapEntry *)realloc(map->entries, map->capacity * sizeof(MapEntry));
    }
    map->size++;
}

bool get(HashMap *map, const char *key) {
    unsigned int index = hash(key) % map->capacity;
    while (map->entries[index].key[0] != '\0' && strcmp(map->entries[index].key, key) != 0) {
        index = (index + 1) % map->capacity;
    }
    return map->entries[index].value;
}

int main() {
    int n;
    char com[13], str[10];
    HashMap map;
    initHashMap(&map);

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s %s", com, str);
        if (com[0] == 'i') {
            set(&map, str, true);
        } else {
            if (get(&map, str)) {
                printf("yes\n");
            } else {
                printf("no\n");
            }
        }
    }

    freeHashMap(&map);
    return 0;
}
