#include <stdio.h>
#include <stdlib.h>

int main() {
	// Declare variables for the number of elements (n) and the number of comparisons (m)
	int n, m;
	
	// Read the values of n and m from standard input
	scanf("%d %d", &n, &m);
	
	// Create a slice to hold the heights of n elements
	int *h = (int *)malloc(n * sizeof(int));
	
	// Read the heights of the n elements from standard input
	for (int i = 0; i < n; i++) {
		scanf("%d", &h[i]);
	}
	
	// Declare variables for the two elements to compare (a and b)
	int a, b;
	
	// Create a map to keep track of unique elements that are involved in comparisons
	int *counter = (int *)malloc(n * sizeof(int));
	
	// Loop through m comparisons
	for (int i = 0; i < m; i++) {
		// Read the indices of the two elements to compare
		scanf("%d %d", &a, &b);
		
		// Compare the heights of the two elements
		if (h[a-1] < h[b-1]) {
			// If height of a is less than height of b, add a to the counter
			counter[a] = 1;
		} else if (h[a-1] > h[b-1]) {
			// If height of a is greater than height of b, add b to the counter
			counter[b] = 1;
		} else if (h[a-1] == h[b-1]) {
			// If heights are equal, add both a and b to the counter
			counter[a] = 1;
			counter[b] = 1;
		}
	}
	
	// Print the number of elements that were not involved in any comparisons
	printf("%d\n", n - (int)counter);
	
	// Free the memory allocated for the slice and the map
	free(h);
	free(counter);
	
	return 0;
}

