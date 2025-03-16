#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define INF 1000000000

int main() {
	int A, B, Q, i, j, x, b, d, res;
	int *s, *t;

	scanf("%d %d %d", &A, &B, &Q);
	s = (int *)malloc((A + 2) * sizeof(int));
	t = (int *)malloc((B + 2) * sizeof(int));
	for (i = 1; i <= A; i++) {
		scanf("%d", &s[i]);
	}
	for (i = 1; i <= B; i++) {
		scanf("%d", &t[i]);
	}
	s[0] = -INF;
	s[A + 1] = INF;
	t[0] = -INF;
	t[B + 1] = INF;

	for (i = 0; i < Q; i++) {
		scanf("%d", &x);
		b = -1;
		d = -1;
		for (j = 1; j <= A; j++) {
			if (s[j] >= x) {
				b = j;
				break;
			}
		}
		for (j = 1; j <= B; j++) {
			if (t[j] >= x) {
				d = j;
				break;
			}
		}
		res = INF;
		for (j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				int d1 = abs(s[b - j] - x) + abs(t[d - k] - s[b - j]);
				int d2 = abs(t[d - k] - x) + abs(s[b - j] - t[d - k]);
				res = min(res, min(d1, d2));
			}
		}
		printf("%d\n", res);
	}
	free(s);
	free(t);
	return 0;
}

