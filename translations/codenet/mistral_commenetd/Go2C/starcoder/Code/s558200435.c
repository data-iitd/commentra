
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <math.h>

#define MAX(x, y) (((x) > (y))? (x) : (y))
#define MIN(x, y) (((x) < (y))? (x) : (y))

int main() {
	// Read the number of elements in the array 'a'
	int n;
	scanf("%d", &n);

	// Create a slice 'a' of length 'n' to store the input elements
	int *a = (int *) malloc(n * sizeof(int));

	// Read 'n' elements from the standard input and store them in slice 'a'
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	// Initialize an empty slice 'b' to store the unique elements
	int *b = (int *) malloc(n * sizeof(int));

	// Iterate through each element 'v' in slice 'a'
	for (int i = 0; i < n; i++) {
		// Use'sort.Search' function to find the index 'x' where 'v' should be inserted in slice 'b'
		int x = sort_search(b, n, a[i]);

		// If 'x' is equal to the length of slice 'b', it means 'v' is not present in the slice, so append it
		if (x == n) {
			b = (int *) realloc(b, (n + 1) * sizeof(int));
			b[n] = a[i];
			n++;
		} else {
			// Otherwise, replace the element at index 'x' in slice 'b' with 'v'
			b[x] = a[i];
		}
	}

	// Print the length of slice 'b' as the output
	printf("%d\n", n);

	// End of the code
}

int sort_search(int *b, int n, int v) {
	// Initialize the variable 'x' to store the index where 'v' should be inserted in slice 'b'
	int x = 0;

	// Iterate through each element 'u' in slice 'b'
	for (int i = 0; i < n; i++) {
		// If 'u' is greater than 'v', then 'v' should be inserted before 'u' in slice 'b'
		if (b[i] > v) {
			break;
		}

		// Otherwise, 'v' should be inserted after 'u' in slice 'b'
		x++;
	}

	// Return the index 'x' where 'v' should be inserted in slice 'b'
	return x;
}

