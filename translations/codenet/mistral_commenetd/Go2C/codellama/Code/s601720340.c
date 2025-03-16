
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define magic 1000000007

int find(int n, int p[], int N) {
	for (int i = 0; i < N; i++) {
		if (n == p[i]) {
			return 0;
		}
	}
	return 1;
}

int main() {
	int X, N;
	int p[200000];

	scanf("%d", &X);
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &p[i]);
	}

	for (int i = 0; i <= 100; i++) {
		if (find(X-i, p, N) == 1) {
			printf("%d\n", X-i);
			return 0;
		}
		if (find(X+i, p, N) == 1) {
			printf("%d\n", X+i);
			return 0;
		}
	}

	// OUTPUT GENERATION PART
	int ans = 0;
	printf("%d\n", ans);

	// If ans > 0, print "Yes" and exit; otherwise, print "No"
	if (ans > 0) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}

	return 0;
}

