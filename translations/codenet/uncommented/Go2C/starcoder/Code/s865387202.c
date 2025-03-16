#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

#define MAX_CITIES 100000
#define MAX_YEAR 1000000

typedef struct {
	int prefecture;
	int position;
	int year;
} city;

typedef struct {
	city cities[MAX_CITIES];
	int size;
} cities;

typedef struct {
	cities cities[MAX_YEAR];
	int size;
} cMap;

void swap(city *a, city *b) {
	city tmp = *a;
	*a = *b;
	*b = tmp;
}

void sortCities(cities *c) {
	for (int i = 0; i < c->size; i++) {
		for (int j = i + 1; j < c->size; j++) {
			if (c->cities[i].year > c->cities[j].year) {
				swap(&c->cities[i], &c->cities[j]);
			}
		}
	}
}

void sortCMap(cMap *h) {
	for (int i = 0; i < h->size; i++) {
		sortCities(&h->cities[i]);
	}
}

void printCMap(cMap *h) {
	for (int i = 0; i < h->size; i++) {
		for (int j = 0; j < h->cities[i].size; j++) {
			printf("%06d%06d\n", h->cities[i].cities[j].prefecture, h->cities[i].cities[j].position);
		}
	}
}

int main() {
	int n, m;
	scanf("%d %d\n", &n, &m);
	cMap h;
	h.size = 0;
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d\n", &x, &y);
		if (h.cities[x].size == 0) {
			h.cities[x].cities[h.cities[x].size].prefecture = x;
			h.cities[x].cities[h.cities[x].size].position = i;
			h.cities[x].cities[h.cities[x].size].year = y;
			h.cities[x].size++;
		} else {
			h.cities[x].cities[h.cities[x].size].prefecture = x;
			h.cities[x].cities[h.cities[x].size].position = i;
			h.cities[x].cities[h.cities[x].size].year = y;
			h.cities[x].size++;
		}
	}
	sortCMap(&h);
	printCMap(&h);
	return 0;
}

