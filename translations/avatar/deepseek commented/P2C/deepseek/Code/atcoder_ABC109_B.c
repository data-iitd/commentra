#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

typedef struct {
    char key[MAX_STRING_LENGTH];
    int value;
} Entry;

typedef struct {
    Entry *entries;
    int size;
    int capacity;
} HashMap;

HashMap* createHashMap(int capacity) {
    HashMap* map = (HashMap*)malloc(sizeof(HashMap));
    map->entries = (Entry*)calloc(capacity, sizeof(Entry));
    map->size = 0;
    map->capacity = capacity;
    return map;
}

int hash(HashMap* map, const char* key) {
    int hash = 0;
    while (*key) {
        hash = (hash * 31) + *key++;
    }
    return abs(hash) % map->capacity;
}

void put(HashMap* map, const char* key) {
    int index = hash(map, key);
    while (map->entries[index].value != 0 && strcmp(map->entries[index].key, key) != 0) {
        index = (index + 1) % map->capacity;
    }
    if (map->entries[index].value == 0) {
        map->size++;
    }
    strcpy(map->entries[index].key, key);
    map->entries[index].value++;
}

int main() {
    int n;
    scanf("%d", &n);
    HashMap* s = createHashMap(n);
    char l[n][MAX_STRING_LENGTH];
    for (int i = 0; i < n; i++) {
        scanf("%s", l[i]);
    }
    char f[] = "Yes";
    int i = -1;
    for (int j = 0; j < n; j++) {
        put(s, l[j]);
        if (s->entries[hash(s, l[j])].value >= 2) {
            strcpy(f, "No");
        }
        if (i != -1 && strcmp(l[i], l[j]) != 0 && l[i][strlen(l[i]) - 1] != l[j][0]) {
            strcpy(f, "No");
        }
        i++;
    }
    printf("%s\n", f);
    free(s->entries);
    free(s);
    return 0;
}
