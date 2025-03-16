#include <stdio.h>

int main() {
	
	// Declare variables
	int n, i, j, q, x[10000], y[500], sum = 0;
	
	// Read the number of elements in array x
	scanf("%d", &n);
	
	// Read n elements into array x
	for( i = 0; i < n; i++) {
		scanf("%d", &x[i]);
	}
	
	// Read the number of queries
	scanf("%d", &q);
	
	// Read q elements into array y
	for( i = 0; i < q; i++) {
		scanf("%d", &y[i]);
	}
	
	// Initialize sum to count how many elements in y are found in x
	for( i = 0; i < q; i++) {
		// Check each element in y against all elements in x
		for( j = 0; j < n; j++) {
			// If a match is found, increment sum and break the inner loop
			if( y[i] == x[j]) {
				sum = sum + 1;
				break;
			}
		}
	}
	
	// Output the total count of matches found
	printf("%d\n", sum);
	
	return 0;
}
