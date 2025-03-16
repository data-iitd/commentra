#include <stdio.h>
#include <math.h>

#define inf 10000000000.0

int main() {
	int n;
	scanf("%d", &n);

	int arrA[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &arrA[i]);
	}

	int cumSumA[n+1];
	cumSumA[0] = 0;
	for (int i = 0; i < n; i++) {
		cumSumA[i+1] = cumSumA[i] + arrA[i];
	}

	double ans = inf;
	for (int i = 1; i < n; i++) {
		if (fabs(cumSumA[n]-(cumSumA[i]*2)) < ans) {
			ans = fabs(cumSumA[n] - cumSumA[i]*2);
		}
	}

	printf("%d\n", (int)ans);

	return 0;
}

