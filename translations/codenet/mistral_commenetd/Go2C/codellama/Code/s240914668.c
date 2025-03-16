
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Package main is the entry point of the program
int main() {
	// Initialize scanner, reader, and writer
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	int n;
	int *a;

	// Read the number of elements in the array 'a'
	read = getline(&line, &len, stdin);
	n = atoi(line);

	// Allocate memory for the array 'a'
	a = (int *)malloc(n * sizeof(int));

	// Read the elements of the array 'a'
	for (int i = 0; i < n; i++) {
		read = getline(&line, &len, stdin);
		a[i] = atoi(line);
	}

	// Initialize answer variable
	int ans = 0;

	// Iterate through the array 'a'
	for (int i = 0; i < n; i++) {
		// Initialize left and right indices
		int l = i;
		int r = i + 1;

		// Use a while loop to find the next index 'r' such that the difference between 'a[r]' and 'a[l]' is negative
		while (r+1 < n && (a[r]-a[l])*(a[r+1]-a[r]) >= 0) {
			r++;
		}

		// Increment the answer variable
		ans++;

		// Update the index 'i' to 'r' for the next iteration
		i = r;
	}

	// Print the answer
	printf("%d\n", ans);

	// Free memory
	free(a);
	free(line);

	return 0;
}

