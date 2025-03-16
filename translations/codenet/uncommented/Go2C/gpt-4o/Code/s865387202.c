#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int prefecture;
    int position;
    int year;
} City;

typedef struct {
    City *cities;
    int count;
} CityList;

typedef struct {
    CityList *lists;
    int size;
} CityMap;

int compare(const void *a, const void *b) {
    City *cityA = (City *)a;
    City *cityB = (City *)b;
    return cityA->year - cityB->year;
}

int main() {
    int n, m;
    scanf("%d %d\n", &n, &m);
    
    CityMap cityMap;
    cityMap.lists = (CityList *)calloc(n + 1, sizeof(CityList));
    cityMap.size = n + 1;

    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d %d\n", &x, &y);
        
        CityList *list = &cityMap.lists[x];
        list->cities = (City *)realloc(list->cities, (list->count + 1) * sizeof(City));
        list->cities[list->count].prefecture = x;
        list->cities[list->count].year = y;
        list->cities[list->count].position = i;
        list->count++;
    }

    char results[m][13]; // 12 for the formatted string + 1 for null terminator

    for (int i = 1; i < cityMap.size; i++) {
        if (cityMap.lists[i].count > 0) {
            qsort(cityMap.lists[i].cities, cityMap.lists[i].count, sizeof(City), compare);
            for (int idx = 0; idx < cityMap.lists[i].count; idx++) {
                City *ci = &cityMap.lists[i].cities[idx];
                sprintf(results[ci->position], "%06d%06d", ci->prefecture, idx + 1);
            }
        }
    }

    for (int i = 0; i < m; i++) {
        printf("%s\n", results[i]);
    }

    // Free allocated memory
    for (int i = 1; i < cityMap.size; i++) {
        free(cityMap.lists[i].cities);
    }
    free(cityMap.lists);

    return 0;
}

// <END-OF-CODE>
