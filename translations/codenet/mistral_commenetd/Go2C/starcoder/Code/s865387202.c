#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a custom city type with three fields: prefecture, position, and year.
typedef struct {
	int prefecture;
	int position;
	int year;
} city;

// Define a custom cities type as a slice of pointers to city structs.
typedef city* cities[100000];

// Define a custom cMap type as a map with an integer key and a cities slice as the value.
typedef struct {
	int key;
	cities value;
} cMap;

// Main function is the entry point of the program.
int main(int argc, char* argv[]) {
	// Read the number of cities and events from the standard input.
	int n, m;
	scanf("%d %d\n", &n, &m);

	// Initialize an empty cMap named h.
	cMap h[100000];

	// Read m pairs of integers x and y from the standard input.
	for (int i = 0; i < m; i++) {
		// Read an integer x from the standard input.
		int x;
		scanf("%d ", &x);

		// Read an integer y from the standard input.
		int y;
		scanf("%d\n", &y);

		// Check if the prefecture x already exists in the cMap.
		int exists = 0;
		for (int j = 0; j < n; j++) {
			if (h[j].key == x) {
				exists = 1;
				break;
			}
		}

		// If the prefecture x does not exist in the cMap, create a new cities slice with one element and assign it to the key x in the cMap.
		if (!exists) {
			cities v = malloc(sizeof(city));
			v[0].prefecture = x;
			v[0].year = y;
			v[0].position = i;
			h[x].key = x;
			h[x].value = v;
		} else {
			// If the prefecture x already exists in the cMap, append a new city struct to the existing cities slice.
			cities v = h[x].value;
			city ci;
			ci.prefecture = x;
			ci.year = y;
			ci.position = i;
			v[h[x].key] = ci;
		}
	}

	// Initialize a slice named results with length m and zeroed elements.
	char* results[100000];
	for (int i = 0; i < m; i++) {
		results[i] = malloc(sizeof(char) * 100000);
		memset(results[i], 0, sizeof(char) * 100000);
	}

	// Iterate through each value v in the cMap.
	for (int i = 0; i < n; i++) {
		// Sort the cities slice v using the Less method.
		city* v = h[i].value;
		for (int j = 0; j < h[i].key; j++) {
			for (int k = 0; k < h[i].key; k++) {
				if (v[j].year > v[k].year) {
					city ci = v[j];
					v[j] = v[k];
					v[k] = ci;
				}
			}
		}

		// Iterate through each city struct ci in the sorted cities slice v.
		for (int j = 0; j < h[i].key; j++) {
			// Format the result string using sprintf and assign it to the corresponding index in the results slice.
			sprintf(results[v[j].position], "%06d%06d", v[j].prefecture, j + 1);
		}
	}

	// Print the final result using strings.Join and printf.
	for (int i = 0; i < m; i++) {
		printf("%s\n", results[i]);
	}

	return 0;
}

// End of code

