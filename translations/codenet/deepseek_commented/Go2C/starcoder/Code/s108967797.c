#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;
	scanf("%d", &n);
	float a[n];
	for (int i = 0; i < n; i++) {
		scanf("%f", &a[i]);
	}
	float ave = 0.0;
	for (int i = 0; i < n; i++) {
		ave += a[i];
	}
	ave /= n;
	float minDiff = 999999.9;
	int ansIndex = -1;
	for (int i = 0; i < n; i++) {
		float diff = fabs(a[i] - ave);
		if (diff < minDiff) {
			minDiff = diff;
			ansIndex = i;
		}
	}
	printf("%d", ansIndex);
	return 0;
}
