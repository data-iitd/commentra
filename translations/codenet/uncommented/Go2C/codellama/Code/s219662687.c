#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main() {
	int INF = pow(10, 11);
	int A = 0, B = 0, Q = 0;
	int x = 0;
	int b = 0, d = 0;
	int res = 0;
	int S = 0, T = 0;
	int d1 = 0, d2 = 0;
	int i = 0;
	int *s = NULL;
	int *t = NULL;

	scanf("%d", &A);
	s = (int *)malloc((A + 2) * sizeof(int));
	s[0] = -INF;
	s[A + 1] = INF;
	for (i = 1; i <= A; i++) {
		scanf("%d", &s[i]);
	}

	scanf("%d", &B);
	t = (int *)malloc((B + 2) * sizeof(int));
	t[0] = -INF;
	t[B + 1] = INF;
	for (i = 1; i <= B; i++) {
		scanf("%d", &t[i]);
	}

	scanf("%d", &Q);
	for (i = 0; i < Q; i++) {
		scanf("%d", &x);
		b = 0;
		d = 0;
		res = INF;
		for (i = 0; i < A + 2; i++) {
			if (s[i] == x) {
				b = i;
				break;
			}
		}
		for (i = 0; i < B + 2; i++) {
			if (t[i] == x) {
				d = i;
				break;
			}
		}
		for (i = 0; i < 2; i++) {
			S = s[b - 1 + i];
			for (i = 0; i < 2; i++) {
				T = t[d - 1 + i];
				d1 = abs(S - x) + abs(T - S);
				d2 = abs(T - x) + abs(S - T);
				res = min(res, min(d1, d2));
			}
		}
		printf("%d\n", res);
	}

	free(s);
	free(t);
	return 0;
}

// 