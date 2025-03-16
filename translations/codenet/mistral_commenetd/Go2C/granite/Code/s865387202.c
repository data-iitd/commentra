
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int prefecture;
    int position;
    int year;
} city;

typedef struct {
    city **cities;
    int size;
} cities;

typedef struct {
    int key;
    cities *value;
} cMap;

typedef struct {
    cMap *map;
    int size;
} cMap;

int compareCities(const void *a, const void *b) {
    city *c1 = *(city **)a;
    city *c2 = *(city **)b;
    return c1->year - c2->year;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    cMap *h = (cMap *)malloc(sizeof(cMap));
    h->size = 0;

    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);

        cMap *entry = NULL;
        for (int j = 0; j < h->size; j++) {
            if (h->map[j].key == x) {
                entry = &h->map[j];
                break;
            }
        }

        if (entry == NULL) {
            cities *cities = (cities *)malloc(sizeof(cities));
            cities->size = 0;
            entry = (cMap *)malloc(sizeof(cMap));
            entry->key = x;
            entry->value = cities;
            h->map = (cMap *)realloc(h->map, (h->size + 1) * sizeof(cMap));
            h->map[h->size++] = *entry;
        }

        city *city = (city *)malloc(sizeof(city));
        city->prefecture = x;
        city->year = y;
        city->position = i;
        entry->value->cities = (city **)realloc(entry->value->cities, (entry->value->size + 1) * sizeof(city *));
        entry->value->cities[entry->value->size++] = city;
    }

    char **results = (char **)malloc(sizeof(char *) * m);
    for (int i = 0; i < m; i++) {
        results[i] = (char *)malloc(sizeof(char) * 12);
    }

    for (int i = 0; i < h->size; i++) {
        qsort(h->map[i].value->cities, h->map[i].value->size, sizeof(city *), compareCities);
        for (int j = 0; j < h->map[i].value->size; j++) {
            sprintf(results[h->map[i].value->cities[j]->position], "%06d%06d", h->map[i].value->cities[j]->prefecture, j + 1);
        }
    }

    for (int i = 0; i < m; i++) {
        printf("%s\n", results[i]);
        free(results[i]);
    }
    free(results);

    for (int i = 0; i < h->size; i++) {
        for (int j = 0; j < h->map[i].value->size; j++) {
            free(h->map[i].value->cities[j]);
        }
        free(h->map[i].value->cities);
        free(h->map[i].value);
        free(h->map[i].key);
    }
    free(h->map);
    free(h);

    return 0;
}

// End of code