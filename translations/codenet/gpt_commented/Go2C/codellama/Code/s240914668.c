#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	// Set the scanner to split input by whitespace
	char *token;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	// Read the number of integers
	int n = 0;
	read = getline(&line, &len, stdin);
	token = strtok(line, " ");
	n = atoi(token);

	// Read the integers into a slice
	int *a = (int *)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		read = getline(&line, &len, stdin);
		token = strtok(line, " ");
		a[i] = atoi(token);
	}

	// Initialize the answer counter
	int ans = 0;

	// Iterate through the slice of integers
	for (int i = 0; i < n; i++) {
		// Set the left and right pointers for the current segment
		int l = i, r = i + 1;

		// Expand the right pointer while the conditions are met
		while (r + 1 < n && (a[r] - a[l]) * (a[r + 1] - a[r]) >= 0) {
			r++;
		}

		// Increment the answer for each segment found
		ans++;
		// Move the left pointer to the end of the current segment
		i = r;
	}

	// Output the final count of segments
	printf("%d\n", ans);

	// Flush the buffered writer to ensure all output is written
	fflush(stdout);

	// Free the allocated memory
	free(a);
	free(line);

	return 0;
}

