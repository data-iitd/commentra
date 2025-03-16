#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>
#include <assert.h>

#define MAX_N 100000

typedef struct {
	int64_t t, a;
} T;

int64_t max(int64_t x, int64_t y) {
	if (x > y) {
		return x;
	}
	return y;
}

int64_t min(int64_t x, int64_t y) {
	if (x < y) {
		return x;
	}
	return y;
}

int64_t divUp(int64_t x, int64_t y) {
	return (x + y - 1) / y;
}

int64_t solve(int64_t N, T* T, T* A) {
	int64_t t = T[0].t, a = A[0].a;
	for (int64_t i = 1; i < N; i++) {
		int64_t r = max(divUp(t, T[i].t), divUp(a, A[i].a));
		t = T[i].t * r;
		a = A[i].a * r;
	}
	return t + a;
}

int main() {
	int64_t N;
	scanf("%" PRId64, &N);
	T T[MAX_N], A[MAX_N];
	for (int64_t i = 0; i < N; i++) {
		scanf("%" PRId64 " %" PRId64, &T[i].t, &A[i].a);
	}
	int64_t ans = solve(N, T, A);
	printf("%" PRId64 "\n", ans);
	return 0;
}

