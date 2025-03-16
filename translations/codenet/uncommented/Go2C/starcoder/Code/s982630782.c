#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	int *a = malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	int *b = malloc(sizeof(int) * M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &b[i]);
	}
	int *c = malloc(sizeof(int) * M);
	for (int i = 0; i < M; i++) {
		c[i] = b[i];
	}
	qsort(c, M, sizeof(int), cmp);
	int sum = 0;
	int rest = N;
	for (int i = 0; i < M; i++) {
		int num = 0;
		for (int j = 0; j < N; j++) {
			if (a[j] == c[i]) {
				num++;
			}
		}
		if (num >= rest) {
			sum += rest * c[i];
			break;
		}
		sum += num * c[i];
		rest -= num;
	}
	printf("%d\n", sum);
	return 0;
}

int cmp(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}

