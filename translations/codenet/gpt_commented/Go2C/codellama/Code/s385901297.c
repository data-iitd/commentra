#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	// Create a new scanner to read input from standard input (stdin)
	char line[100];
	int ns[4];

	// Read a line of input and parse it into the slice
	fgets(line, 100, stdin);
	sscanf(line, "%d %d %d %d", &ns[0], &ns[1], &ns[2], &ns[3]);

	// Sort the slice of integers in ascending order
	qsort(ns, 4, sizeof(int), compare);

	// Check if the sorted integers match the specific sequence [1, 4, 7, 9]
	if (ns[0] == 1 && ns[1] == 4 && ns[2] == 7 && ns[3] == 9) {
		// If they match, print "YES"
		printf("YES\n");
	} else {
		// If they do not match, print "NO"
		printf("NO\n");
	}

	return 0;
}

int compare(const void *a, const void *b) {
	return (*(int *)a - *(int *)b);
}

