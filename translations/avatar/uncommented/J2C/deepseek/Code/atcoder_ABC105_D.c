#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} IntArray;

IntArray* createIntArray(int capacity) {
    IntArray* array = (IntArray*)malloc(sizeof(IntArray));
    array->data = (int*)malloc(capacity * sizeof(int));
    array->size = 0;
    array->capacity = capacity;
    return array;
}

void appendIntArray(IntArray* array, int value) {
    if (array->size == array->capacity) {
        array->capacity *= 2;
        array->data = (int*)realloc(array->data, array->capacity * sizeof(int));
    }
    array->data[array->size++] = value;
}

void freeIntArray(IntArray* array) {
    free(array->data);
    free(array);
}

typedef struct {
    char **tokens;
    int size;
    int capacity;
} StringArray;

StringArray* createStringArray(int capacity) {
    StringArray* array = (StringArray*)malloc(sizeof(StringArray));
    array->tokens = (char**)malloc(capacity * sizeof(char*));
    array->size = 0;
    array->capacity = capacity;
    return array;
}

void appendStringArray(StringArray* array, char* value) {
    if (array->size == array->capacity) {
        array->capacity *= 2;
        array->tokens = (char**)realloc(array->tokens, array->capacity * sizeof(char*));
    }
    array->tokens[array->size++] = value;
}

void freeStringArray(StringArray* array) {
    for (int i = 0; i < array->size; i++) {
        free(array->tokens[i]);
    }
    free(array->tokens);
    free(array);
}

typedef struct {
    int *data;
    int size;
    int capacity;
} HashMap;

HashMap* createHashMap(int capacity) {
    HashMap* map = (HashMap*)malloc(sizeof(HashMap));
    map->data = (int*)calloc(capacity, sizeof(int));
    map->size = 0;
    map->capacity = capacity;
    return map;
}

void putHashMap(HashMap* map, int key, int value) {
    if (map->size == map->capacity) {
        map->capacity *= 2;
        map->data = (int*)realloc(map->data, map->capacity * sizeof(int));
        memset(map->data + map->size, 0, (map->capacity - map->size) * sizeof(int));
    }
    map->data[key] = value;
    map->size++;
}

int getHashMap(HashMap* map, int key, int defaultValue) {
    if (key >= 0 && key < map->capacity) {
        return map->data[key];
    }
    return defaultValue;
}

void freeHashMap(HashMap* map) {
    free(map->data);
    free(map);
}

long solve(int n, int m, IntArray* a) {
    HashMap* dp = createHashMap(m);
    long ans = 0;
    int base = 0;
    for (int i = 0; i < n; i++) {
        base = (base - a->data[i] % m + m) % m;
        putHashMap((base + a->data[i]) % m, 1, dp);
        ans += getHashMap(base, 0, dp);
    }
    freeHashMap(dp);
    return ans;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    IntArray* a = createIntArray(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a->data[a->size++]);
    }
    long ans = solve(n, m, a);
    printf("%ld\n", ans);
    freeIntArray(a);
    return 0;
}
