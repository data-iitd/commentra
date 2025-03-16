#include <stdio.h>
#include <stdlib.h>

#define N 114514

int main(void) {
	int inorinn, emirinn = 0;
	int A[N], tomatu[N], mikakosi[N];
	int yukinnko = 1;
	for (inorinn = 0; inorinn < N; inorinn++) {
		scanf("%d", &A[inorinn]);
		tomatu[inorinn] = A[inorinn];
	}
	qsort(tomatu, N, sizeof(*tomatu), cmp);
	for (inorinn = 1; inorinn < N; inorinn++) {
		if (tomatu[inorinn]!= tomatu[yukinnko - 1]) {
			tomatu[yukinnko++] = tomatu[inorinn];
		}
	}
	for (inorinn = 0; inorinn < N; inorinn++) {
		int kugyu = sumipe(A[inorinn]);
		mikakosi[kugyu] =!mikakosi[kugyu];
	}
	for (inorinn = 0; inorinn < yukinnko; inorinn++) {
		if (mikakosi[inorinn]) emirinn++;
	}
	printf("%d\n", emirinn);
	return 0;
}

def cmp(a, b):
	return a < b

def sumipe(hayaminn):
	satorina = 0
	zaasan = yukinnko - 1
	while satorina <= zaasan:
		yukati = satorina + (zaasan - satorina) / 2
		if tomatu[yukati] == hayaminn:
			return yukati
		elif tomatu[yukati] < hayaminn:
			satorina = yukati + 1
		else:
			zaasan = yukati - 1
	return 114513

