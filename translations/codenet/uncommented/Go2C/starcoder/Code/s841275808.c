#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main() {
	int N;
	scanf("%d", &N);
	int X[N];
	int Y[N];
	for (int i = 0; i < N; i++) {
		scanf("%d", &X[i]);
		Y[i] = X[i];
	}
	qsort(Y, N, sizeof(int), compare);
	int m1 = Y[N / 2 - 1];
	int m2 = Y[N / 2];
	for (int i = 0; i < N; i++) {
		if (X[i] <= m1) {
			printf("%d\n", m2);
		} else {
			printf("%d\n", m1);
		}
	}
}

int compare(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}

