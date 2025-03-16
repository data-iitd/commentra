#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define MAXN 200000
#define MAXM 200000
#define MAXP 1000000007

int N;
int p[MAXN];

int find(int n) {
	for (int i = 0; i < N; i++) {
		if (n == p[i]) {
			return 0;
		}
	}
	return 1;
}

int main() {
	int X;
	scanf("%d", &X);
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &p[i]);
	}

	for (int i = 0; i <= 100; i++) {
		if (find(X - i) == 1) {
			printf("%d\n", X - i);
			return 0;
		}
		if (find(X + i) == 1) {
			printf("%d\n", X + i);
			return 0;
		}
	}
	return 0;
}

