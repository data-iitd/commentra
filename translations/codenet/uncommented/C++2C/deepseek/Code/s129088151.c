#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char key[10];
    int value;
} Entry;

typedef struct {
    Entry* entries;
    int size;
    int capacity;
} HashMap;

HashMap* createHashMap(int capacity) {
    HashMap* map = (HashMap*)malloc(sizeof(HashMap));
    map->entries = (Entry*)malloc(capacity * sizeof(Entry));
    map->size = 0;
    map->capacity = capacity;
    return map;
}

int hash(const char* str, int capacity) {
    int hash = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        hash = (hash * 31 + str[i]) % capacity;
    }
    return hash;
}

void put(HashMap* map, const char* key, int value) {
    int index = hash(key, map->capacity);
    while (map->entries[index].key[0] != '\0' && strcmp(map->entries[index].key, key) != 0) {
        index = (index + 1) % map->capacity;
    }
    if (map->entries[index].key[0] == '\0') {
        map->size++;
    }
    strcpy(map->entries[index].key, key);
    map->entries[index].value = value;
}

int get(HashMap* map, const char* key) {
    int index = hash(key, map->capacity);
    while (map->entries[index].key[0] != '\0' && strcmp(map->entries[index].key, key) != 0) {
        index = (index + 1) % map->capacity;
    }
    if (map->entries[index].key[0] == '\0') {
        return -1; // Key not found
    }
    return map->entries[index].value;
}

int main() {
    int n;
    char com[13], str[10];
    HashMap* T = createHashMap(1000); // Initial capacity

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s%s", com, str);
        if (com[0] == 'i') {
            put(T, str, 1);
        } else {
            if (get(T, str) != -1) {
                printf("yes\n");
            } else {
                printf("no\n");
            }
        }
    }

    free(T->entries);
    free(T);
    return 0;
}
