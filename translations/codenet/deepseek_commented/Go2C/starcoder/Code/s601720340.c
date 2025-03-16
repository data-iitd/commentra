
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define MAX_N 200000
#define MAX_M 100
#define MAX_P 1000000007

int magic = 1000000007;

int N;
int p[MAX_N];

int find(int n) {
	for (int i = 0; i < N; i++) {
		if (n == p[i]) {
			return 0;
		}
	}
	return 1;
}

void solve() {
	int X;
	scanf("%d", &X);
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &p[i]);
	}

	for (int i = 0; i <= 100; i++) {
		if (find(X - i) == 1) {
			printf("%d\n", X - i);
			return;
		}
		if (find(X + i) == 1) {
			printf("%d\n", X + i);
			return;
		}
	}
}

int main() {
	solve();
	return 0;
}

