#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct city {
    int prefecture;
    int position;
    int year;
} City;

typedef City* CityPtr;

typedef struct cities {
    CityPtr* array;
    int size;
} Cities;

typedef Cities* CitiesPtr;

typedef struct cMap {
    CitiesPtr* map;
    int size;
} CMap;

typedef CMap* CMapPtr;

void readInput(int* n, int* m, CMapPtr h) {
    scanf("%d %d\n", n, m);
    h->map = (CitiesPtr*)malloc(sizeof(CitiesPtr) * (*n));
    h->size = *n;
    for (int i = 0; i < *m; i++) {
        int x, y;
        scanf("%d %d\n", &x, &y);
        if (h->map[x - 1] == NULL) {
            h->map[x - 1] = (CitiesPtr)malloc(sizeof(Cities));
            h->map[x - 1]->array = (CityPtr*)malloc(sizeof(CityPtr) * (*m));
            h->map[x - 1]->size = 0;
        }
        h->map[x - 1]->array[h->map[x - 1]->size] = (CityPtr)malloc(sizeof(City));
        h->map[x - 1]->array[h->map[x - 1]->size]->prefecture = x;
        h->map[x - 1]->array[h->map[x - 1]->size]->year = y;
        h->map[x - 1]->array[h->map[x - 1]->size]->position = i;
        h->map[x - 1]->size++;
    }
}

void sortCities(CitiesPtr cities) {
    for (int i = 0; i < cities->size - 1; i++) {
        for (int j = 0; j < cities->size - i - 1; j++) {
            if (cities->array[j]->year > cities->array[j + 1]->year) {
                CityPtr temp = cities->array[j];
                cities->array[j] = cities->array[j + 1];
                cities->array[j + 1] = temp;
            }
        }
    }
}

void generateResults(char** results, CitiesPtr cities, int m) {
    for (int i = 0; i < cities->size; i++) {
        sortCities(cities);
        for (int j = 0; j < cities->size; j++) {
            sprintf(results[cities->array[j]->position], "%06d%06d", cities->array[j]->prefecture, j + 1);
        }
    }
}

int main() {
    int n, m;
    CMapPtr h = (CMapPtr)malloc(sizeof(CMap));
    h->map = NULL;
    h->size = 0;

    readInput(&n, &m, h);

    char** results = (char**)malloc(sizeof(char*) * m);
    for (int i = 0; i < m; i++) {
        results[i] = (char*)malloc(13 * sizeof(char)); // 6 for prefecture + 6 for position + 1 for null terminator
    }

    generateResults(results, h->map[0], m);

    for (int i = 0; i < m; i++) {
        printf("%s\n", results[i]);
        free(results[i]);
    }
    free(results);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < h->map[i]->size; j++) {
            free(h->map[i]->array[j]);
        }
        free(h->map[i]->array);
        free(h->map[i]);
    }
    free(h->map);
    free(h);

    return 0;
}
