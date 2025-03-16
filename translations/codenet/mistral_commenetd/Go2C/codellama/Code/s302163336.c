
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initialize scanner
char *sc = NULL;

// Function to read the next integer from the standard input
int nextInt() {
	// Read an integer from the standard input and convert it to an integer
	char *p = strtok(sc, " ");
	if (p == NULL) {
		// If there is an error, panic with the error message
		panic("Error reading from standard input");
	}
	int i = atoi(p);
	sc = NULL;
	return i;
}

// Function to panic with the given error message
void panic(char *msg) {
	printf("%s\n", msg);
	exit(1);
}

int main() {
	// Read the number of elements n and m from the standard input
	int n = nextInt();
	int m = nextInt();

	// Initialize h array with n elements and good array with n boolean values
	int *h = (int *)malloc(n * sizeof(int));
	int *good = (int *)malloc(n * sizeof(int));

	// Read n integers from the standard input and initialize h and good arrays
	for (int i = 0; i < n; i++) {
		h[i] = nextInt();
		// Set good[i] to true initially
		good[i] = 1;
	}

	// Process m queries
	for (int i = 0; i < m; i++) {
		// Read two integers ai and bi from the standard input
		int ai = nextInt() - 1;
		int bi = nextInt() - 1;

		// Compare the heights of h[ai] and h[bi]
		if (h[ai] > h[bi]) {
			// If h[ai] is greater than h[bi], mark good[bi] as false
			good[bi] = 0;
		} else if (h[ai] < h[bi]) {
			// If h[ai] is less than h[bi], mark good[ai] as false
			good[ai] = 0;
		} else {
			// If heights are equal, mark both good[ai] and good[bi] as false
			good[ai] = 0;
			good[bi] = 0;
		}
	}

	// Initialize answer variable ans to 0
	int ans = 0;

	// Count the number of good elements in the h array
	for (int i = 0; i < n; i++) {
		if (good[i]) {
			// Increment ans if good[i] is true
			ans++;
		}
	}

	// Print the answer
	printf("%d\n", ans);

	// Free the memory allocated for h and good arrays
	free(h);
	free(good);

	return 0;
}

