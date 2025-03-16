#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int key;
    int value;
} Pair;

typedef struct {
    Pair *pairs;
    int size;
    int capacity;
} Map;

void initMap(Map *map, int capacity) {
    map->pairs = (Pair *)malloc(capacity * sizeof(Pair));
    map->size = 0;
    map->capacity = capacity;
}

void put(Map *map, int key, int value) {
    for (int i = 0; i < map->size; i++) {
        if (map->pairs[i].key == key) {
            map->pairs[i].value = value;
            return;
        }
    }
    if (map->size < map->capacity) {
        map->pairs[map->size].key = key;
        map->pairs[map->size].value = value;
        map->size++;
    }
}

int get(Map *map, int key) {
    for (int i = 0; i < map->size; i++) {
        if (map->pairs[i].key == key) {
            return map->pairs[i].value;
        }
    }
    return -1; // Return -1 if key is not found
}

void freeMap(Map *map) {
    free(map->pairs);
}

int main() {
    // Step 1: Read the input value N, which represents the number of elements.
    int N;
    scanf("%d", &N);

    // Step 2: Create a map idorder to store the elements and their corresponding positions.
    Map idorder;
    initMap(&idorder, N);

    // Step 3: Read each element and store its value and position in the map.
    for (int i = 1; i <= N; i++) {
        int A;
        scanf("%d", &A);
        put(&idorder, A, i);
    }

    // Step 4: Print the positions of the elements in the order they were read.
    for (int i = 1; i <= N; i++) {
        printf("%d ", get(&idorder, i));
    }

    // Free the allocated memory for the map
    freeMap(&idorder);
    
    return 0;
}

// <END-OF-CODE>
