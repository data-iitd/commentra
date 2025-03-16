#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int N;
	scanf("%d", &N); // Read the number of values
	float *values = (float *) malloc(N * sizeof(float));
	for (int i = 0; i < N; i++) {
		scanf("%f", &values[i]); // Read the values into the slice
	}

	qsort(values, N, sizeof(float), compare); // Sort the values in ascending order
	float generated;
	//printf("%f", values); // Uncomment to print the sorted values (for debugging purposes)
	for (int i = 0; i < N-1; i++) {
		generated = (values[i] + values[i+1]) / 2; // Calculate the average of the current and next value
		values[i+1] = generated; // Update the next value with the calculated average
	}

	printf("%f", generated); // Print the final generated value
	return 0;
}

float compare(const void *a, const void *b) {
	return *(float *) a - *(float *) b;
}

