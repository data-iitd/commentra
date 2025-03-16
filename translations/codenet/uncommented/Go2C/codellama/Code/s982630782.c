#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int N, M;
	int *ints;
	int *m;
	int i, j, k;
	int sum;
	int rest;
	int num;
	int B, C;

	scanf("%d %d", &N, &M);
	ints = (int *)malloc(sizeof(int) * N);
	m = (int *)malloc(sizeof(int) * N);
	for (i = 0; i < N; i++) {
		scanf("%d", &ints[i]);
		m[ints[i]]++;
	}
	for (i = 0; i < M; i++) {
		scanf("%d %d", &B, &C);
		m[C] += B;
	}
	for (i = 0; i < N; i++) {
		ints[i] = m[ints[i]];
	}
	qsort(ints, N, sizeof(int), cmp);
	rest = N;
	sum = 0;
	for (i = 0; i < N; i++) {
		num = ints[i];
		if (num >= rest) {
			sum += rest * ints[i];
			break;
		}
		sum += num * ints[i];
		rest -= num;
	}
	printf("%d\n", sum);
	free(ints);
	free(m);
	return 0;
}

int cmp(const void *a, const void *b) {
	return *(int *)b - *(int *)a;
}

