


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	// Declare variables for the number of elements (n) and the number of comparisons (m)
	int n, m;
	
	// Read the values of n and m from standard input
	scanf("%d %d", &n, &m);
	
	// Create a slice to hold the heights of n elements
	int *h = (int *) malloc(n * sizeof(int));
	
	// Read the heights of the n elements from standard input
	for (int i = 0; i < n; i++) {
		scanf("%d", &h[i]);
	}
	
	// Declare variables for the two elements to compare (a and b)
	int a, b;
	
	// Create a map to keep track of unique elements that are involved in comparisons
	int *counter = (int *) malloc(n * sizeof(int));
	memset(counter, 0, n * sizeof(int));
	
	// Loop through m comparisons
	for (int i = 0; i < m; i++) {
		// Read the indices of the two elements to compare
		scanf("%d %d", &a, &b);
		
		// Compare the heights of the two elements
		if (h[a-1] < h[b-1]) {
			// If height of a is less than height of b, add a to the counter
			counter[a-1] = 1;
		} else if (h[a-1] > h[b-1]) {
			// If height of a is greater than height of b, add b to the counter
			counter[b-1] = 1;
		} else if (h[a-1] == h[b-1]) {
			// If heights are equal, add both a and b to the counter
			counter[a-1] = 1;
			counter[b-1] = 1;
		}
	}
	
	// Print the number of elements that were not involved in any comparisons
	printf("%d\n", n - (int) strchr(counter, 1));
}


Translate the above C code to Python.

import sys

# Declare variables for the number of elements (n) and the number of comparisons (m)
n, m = map(int, sys.stdin.readline().split())

# Create a slice to hold the heights of n elements
h = [0] * n

# Read the heights of the n elements from standard input
for i in range(n):
    h[i] = int(sys.stdin.readline())

# Declare variables for the two elements to compare (a and b)
a, b = 0, 0

# Create a map to keep track of unique elements that are involved in comparisons
counter = [0] * n

# Loop through m comparisons
for i in range(m):
    # Read the indices of the two elements to compare
    a, b = map(int, sys.stdin.readline().split())
    
    # Compare the heights of the two elements
    if h[a-1] < h[b-1]:
        # If height of a is less than height of b, add a to the counter
        counter[a-1] = 1
    elif h[a-1] > h[b-1]:
        # If height of a is greater than height of b, add b to the counter
        counter[b-1] = 1
    elif h[a-1] == h[b-1]:
        # If heights are equal, add both a and b to the counter
        counter[a-1] = 1
        counter[b-1] = 1

# Print the number of elements that were not involved in any comparisons
print(n - counter.count(1))
