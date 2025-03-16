#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ri() {
	int n = 0;
	char c;
	while ((c = getchar()) != '\n') {
		n = n*10 + c-48;
	}
	return n;
}

double ave(double *s, int n) {
	double sum = 0;
	for (int i = 0; i < n; i++) {
		sum += s[i];
	}
	return sum / n;
}

double diff(double a, double b) {
	if (a > b) {
		return a - b;
	}
	return b - a;
}

int main() {
	int n = ri();
	double *a = (double *)malloc(sizeof(double) * n);
	for (int i = 0; i < n; i++) {
		a[i] = ri();
	}
	// printf("%f\n", a[0]);

	double ave = ave(a, n);

	double minDiff = 999999.9;
	int ansIndex = -1;
	for (int i = 0; i < n; i++) {
		double diff = diff(a[i], ave);
		if (diff < minDiff) {
			minDiff = diff;
			ansIndex = i;
		}
	}
	printf("%d\n", ansIndex);
	return 0;
}

