#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
	int n, t, a;
	double minDiff, diff;
	int minIdx;
	double *heights;

	scanf("%d %d %d", &n, &t, &a);
	heights = (double *)malloc(sizeof(double) * n);
	for (int i = 0; i < n; i++) {
		scanf("%lf", &heights[i]);
	}

	minDiff = fabs(t - heights[0] * 0.006 - a);
	minIdx = 0;
	for (int i = 1; i < n; i++) {
		diff = fabs(t - heights[i] * 0.006 - a);
		if (diff < minDiff) {
			minDiff = diff;
			minIdx = i;
		}
	}
	printf("%d\n", minIdx + 1);
	free(heights);
	return 0;
}
