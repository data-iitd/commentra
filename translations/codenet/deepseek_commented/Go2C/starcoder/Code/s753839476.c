#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Main function: Reads input values, calculates the minimum difference, and prints the index.
int main() {
	int n, minIdx;
	double t, a, minDiff;
	scanf("%d %lf %lf", &n, &t, &a);
	double heights[n];
	for (int i = 0; i < n; i++) {
		scanf("%lf", &heights[i]);
	}
	minDiff = fabs(t - heights[0] * 0.006 - a);
	minIdx = 0;
	for (int i = 1; i < n; i++) {
		double diff = fabs(t - heights[i] * 0.006 - a);
		if (diff < minDiff) {
			minDiff = diff;
			minIdx = i;
		}
	}
	printf("%d\n", minIdx + 1);
}

