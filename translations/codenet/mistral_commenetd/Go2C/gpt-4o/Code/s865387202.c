#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a custom city structure with three fields: prefecture, position, and year.
typedef struct {
    int prefecture;
    int position;
    int year;
} city;

// Define a custom cities type as a dynamic array of pointers to city structs.
typedef struct {
    city **array;
    size_t size;
    size_t capacity;
} cities;

// Define a custom cMap type as a struct with an integer key and a cities struct as the value.
typedef struct {
    int key;
    cities value;
} cMapEntry;

typedef struct {
    cMapEntry *entries;
    size_t size;
    size_t capacity;
} cMap;

// Function to initialize a cities structure.
void initCities(cities *c) {
    c->size = 0;
    c->capacity = 2;
    c->array = malloc(c->capacity * sizeof(city *));
}

// Function to append a city to the cities structure.
void appendCity(cities *c, city *cItem) {
    if (c->size >= c->capacity) {
        c->capacity *= 2;
        c->array = realloc(c->array, c->capacity * sizeof(city *));
    }
    c->array[c->size++] = cItem;
}

// Function to initialize a cMap structure.
void initCMap(cMap *m) {
    m->size = 0;
    m->capacity = 2;
    m->entries = malloc(m->capacity * sizeof(cMapEntry));
}

// Function to add a city to the cMap.
void addCityToMap(cMap *m, int prefecture, int year, int position) {
    for (size_t i = 0; i < m->size; i++) {
        if (m->entries[i].key == prefecture) {
            appendCity(&m->entries[i].value, &(city){prefecture, position, year});
            return;
        }
    }
    if (m->size >= m->capacity) {
        m->capacity *= 2;
        m->entries = realloc(m->entries, m->capacity * sizeof(cMapEntry));
    }
    m->entries[m->size].key = prefecture;
    initCities(&m->entries[m->size].value);
    appendCity(&m->entries[m->size].value, &(city){prefecture, position, year});
    m->size++;
}

// Comparison function for sorting cities by year.
int compareCities(const void *a, const void *b) {
    return (*(city **)a)->year - (*(city **)b)->year;
}

// Main function is the entry point of the program.
int main() {
    // Read the number of cities and events from the standard input.
    int n, m;
    scanf("%d %d\n", &n, &m);

    // Initialize an empty cMap named h.
    cMap h;
    initCMap(&h);

    // Read m pairs of integers x and y from the standard input.
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d %d\n", &x, &y);
        addCityToMap(&h, x, y, i);
    }

    // Initialize a results array with length m.
    char results[m][13]; // 12 for "000000000000" + 1 for '\0'

    // Iterate through each entry in the cMap.
    for (size_t i = 0; i < h.size; i++) {
        // Sort the cities slice using qsort.
        qsort(h.entries[i].value.array, h.entries[i].value.size, sizeof(city *), compareCities);

        // Iterate through each city struct in the sorted cities slice.
        for (size_t idx = 0; idx < h.entries[i].value.size; idx++) {
            city *ci = h.entries[i].value.array[idx];
            // Format the result string and assign it to the corresponding index in the results array.
            sprintf(results[ci->position], "%06d%06d", ci->prefecture, idx + 1);
        }
    }

    // Print the final result.
    for (int i = 0; i < m; i++) {
        printf("%s\n", results[i]);
    }

    // Free allocated memory (not shown for brevity).

    return 0;
}

// <END-OF-CODE>
