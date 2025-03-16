#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent a city with its prefecture, year, and position
typedef struct {
	int prefecture;
	int position;
	int year;
} city;

// Define a slice of city pointers for sorting
typedef city** cities;

// Define a map where the key is an integer (prefecture) and the value is a slice of cities
typedef struct {
	int key;
	cities value;
} cMap;

int main() {
	int n, m; // n: number of prefectures, m: number of cities
	
	// Read the number of prefectures and cities from input
	scanf("%d %d\n", &n, &m);
	
	// Initialize a map to hold cities grouped by their prefecture
	cMap h[n];
	
	// Read city data from input
	for (int i = 0; i < m; i++) {
		int x, y; // x: prefecture number, y: year
		scanf("%d %d\n", &x, &y);
		
		// Check if the prefecture already exists in the map
		int exists = 0;
		for (int j = 0; j < n; j++) {
			if (h[j].key == x) {
				exists = 1;
				break;
			}
		}
		if (!exists) {
			// If it doesn't exist, create a new entry with the city
			h[n].key = x;
			h[n].value = (cities)malloc(sizeof(city*));
			h[n].value[0] = (city*)malloc(sizeof(city));
			h[n].value[0]->prefecture = x;
			h[n].value[0]->year = y;
			h[n].value[0]->position = i;
			n++;
		} else {
			// If it exists, append the new city to the existing slice
			h[n].value = (cities)realloc(h[n].value, (n+1)*sizeof(city*));
			h[n].value[n] = (city*)malloc(sizeof(city));
			h[n].value[n]->prefecture = x;
			h[n].value[n]->year = y;
			h[n].value[n]->position = i;
			n++;
		}
	}

	// Prepare a results slice to hold formatted output for each city
	char** results = (char**)malloc(m*sizeof(char*));

	// Iterate over each group of cities in the map
	for (int i = 0; i < n; i++) {
		// Sort the cities by year using the Less method defined below
		qsort(h[i].value, n, sizeof(city*), Less);
		// Format the output for each city based on its position and year
		for (int j = 0; j < n; j++) {
			results[h[i].value[j]->position] = (char*)malloc(13*sizeof(char));
			sprintf(results[h[i].value[j]->position], "%06d%06d", h[i].value[j]->prefecture, j+1);
		}
	}
	
	// Print the results, joining them with newline characters
	for (int i = 0; i < m; i++) {
		printf("%s\n", results[i]);
	}
	
	// Free memory
	for (int i = 0; i < n; i++) {
		free(h[i].value);
	}
	free(h);
	for (int i = 0; i < m; i++) {
		free(results[i]);
	}
	free(results);
	
	return 0;
}

// Implement the Less method for sorting cities by year
int Less(const void* a, const void* b) {
	return (*(city**)a)->year < (*(city**)b)->year;
}

