#include <stdio.h>
#include <stdlib.h>

// Define a custom city type with three fields: prefecture, position, and year.
typedef struct {
    int prefecture;
    int position;
    int year;
} City;

// Define a custom cities type as a dynamic array of City pointers.
typedef struct {
    City** data;
    int size;
    int capacity;
} Cities;

// Define a custom cMap type as a dynamic array of Cities pointers.
typedef struct {
    Cities* data;
    int size;
    int capacity;
} CMap;

// Function to initialize a new Cities array.
Cities* createCities(int capacity) {
    Cities* cities = (Cities*)malloc(sizeof(Cities));
    cities->data = (City**)malloc(capacity * sizeof(City*));
    cities->size = 0;
    cities->capacity = capacity;
    return cities;
}

// Function to initialize a new CMap.
CMap* createCMap(int capacity) {
    CMap* cMap = (CMap*)malloc(sizeof(CMap));
    cMap->data = (Cities*)malloc(capacity * sizeof(Cities));
    cMap->size = 0;
    cMap->capacity = capacity;
    return cMap;
}

// Main function is the entry point of the program.
int main() {
    // Read the number of cities and events from the standard input.
    int n, m;
    scanf("%d %d", &n, &m);

    // Initialize an empty cMap named h.
    CMap* h = createCMap(n);

    // Read m pairs of integers x and y from the standard input.
    for (int i = 0; i < m; i++) {
        // Read an integer x from the standard input.
        int x;
        scanf("%d", &x);

        // Read an integer y from the standard input.
        int y;
        scanf("%d", &y);

        // Check if the prefecture x already exists in the cMap.
        int found = -1;
        for (int j = 0; j < h->size; j++) {
            if (h->data[j].data[0]->prefecture == x) {
                found = j;
                break;
            }
        }

        // If the prefecture x does not exist in the cMap, create a new cities array with one element and assign it to the key x in the cMap.
        if (found == -1) {
            h->data[h->size].data = (City**)malloc(1 * sizeof(City*));
            h->data[h->size].data[0] = (City*)malloc(sizeof(City));
            h->data[h->size].data[0]->prefecture = x;
            h->data[h->size].data[0]->year = y;
            h->data[h->size].data[0]->position = i;
            h->data[h->size].size = 1;
            h->data[h->size].capacity = 1;
            h->size++;
        } else {
            // If the prefecture x already exists in the cMap, append a new city struct to the existing cities array.
            h->data[found].data = (City**)realloc(h->data[found].data, (h->data[found].size + 1) * sizeof(City*));
            h->data[found].data[h->data[found].size] = (City*)malloc(sizeof(City));
            h->data[found].data[h->data[found].size]->prefecture = x;
            h->data[found].data[h->data[found].size]->year = y;
            h->data[found].data[h->data[found].size]->position = i;
            h->data[found].size++;
        }
    }

    // Initialize a char array named results with length m and zeroed elements.
    char** results = (char**)malloc(m * sizeof(char*));
    for (int i = 0; i < m; i++) {
        results[i] = (char*)malloc(13 * sizeof(char)); // 6 for prefecture + 6 for position + 1 for null terminator
    }

    // Iterate through each value v in the cMap.
    for (int i = 0; i < h->size; i++) {
        // Sort the cities array v using the Less method.
        for (int j = 0; j < h->data[i].size - 1; j++) {
            for (int k = 0; k < h->data[i].size - j - 1; k++) {
                if (h->data[i].data[k]->year > h->data[i].data[k + 1]->year) {
                    City* temp = h->data[i].data[k];
                    h->data[i].data[k] = h->data[i].data[k + 1];
                    h->data[i].data[k + 1] = temp;
                }
            }
        }

        // Iterate through each city struct ci in the sorted cities array v.
        for (int j = 0; j < h->data[i].size; j++) {
            // Format the result string using sprintf and assign it to the corresponding index in the results array.
            sprintf(results[h->data[i].data[j]->position], "%06d%06d", h->data[i].data[j]->prefecture, j + 1);
        }
    }

    // Print the final result using a loop and printf.
    for (int i = 0; i < m; i++) {
        if (i < m - 1) {
            printf("%s\n", results[i]);
        } else {
            printf("%s", results[i]);
        }
        free(results[i]);
    }
    free(results);

    // Free the memory allocated for the cMap.
    for (int i = 0; i < h->size; i++) {
        for (int j = 0; j < h->data[i].size; j++) {
            free(h->data[i].data[j]);
        }
        free(h->data[i].data);
    }
    free(h->data);
    free(h);

    return 0;
}

