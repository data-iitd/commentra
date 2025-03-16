#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int N;
	scanf("%d", &N);
	float *values = (float *)malloc(N * sizeof(float));
	for (int i = 0; i < N; i++) {
		scanf("%f", &values[i]);
	}

	qsort(values, N, sizeof(float), compare);
	float generated = 0;
	//printf("%f\n", values[0]);
	for (int i = 0; i < N-1; i++) {
		generated = (values[i] + values[i+1]) / 2;
		values[i+1] = generated;
	}

	printf("%f\n", generated);
	free(values);
	return 0;
}

int compare(const void *a, const void *b) {
	return (*(float *)a - *(float *)b);
}

