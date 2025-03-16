#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

// Represents a city
typedef struct {
	int prefecture; // Represents the prefecture number of the city
	int position; // Represents the position of the city in its prefecture
	int year; // Represents the year the city was established
} city;

// A slice of city pointers
typedef city* cities[100000];

// A map from prefecture numbers to slices of city pointers
typedef cities cMap[100000];

// Sorts the cities within the prefecture
void sortCities(cities c) {
	for (int i = 0; i < 100000; i++) {
		for (int j = 0; j < 100000; j++) {
			if (c[i][j].year < c[i][j+1].year) {
				city temp = c[i][j];
				c[i][j] = c[i][j+1];
				c[i][j+1] = temp;
			}
		}
	}
}

// Formats the city string
char* formatCity(city c) {
	char* s = (char*) malloc(sizeof(char) * 100000);
	sprintf(s, "%06d%06d", c.prefecture, c.position);
	return s;
}

// Main function
int main(int argc, char* argv[]) {
	int n, m;
	scanf("%d %d\n", &n, &m);
	cMap h;
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d\n", &x, &y);
		bool exists = false;
		for (int j = 0; j < 100000; j++) {
			if (h[x][j].prefecture == x) {
				exists = true;
				break;
			}
		}
		if (!exists) {
			h[x][0] = (city) {x, 0, y};
		} else {
			h[x][0].year = y;
		}
	}
	for (int i = 0; i < 100000; i++) {
		sortCities(h[i]);
	}
	char* results[100000];
	for (int i = 0; i < 100000; i++) {
		for (int j = 0; j < 100000; j++) {
			results[h[i][j].position] = formatCity(h[i][j]);
		}
	}
	for (int i = 0; i < 100000; i++) {
		printf("%s\n", results[i]);
	}
	return 0;
}

