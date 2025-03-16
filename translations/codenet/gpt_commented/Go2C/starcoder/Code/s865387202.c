

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent a city with its prefecture, year, and position
typedef struct {
	int prefecture; // Prefecture number
	int position;   // Position in the input
	int year;       // Year associated with the city
} city;

// Define a map where the key is an integer (prefecture) and the value is a slice of cities
typedef struct {
	city **cities;
	int size;
} cMap;

// Define a slice of city pointers for sorting
typedef city *cities[10000];

// Define a function to read city data from input
void readCities(cMap *h, int n, int m) {
	int i;
	for (i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d\n", &x, &y);
		
		// Check if the prefecture already exists in the map
		cMap *entry = h->cities[x];
		if (entry == NULL) {
			// If it doesn't exist, create a new entry with the city
			city *c = malloc(sizeof(city));
			c->prefecture = x;
			c->year = y;
			c->position = i;
			h->cities[x] = c;
			h->size++;
		} else {
			// If it exists, append the new city to the existing slice
			city *c = malloc(sizeof(city));
			c->prefecture = x;
			c->year = y;
			c->position = i;
			h->cities[x] = realloc(entry, sizeof(city) * (h->size + 1));
			h->cities[x][h->size] = *c;
			h->size++;
		}
	}
}

// Define a function to sort cities by year
void sortCities(cities *c) {
	int i, j;
	for (i = 0; i < c->size; i++) {
		for (j = i + 1; j < c->size; j++) {
			if (c->cities[i]->year > c->cities[j]->year) {
				city *temp = c->cities[i];
				c->cities[i] = c->cities[j];
				c->cities[j] = temp;
			}
		}
	}
}

// Define a function to format the output for each city based on its position and year
void formatCities(cities *c, char **results) {
	int i;
	for (i = 0; i < c->size; i++) {
		char *s = malloc(sizeof(char) * 12);
		sprintf(s, "%06d%06d", c->cities[i]->prefecture, i + 1);
		results[c->cities[i]->position] = s;
	}
}

// Define a function to print the results, joining them with newline characters
void printResults(char **results, int m) {
	int i;
	for (i = 0; i < m; i++) {
		printf("%s\n", results[i]);
	}
}

int main() {
	int n, m;
	scanf("%d %d\n", &n, &m);
	
	// Initialize a map to hold cities grouped by their prefecture
	cMap h = {NULL, 0};
	
	// Read city data from input
	readCities(&h, n, m);
	
	// Prepare a results slice to hold formatted output for each city
	char *results[10000] = {NULL};
	
	// Iterate over each group of cities in the map
	int i;
	for (i = 0; i < h.size; i++) {
		// Sort the cities by year using the sortCities function defined above
		sortCities(h.cities[i]);
		// Format the output for each city based on its position and year
		formatCities(h.cities[i], results);
	}
	
	// Print the results, joining them with newline characters
	printResults(results, m);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent a city with its prefecture, year, and position
typedef struct {
	int prefecture; // Prefecture number
	int position;   // Position in the input
	int year;       // Year associated with the city
} city;

// Define a map where the key is an integer (prefecture) and the value is a slice of cities
typedef struct {
	city **cities;
	int size;
} cMap;

// Define a slice of city pointers for sorting
typedef city *cities[10000];

// Define a function to read city data from input
void readCities(cMap *h, int n, int m) {
	int i;
	for (i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d\n", &x, &y);
		
		// Check if the prefecture already exists in the map
		cMap *entry = h->cities[x];
		if (entry == NULL) {
			// If it doesn't exist, create a new entry with the city
			city *c = malloc(sizeof(city));
			c->prefecture = x;
			c->year = y;
			c->position = i;
			h->cities[x] = c;
			h->size++;
		} else {
			// If it exists, append the new city to the existing slice
			city *c = malloc(sizeof(city));
			c->prefecture = x;
			c->year = y;
			c->position = i;
			h->cities[x] = realloc(entry, sizeof(city) * (h->size + 1));
			h->cities[x][h->size] = *c;
			h->size++;
		}
	}
}

// Define a function to sort cities by year
void sortCities(cities *c) {
	int i, j;
	for (i = 0; i < c->size; i++) {
		for (j = i + 1; j < c->size; j++) {
			if (c->cities[i]->year > c->cities[j]->year) {
				city *temp = c->cities[i];
				c->cities[i] = c->cities[j];
				c->cities[j] = temp;
			}
		}
	}
}

// Define a function to format the output for each city based on its position and year
void formatCities(cities *c, char **results) {
	int i;
	for (i = 0; i < c->size; i++) {
		char *s = malloc(sizeof(char) * 12);
		sprintf(s, "%06d%06d", c->cities[i]->prefecture, i + 1);
		results[c->cities[i]->position] = s;
	}
}

// Define a function to print the results, joining them with newline characters
void printResults(char **results, int m) {
	int i;
	for (i = 0; i < m; i++) {
		printf("%s\n", results[i]);
	}
}

int main() {
	int n, m;
	scanf("%d %d\n", &n, &m);
	
	// Initialize a map to hold cities grouped by their prefecture
	cMap h = {NULL, 0};
	
	// Read city data from input
	readCities(&h, n, m);
	
	// Prepare a results slice to hold formatted output for each city
	char *results[10000] = {NULL};
	
	// Iterate over each group of cities in the map
	int i;
	for (i = 0; i < h.size; i++) {
		// Sort the cities by year using the sortCities function defined above
		sortCities(h.cities[i]);
		// Format the output for each city based on its position and year
		formatCities(h.cities[i], results);
	}
	
	// Print the results, joining them with newline characters
	printResults(results, m);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent a city with its prefecture, year, and position
typedef struct {
	int prefecture; // Prefecture number
	int position;   // Position in the input
	int year;       // Year associated with the city
} city;

// Define a map where the key is an integer (prefecture) and the value is a slice of cities
typedef struct {
	city **cities;
	int size;
} cMap;

// Define a slice of city pointers for sorting
typedef city *cities[10000];

// Define a function to read city data from input
void readCities(cMap *h, int n, int m) {
	int i;
	for (i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d\n", &x, &y);
		
		// Check if the prefecture already exists in the map
		cMap *entry = h->cities[x];
		if (entry == NULL) {
			// If it doesn't exist, create a new entry with the city
			city *c = malloc(sizeof(city));
			c->prefecture = x;
			c->year = y;
			c->position = i;
			h->cities[x] = c;
			h->size++;
		} else {
			// If it exists, append the new city to the existing slice
			city *c = malloc(sizeof(city));
			c->prefecture = x;
			c->year = y;
			c->position = i;
			h->cities[x] = realloc(entry, sizeof(city) * (h->size + 1));
			h->cities[x][h->size] = *c;
			h->size++;
		}
	}
}

// Define a function to sort cities by year
void sortCities(cities *c) {
	int i, j;
	for (i = 0; i < c->size; i++) {
		for (j = i + 1; j < c->size; j++) {
			if (c->cities[i]->year > c->cities[j]->year) {
				city *temp = c->cities[i];
				c->cities[i] = c->cities[j];
				c->cities[j] = temp;
			}
		}
	}
}

// Define a function to format the output for each city based on its position and year
void formatCities(cities *c, char **results) {
	int i;
	for (i = 0; i < c->size; i++) {
		char *s = malloc(sizeof(char) * 12);
		sprintf(s, "%06d%06d", c->cities[i]->prefecture, i + 1);
		results[c->cities[i]->position] = s;
	}
}

// Define a function to print the results, joining them with newline characters
void printResults(char **results, int m) {
	int i;
	for (i = 0; i < m; i++) {
		printf("%s\n", results[i]);
	}
}

int main() {
	int n, m;
	scanf("%d %d\n", &n, &m);
	
	// Initialize a map to hold cities grouped by their prefecture
	cMap h = {NULL, 0};
	
	// Read city data from input
	readCities(&h, n, m);
	
	// Prepare a results slice to hold formatted output for each city
	char *results[10000] = {NULL};
	
	// Iterate over each group of cities in the map
	int i;
	for (i = 0; i < h.size; i++) {
		// Sort the cities by year using the sortCities function defined above
		sortCities(h.cities[i]);
		// Format the output for each city based on its position and year
		formatCities(h.cities[i], results);
	}
	
	// Print the results, joining them with newline characters
	printResults(results, m);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent a city with its prefecture, year, and position
typedef struct {
	int prefecture; // Prefecture number
	int position;   // Position in the input
	int year;       // Year associated with the city
} city;

// Define a map where the key is an integer (prefecture) and the value is a slice of cities
typedef struct {
	city **cities;
	int size;
} cMap;

// Define a slice of city pointers for sorting
typedef city *cities[10000];

// Define a function to read city data from input
void readCities(cMap *h, int n, int m) {
	int i;
	for (i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d\n", &x, &y);
		
		// Check if the prefecture already exists in the map
		cMap *entry = h->cities[x];
		if (entry == NULL) {
			// If it doesn't exist, create a new entry with the city
			city *c = malloc(sizeof(city));
			c->prefecture = x;
			c->year = y;
			c->position = i;
			h->cities[x] = c;
			h->size++;
		} else {
			// If it exists, append the new city to the existing slice
			city *c = malloc(sizeof(city));
			c->prefecture = x;
			c->year = y;
			c->position = i;
			h->cities[x] = realloc(entry, sizeof(city) * (h->size + 1));
			h->cities[x][h->size] = *c;
			h->size++;
		}
	}
}

// Define a function to sort cities by year
void sortCities(cities *c) {
	int i, j;
	for (i = 0; i < c->size; i++) {
		for (j = i + 1; j < c->size; j++) {
			if (c->cities[i]->year > c->cities[j]->year) {
				city *temp = c->cities[i];
				c->cities[i] = c->cities[j];
				c->cities[j] = temp;
			}
		}
	}
}

// Define a function to format the output for each city based on its position and year
void formatCi