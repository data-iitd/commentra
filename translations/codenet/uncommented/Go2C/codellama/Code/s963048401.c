#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define mod 1000000007

int intScanner() {
	int n;
	scanf("%d", &n);
	return n;
}

float floatScanner() {
	float n;
	scanf("%f", &n);
	return n;
}

int stringToInt(char *s) {
	int n;
	n = atoi(s);
	return n;
}

int main() {
	int n = intScanner();
	int *as = (int *)malloc(sizeof(int) * n);
	int *xs = (int *)malloc(sizeof(int) * n);
	int i, j;
	for (i = 0; i < n; i++) {
		as[i] = intScanner();
	}
	xs[0] = as[0];
	for (j = 1; j < n; j++) {
		int idx = 0;
		for (i = 0; i < j; i++) {
			if (xs[i] < as[j]) {
				idx++;
			}
		}
		if (idx == j) {
			xs[j] = as[j];
		} else {
			xs[idx] = as[j];
		}
	}
	printf("%d\n", j);
	return 0;
}

