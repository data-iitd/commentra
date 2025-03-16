#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
	int N;
	int *X, *Y;
	int i, j, m1, m2;
	
	scanf("%d", &N);
	X = (int *)malloc(N * sizeof(int));
	Y = (int *)malloc(N * sizeof(int));
	for (i = 0; i < N; i++) {
	    scanf("%d", &X[i]);
	    Y[i] = X[i];
	}
	
	qsort(Y, N, sizeof(int), cmp);
	m1 = Y[N / 2 - 1];
	m2 = Y[N / 2];
	for (i = 0; i < N; i++) {
	    if (X[i] <= m1) {
	        printf("%d\n", m2);
	    } else {
	        printf("%d\n", m1);
	    }
	}
	
	free(X);
	free(Y);
	
	return 0;
}

int cmp(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}

