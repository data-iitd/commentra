#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read an integer from input
int ri() {
	char *str;
	int n = 0;
	str = malloc(sizeof(char) * 100);
	fgets(str, 100, stdin);
	for (int i = 0; i < strlen(str); i++) {
		n = n*10 + (str[i] - 48);
	}
	return n;
}

// Function to calculate the average of a slice of float64 numbers
float ave(float *s, int n) {
	float sum = 0;
	for (int i = 0; i < n; i++) {
		sum += s[i];
	}
	return sum / n;
}

// Function to calculate the absolute difference between two float64 numbers
float diff(float a, float b) {
	if (a > b) {
		return a - b;
	}
	return b - a;
}

int main() {
	int n = ri();
	float *a = malloc(sizeof(float) * n);
	for (int i = 0; i < n; i++) {
		a[i] = ri();
	}
	float ave = ave(a, n);
	float minDiff = 999999.9;
	int ansIndex = -1;
	for (int i = 0; i < n; i++) {
		float diff = diff(a[i], ave);
		if (diff < minDiff) {
			minDiff = diff;
			ansIndex = i;
		}
	}
	printf("%d\n", ansIndex);
	return 0;
}

