
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a custom data structure
typedef struct {
	int n, m; // dimensions of the images
	char **nImg, **mImg; // image data as strings
} data;

// Initialize a new data object
data newData() {
	// Read dimensions from user input
	int n, m;
	scanf("%d %d", &n, &m);
	// Load image data as strings
	char **nImg = load(n);
	char **mImg = load(m);

	// Initialize data object with loaded data
	data d = {n, m, nImg, mImg};
	return d;
}

// Load image data as strings
char **load(int cnt) {
	// Allocate memory for image data
	char **ret = (char **)malloc(cnt * sizeof(char *));
	for (int i = 0; i < cnt; i++) {
		ret[i] = (char *)malloc(cnt * sizeof(char));
	}
	// Read image data from user input
	for (int i = 0; i < cnt; i++) {
		scanf("%s", ret[i]);
	}

	// Return loaded image data
	return ret;
}

// Check if data already exists in the larger image
int exist(data d) {
	// Iterate through all possible positions in larger image
	for (int i = 0; i <= d.n - d.m; i++) {
		for (int j = 0; j <= d.n - d.m; j++) {
			// Check if current position matches the smaller image
			if (match(d, i, j)) {
				// If match is found, return true
				return 1;
			}
		}
	}

	// If no match is found, return false
	return 0;
}

// Check if smaller image matches at current position in larger image
int match(data d, int x, int y) {
	// Iterate through each pixel in smaller image
	for (int i = 0; i < d.m; i++) {
		for (int j = 0; j < d.m; j++) {
			// Check if corresponding pixel in larger image matches
			if (d.nImg[x + i][y + j] != d.mImg[i][j]) {
				// If mismatch is found, return false
				return 0;
			}
		}
	}

	// If all pixels match, return true
	return 1;
}

int main() {
	// Initialize a new data object
	data d = newData();
	// Check if data already exists
	if (exist(d)) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
	return 0;
}

