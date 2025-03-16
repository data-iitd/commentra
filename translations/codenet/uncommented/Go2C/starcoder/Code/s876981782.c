#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
	int N;
	scanf("%d", &N);
	float values[N];
	for (int i = 0; i < N; i++) {
		scanf("%f", &values[i]);
	}

	qsort(values, N, sizeof(float), compare);
	float generated = 0;
	for (int i = 0; i < N-1; i++) {
		generated = (values[i] + values[i+1]) / 2;
		values[i+1] = generated;
	}

	printf("%f", generated);
}

