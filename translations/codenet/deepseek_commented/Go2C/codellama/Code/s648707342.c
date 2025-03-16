#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Reads a single integer from standard input.
int scanInt() {
	int iv;
	scanf("%d", &iv);
	return iv;
}

// Initializes the scanner to split input by words.
void init() {
	setbuf(stdin, NULL);
}

// Defines a struct to represent an arm with left and right endpoints.
typedef struct {
	int l;
	int r;
} arm;

int main() {
	// Reads the number of arms.
	int n = scanInt();
	
	// Creates a slice to store the arms.
	arm *as = (arm *)malloc(n * sizeof(arm));
	
	// Reads each arm's range and stores the left and right endpoints.
	for (int i = 0; i < n; i++) {
		int x = scanInt();
		int l = scanInt();
		as[i].l = x - l;
		as[i].r = x + l;
	}
	
	// Sorts the arms based on their right endpoints.
	qsort(as, n, sizeof(arm), compare);
	
	// Initializes the answer and the right endpoint reference.
	int ans = 1;
	int r = as[0].r;
	
	// Iterates through the sorted arms to count non-overlapping arms.
	for (int i = 1; i < n; i++) {
		if (as[i].l >= r) {
			ans++;
			r = as[i].r;
		}
	}
	
	// Prints the count of non-overlapping arms.
	printf("%d\n", ans);
	
	// Frees the memory allocated for the arms.
	free(as);
	
	return 0;
}

// Compares two arms based on their right endpoints.
int compare(const void *a, const void *b) {
	return ((arm *)a)->r - ((arm *)b)->r;
}

