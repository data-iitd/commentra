#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define initialBufSize 10000
#define maxBufSize 100000000

int main() {
	char buf[initialBufSize]; // Initialize input buffer
	char *s = buf;
	int scanned = 0;
	int N, K;

	// Read input numbers N and K
	scanf("%d %d", &N, &K);

	// Calculate the base-10 representation of N up to digit count K
	s = TenToN(N, K, s);

	// Print the length of the calculated string
	printf("%d\n", strlen(s));

	return 0;
}

char *TenToN(int number, int n, char *s) {
	int tmp = number; // Initialize temporary variable

	// Repeat the following process until the number becomes less than N
	while (tmp >= n) {
		// Append the remainder of the division by N to the result string
		sprintf(s, "%d%s", tmp % n, s);

		// If the number is less than N, break the loop
		if (tmp < n) {
			break;
		}

		// Divide the number by N
		tmp /= n;
	}

	// Return the result string
	return s;
}

