#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ri() reads an integer from standard input.
int ri() {
	int n;
	scanf("%d", &n);
	return n;
}

// ave(s) calculates the average of a slice of float64 values.
float ave(float s[]) {
	int i;
	float sum = 0;
	for (i = 0; i < sizeof(s) / sizeof(float); i++) {
		sum += s[i];
	}
	return sum / (sizeof(s) / sizeof(float));
}

// diff(a, b) calculates the absolute difference between two float64 values.
float diff(float a, float b) {
	if (a > b) {
		return a - b;
	}
	return b - a;
}

// main function is the entry point of the program.
int main() {
	int n = ri(); // Reads the number of elements.
	float a[n];
	for (int i = 0; i < n; i++) {
		a[i] = ri(); // Reads n integers into a float64 slice.
	}
	// Uncommenting the following line will print the slice for debugging purposes.
	// printf("%f\n", a);

	float ave = ave(a); // Calculates the average of the slice.

	float minDiff = 999999.9;
	int ansIndex = -1;
	for (int i = 0; i < n; i++) {
		float diff = diff(a[i], ave); // Calculates the absolute difference between each element and the average.
		if (diff < minDiff) {
			minDiff = diff;
			ansIndex = i;
		}
	}
	printf("%d\n", ansIndex); // Outputs the index with the smallest difference.
	return 0;
}

