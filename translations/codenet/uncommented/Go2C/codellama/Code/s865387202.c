#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct city {
	int prefecture;
	int position;
	int year;
} city;

typedef struct cities {
	city *cities;
	int size;
} cities;

typedef struct cMap {
	cities *cities;
	int size;
} cMap;

int cmp(const void *a, const void *b) {
	city *c1 = (city *)a;
	city *c2 = (city *)b;
	return c1->year - c2->year;
}

int main() {
	int n, m;
	scanf("%d %d\n", &n, &m);
	cMap h = (cMap){.size = n};
	h.cities = (cities *)malloc(sizeof(cities) * n);
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d\n", &x, &y);
		if (h.cities[x].size == 0) {
			h.cities[x].cities = (city *)malloc(sizeof(city));
			h.cities[x].cities[0] = (city){.prefecture = x, .year = y, .position = i};
			h.cities[x].size = 1;
		} else {
			h.cities[x].cities = (city *)realloc(h.cities[x].cities, sizeof(city) * (h.cities[x].size + 1));
			h.cities[x].cities[h.cities[x].size] = (city){.prefecture = x, .year = y, .position = i};
			h.cities[x].size++;
		}
	}

	char *results = (char *)malloc(sizeof(char) * 12 * m);
	for (int i = 0; i < n; i++) {
		qsort(h.cities[i].cities, h.cities[i].size, sizeof(city), cmp);
		for (int j = 0; j < h.cities[i].size; j++) {
			sprintf(results + 12 * h.cities[i].cities[j].position, "%06d%06d", h.cities[i].cities[j].prefecture, j + 1);
		}
	}
	printf("%s\n", results);
	free(results);
	for (int i = 0; i < n; i++) {
		free(h.cities[i].cities);
	}
	free(h.cities);
	return 0;
}

