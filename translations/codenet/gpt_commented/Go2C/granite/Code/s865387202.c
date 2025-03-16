
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct city {
    int prefecture;
    int position;
    int year;
} city;

typedef struct cities {
    city **cities;
    int size;
} cities;

typedef struct cMap {
    cities *cities;
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
    h->size = n;
    h->cities = (cities *)malloc(sizeof(cities) * n);

    for (int i = 0; i < n; i++) {
        h->cities[i].size = 0;
    }

    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        city *c = (city *)malloc(sizeof(city));
        c->prefecture = x;
        c->year = y;
        c->position = i;
        h->cities[x - 1].cities[h->cities[x - 1].size++] = c;
    }

    char **results = (char **)malloc(sizeof(char *) * m);

    for (int i = 0; i < n; i++) {
        qsort(h->cities[i].cities, h->cities[i].size, sizeof(city *), compareCities);
        for (int j = 0; j < h->cities[i].size; j++) {
            char result[12];
            sprintf(result, "%06d%06d", h->cities[i].cities[j]->prefecture, j + 1);
            results[h->cities[i].cities[j]->position] = (char *)malloc(sizeof(char) * 12);
            strcpy(results[h->cities[i].cities[j]->position], result);
        }
    }

    for (int i = 0; i < m; i++) {
        printf("%s\n", results[i]);
        free(results[i]);
    }

    free(results);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < h->cities[i].size; j++) {
            free(h->cities[i].cities[j]);
        }
        free(h->cities[i].cities);
    }

    free(h->cities);
    free(h);

    return 0;
}
