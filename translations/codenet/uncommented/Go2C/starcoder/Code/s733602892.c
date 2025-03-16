#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <math.h>

#define REP(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int N, K;
	scanf("%d %d", &N, &K);
	int *As = malloc(sizeof(int) * N);
	int *Fs = malloc(sizeof(int) * N);
	REP(i, N) {
		scanf("%d", &As[i]);
	}
	REP(i, N) {
		scanf("%d", &Fs[i]);
	}

	qsort(As, N, sizeof(int), cmp);
	qsort(Fs, N, sizeof(int), cmp);

	int *scores = malloc(sizeof(int) * N);
	REP(i, N) {
		scores[i] = As[i] * Fs[i];
	}
	qsort(scores, N, sizeof(int), cmp);

	int ok = scores[0];
	int ng = -1;
	while (ok - ng > 1) {
		int mid = (ok + ng) / 2;

		bool isOK = true;
		int k = K;
		REP(i, N) {
			if (As[i] * Fs[i] > mid) {
				k -= As[i] - mid / Fs[i];
			}
			if (k < 0) {
				isOK = false;
				break;
			}
		}

		if (isOK) {
			ok = mid;
		} else {
			ng = mid;
		}
	}
	printf("%d\n", ok);
}

int cmp(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}

