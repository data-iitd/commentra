#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	int n;
	scanf("%d", &n);

	int *arrA = (int *)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arrA[i]);
	}

	int *cumSumA = (int *)malloc(sizeof(int) * (n + 1));
	cumSumA[0] = 0;
	for (int i = 0; i < n; i++) {
		cumSumA[i + 1] = cumSumA[i] + arrA[i];
	}

	double ans = 10000000000.0;
	for (int i = 1; i < n; i++) {
		if (fabs(cumSumA[n] - (cumSumA[i] * 2)) < ans) {
			ans = fabs(cumSumA[n] - (cumSumA[i] * 2));
		}
	}

	printf("%d\n", (int)ans);
}

