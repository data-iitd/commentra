#include <stdio.h>
#include <math.h>
#include <limits.h>

#define INF INT_MAX

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

	double ans = INF;
	for (int i = 1; i < n; i++) {
		double temp = fabs((double)(cumSumA[n] - (cumSumA[i] * 2)));
		if (temp < ans) {
			ans = temp;
		}
	}

	printf("%d\n", (int)ans);
	return 0;
}
