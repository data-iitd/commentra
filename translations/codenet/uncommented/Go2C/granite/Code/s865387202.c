
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
} cMap;

int compareCities(const void *a, const void *b) {
    city *c1 = *(city **)a;
    city *c2 = *(city **)b;
    return c1->year - c2->year;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    cMap map;
    map.cities = (city **)malloc(sizeof(city *) * n);
    map.size = 0;
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        if (map.size < x) {
            map.size = x;
        }
        city *c = (city *)malloc(sizeof(city));
        c->prefecture = x;
        c->year = y;
        c->position = i;
        map.cities[x - 1] = c;
    }
    for (int i = 0; i < map.size; i++) {
        if (map.cities[i]!= NULL) {
            qsort(map.cities[i], m, sizeof(city), compareCities);
        }
    }
    char **results = (char **)malloc(sizeof(char *) * m);
    for (int i = 0; i < map.size; i++) {
        if (map.cities[i]!= NULL) {
            for (int j = 0; j < m; j++) {
                city *c = map.cities[i][j];
                char *result = (char *)malloc(sizeof(char) * 12);
                sprintf(result, "%06d%06d", c->prefecture, j + 1);
                results[c->position] = result;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        printf("%s\n", results[i]);
        free(results[i]);
    }
    free(results);
    for (int i = 0; i < map.size; i++) {
        if (map.cities[i]!= NULL) {
            for (int j = 0; j < m; j++) {
                free(map.cities[i][j]);
            }
            free(map.cities[i]);
        }
    }
    free(map.cities);
    return 0;
}
