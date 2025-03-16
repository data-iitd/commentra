#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CITIES 100000

typedef struct {
	int prefecture;
	int position;
	int year;
} city;

typedef struct {
	int prefecture;
	int size;
	city cities[MAX_CITIES];
} prefecture;

typedef struct {
	int size;
	prefecture prefectures[MAX_CITIES];
} cities;

void swap(city *a, city *b) {
	city temp = *a;
	*a = *b;
	*b = temp;
}

int compare(const void *a, const void *b) {
	return (*(city *)a).year - (*(city *)b).year;
}

void sort(prefecture *p) {
	qsort(p->cities, p->size, sizeof(city), compare);
}

void print(cities *c) {
	int i, j;
	for (i = 0; i < c->size; i++) {
		prefecture *p = &c->prefectures[i];
		sort(p);
		for (j = 0; j < p->size; j++) {
			city *c = &p->cities[j];
			printf("%06d%06d\n", c->prefecture, j + 1);
		}
	}
}

int main() {
	int n, m;
	scanf("%d %d\n", &n, &m);
	cities *c = malloc(sizeof(cities));
	c->size = n;
	int i, j;
	for (i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d\n", &x, &y);
		int exists = 0;
		for (j = 0; j < c->size; j++) {
			if (c->prefectures[j].prefecture == x) {
				exists = 1;
				break;
			}
		}
		if (!exists) {
			c->prefectures[j].prefecture = x;
			c->prefectures[j].size = 1;
			c->prefectures[j].cities[0].prefecture = x;
			c->prefectures[j].cities[0].year = y;
			c->prefectures[j].cities[0].position = i;
		} else {
			c->prefectures[j].cities[c->prefectures[j].size].prefecture = x;
			c->prefectures[j].cities[c->prefectures[j].size].year = y;
			c->prefectures[j].cities[c->prefectures[j].size].position = i;
			c->prefectures[j].size++;
		}
	}
	print(c);
	return 0;
}

