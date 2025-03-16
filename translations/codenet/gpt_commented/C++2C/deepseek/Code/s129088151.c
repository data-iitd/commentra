#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char key[10];
    int value;
} Entry;

typedef struct {
    Entry *entries;
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

int hash(const char* key, int capacity) {
    int hash = 0;
    while (*key) {
        hash = (hash * 31) + *key++;
    }
    return abs(hash) % capacity;
}

void put(HashMap* map, const char* key, int value) {
    int index = hash(key, map->capacity);
    while (map->entries[index].value != 0) {
        index = (index + 1) % map->capacity;
    }
    strcpy(map->entries[index].key, key);
    map->entries[index].value = value;
    map->size++;
}

int get(HashMap* map, const char* key) {
    int index = hash(key, map->capacity);
    while (map->entries[index].value != 0) {
        if (strcmp(map->entries[index].key, key) == 0) {
            return map->entries[index].value;
        }
        index = (index + 1) % map->capacity;
    }
    return 0;
}

int main() {
    int n;
    char str[10], com[13];
    HashMap* T = createHashMap(1000); // Initial capacity, can be adjusted

    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%s%s", com, str);
        
        if (com[0] == 'i') {
            put(T, str, 1);
        } else {
            if (get(T, str)) {
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
