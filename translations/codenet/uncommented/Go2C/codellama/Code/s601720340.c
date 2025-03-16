
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define magic 1000000007

int main() {
	int N;
	int p[200000];

	int find(int n) {
		for (int i = 0; i < N; i++) {
			if (n == p[i]) {
				return 0;
			}
		}
		return 1;
	}

	int X = 0;
	int N = 0;
	scanf("%d", &X);
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &p[i]);
	}

	for (int i = 0; i <= 100; i++) {
		if (find(X - i) == 1) {
			printf("%d\n", X - i);
			exit(0);
		}
		if (find(X + i) == 1) {
			printf("%d\n", X + i);
			exit(0);
		}
	}

	return 0;
}

