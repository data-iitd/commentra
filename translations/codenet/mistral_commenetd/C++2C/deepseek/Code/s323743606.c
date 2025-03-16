#include <stdio.h>
#include <stdlib.h>

// Define a structure for the map entries
typedef struct {
    int key;
    int value;
} MapEntry;

// Define a structure for the map
typedef struct {
    MapEntry *entries;
    int size;
    int capacity;
} Map;

// Initialize a map
Map* createMap(int capacity) {
    Map* map = (Map*)malloc(sizeof(Map));
    map->entries = (MapEntry*)malloc(capacity * sizeof(MapEntry));
    map->size = 0;
    map->capacity = capacity;
    return map;
}

// Hash function
int hash(int key, int capacity) {
    return abs(key) % capacity;
}

// Insert a key-value pair into the map
void mapInsert(Map* map, int key, int value) {
    if (map->size >= map->capacity) {
        map->capacity *= 2;
        map->entries = (MapEntry*)realloc(map->entries, map->capacity * sizeof(MapEntry));
    }
    int index = hash(key, map->capacity);
    while (map->entries[index].key != 0) {
        index = (index + 1) % map->capacity;
    }
    map->entries[index].key = key;
    map->entries[index].value = value;
    map->size++;
}

// Find the value associated with a key in the map
int mapFind(Map* map, int key) {
    int index = hash(key, map->capacity);
    while (map->entries[index].key != 0) {
        if (map->entries[index].key == key) {
            return map->entries[index].value;
        }
        index = (index + 1) % map->capacity;
    }
    return -1; // Key not found
}

int main() {
    Map* m = createMap(1000); // Initialize an empty map with a capacity of 1000

    // Iterate through all possible indices 'i' that satisfy the condition i*200 < 5001
    for (int i = 0; i * 200 < 5001; i++) {
        // Iterate through all possible indices 'j' that satisfy the condition j*300 < 5001
        for (int j = 0; j * 300 < 5001; j++) {
            // Iterate through all possible indices 'k' that satisfy the condition k*500 < 5001
            for (int k = 0; k * 500 < 5001; k++) {
                // Calculate the composite index 'w'
                int w = i * 200 + j * 300 + k * 500;

                // Calculate the potential value 'p' for the given index 'w'
                int p = i / 5 * 5 * 380 * 0.8 + i % 5 * 380
                        + j / 4 * 4 * 550 * 0.85 + j % 4 * 550
                        + k / 3 * 3 * 850 * 0.88 + k % 3 * 850;

                // If the map 'm' already contains the index 'w', update its value with the minimum of the current potential value and the existing one
                if (mapFind(m, w) != -1) {
                    int existingValue = mapFind(m, w);
                    if (p < existingValue) {
                        mapInsert(m, w, p);
                    }
                }
                // If the map 'm' does not contain the index 'w', add it with the current potential value as its value
                else {
                    mapInsert(m, w, p);
                }
            }
        }
    }

    // Read integers from the standard input and print their corresponding potential values from the map 'm'
    int n;
    while (scanf("%d", &n) != EOF && n) {
        int result = mapFind(m, n);
        if (result != -1) {
            printf("%d\n", result);
        } else {
            printf("Key not found\n");
        }
    }

    // Free the allocated memory
    free(m->entries);
    free(m);

    return 0;
}
