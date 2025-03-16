#include <stdio.h>
#include <stdlib.h>

int main() {
	int in[3];
	int i;
	int result;

	// Read three integers from standard input
	for (i = 0; i < 3; i++) {
		scanf("%d", &in[i]);
	}

	// Sort the integers in ascending order
	qsort(in, 3, sizeof(int), compare);

	// Calculate the result based on the sorted integers
	// The result is computed as: (largest number * 10) + (second largest number) + (smallest number)
	result = in[2] * 10 + in[1] + in[0];

	// Print the result
	printf("%d\n", result);

	return 0;
}

int compare(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}

