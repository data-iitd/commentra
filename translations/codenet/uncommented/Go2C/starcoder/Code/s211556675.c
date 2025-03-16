#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

#define MAX(a, b) ((a) > (b)? (a) : (b))
#define MIN(a, b) ((a) < (b)? (a) : (b))
#define ABS(x) ((x) > 0? (x) : -(x))
#define POW(x, y) ((int)pow((double)(x), (double)(y)))

typedef struct {
	int id, num;
} Val;

int main() {
	int A, B, C, K;
	scanf("%d %d %d %d", &A, &B, &C, &K);
	int ma = MAX(A, B, C);
	int rest = 0;
	if (ma == A) {
		rest += B + C;
	} else if (ma == B) {
		rest += A + C;
	} else {
		rest += A + B;
	}
	for (int i = 1; i <= K; i++) {
		ma *= 2;
	}
	printf("%d\n", ma + rest);
	return 0;
}

