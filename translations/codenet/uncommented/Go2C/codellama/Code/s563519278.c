#include <stdio.h>
#include <stdlib.h>

int main() {
	int N;
	scanf("%d", &N);
	int *v = (int *)malloc(N * sizeof(int));
	int a;

	for (int i = 1; i < N; i++) {
		scanf("%d", &a);
		v[a - 1]++;
	}

	for (int i = 0; i < N; i++) {
		printf("%d\n", v[i]);
	}

	free(v);
	return 0;
}

