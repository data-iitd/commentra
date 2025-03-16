#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// Util. ----------

int abs(int x) {
	return x < 0? -x : x;
}

int min(int x, int y) {
	return x < y? x : y;
}

int max(int x, int y) {
	return x > y? x : y;
}

// ---------- Util.

int main() {
	int A, B, Q, s[100000], t[100000];
	scanf("%d %d %d", &A, &B, &Q);
	s[0] = -1000000000;
	s[A+1] = 1000000000;
	for (int i = 1; i <= A; i++) {
		scanf("%d", &s[i]);
	}
	t[0] = -1000000000;
	t[B+1] = 1000000000;
	for (int i = 1; i <= B; i++) {
		scanf("%d", &t[i]);
	}
	for (int i = 0; i < Q; i++) {
		int x;
		scanf("%d", &x);
		int b = 0, d = 0;
		while (s[b+1] < x) {
			b++;
		}
		while (t[d+1] < x) {
			d++;
		}
		int res = 1000000000;
		for (int S = s[b-1]; S <= s[b]; S++) {
			for (int T = t[d-1]; T <= t[d]; T++) {
				int d1 = abs(S-x) + abs(T-S);
				int d2 = abs(T-x) + abs(S-T);
				res = min(res, min(d1, d2));
			}
		}
		printf("%d\n", res);
	}
}

