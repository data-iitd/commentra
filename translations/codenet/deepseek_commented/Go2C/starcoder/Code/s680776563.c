
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Utility functions for various operations.
int IntMax(int a, int b) {
	if (a < b) {
		return b;
	}
	return a;
}

int IntMin(int a, int b) {
	if (a > b) {
		return b;
	}
	return a;
}

int IntGcd(int a, int b) {
	if (a < b) {
		b = a - b;
	}
	if (b == 0) {
		return a;
	}
	return IntGcd(b, a % b);
}

int IntAbs(int a) {
	if (a < 0) {
		a *= -1;
	}
	return a;
}

// Main function: Entry point of the program.
// Initializes a FastScanner, reads three integers A, B, and C,
// and checks if the difference between consecutive integers is the same.
// If the difference is the same, it prints "YES"; otherwise, it prints "NO".
int main() {
	int A, B, C;
	scanf("%d %d %d", &A, &B, &C);
	if (B - A == C - B) {
		printf("YES");
	} else {
		printf("NO");
	}
	return 0;
}

