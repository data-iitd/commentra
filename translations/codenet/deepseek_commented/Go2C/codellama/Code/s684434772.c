
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Go:

// Combination Function
// The combi function calculates the number of combinations of choosing k items from n items.
// It uses a simplified formula to find the range of the binomial coefficient.
int64_t combi(int n, int k) {
	int64_t min = (k-1)*k/2; // Calculate the minimum value of the binomial coefficient.
	int64_t max = (2*n-k+1)*k/2; // Calculate the maximum value of the binomial coefficient.
	return max - min + 1; // Return the number of combinations.
}

// Utility Functions
// These functions provide basic mathematical operations and input reading capabilities.

// Abs returns the absolute value of an integer.
int Abs(int x) {
	if (x >= 0) {
		return x;
	}
	return -x;
}

// Min returns the smallest value among the given integers.
int Min(int values[], int size) {
	if (size == 0) {
		printf("no values");
		return 0;
	}
	int min = values[0];
	for (int i = 1; i < size; i++) {
		if (values[i] < min) {
			min = values[i];
		}
	}
	return min;
}

// Max returns the largest value among the given integers.
int Max(int values[], int size) {
	if (size == 0) {
		printf("no values");
		return 0;
	}
	int max = values[0];
	for (int i = 1; i < size; i++) {
		if (values[i] > max) {
			max = values[i];
		}
	}
	return max;
}

// Pow returns the base raised to the power of exponent.
int Pow(int base, int exponent) {
	int answer = 1;
	for (int i = 0; i < exponent; i++) {
		answer *= base;
	}
	return answer;
}

// Abs64 returns the absolute value of a 64-bit integer.
int64_t Abs64(int64_t x) {
	if (x >= 0) {
		return x;
	}
	return -x;
}

// Min64 returns the smallest value among the given 64-bit integers.
int64_t Min64(int64_t values[], int size) {
	if (size == 0) {
		printf("no values");
		return 0;
	}
	int64_t min = values[0];
	for (int i = 1; i < size; i++) {
		if (values[i] < min) {
			min = values[i];
		}
	}
	return min;
}

// Max64 returns the largest value among the given 64-bit integers.
int64_t Max64(int64_t values[], int size) {
	if (size == 0) {
		printf("no values");
		return 0;
	}
	int64_t max = values[0];
	for (int i = 1; i < size; i++) {
		if (values[i] > max) {
			max = values[i];
		}
	}
	return max;
}

// Pow64 returns the base raised to the power of exponent for 64-bit integers.
int64_t Pow64(int64_t base, int exponent) {
	int64_t answer = 1;
	for (int i = 0; i < exponent; i++) {
		answer *= base;
	}
	return answer;
}

// Scanner Struct
// The Scanner struct provides methods to read input efficiently.

typedef struct {
	FILE *file;
} Scanner;

Scanner NewScanner() {
	Scanner sc;
	sc.file = stdin;
	return sc;
}

char *ReadString(Scanner *sc) {
	char *text = malloc(sizeof(char) * 1000);
	fscanf(sc->file, "%s", text);
	return text;
}

int ReadInt(Scanner *sc) {
	int num;
	fscanf(sc->file, "%d", &num);
	return num;
}

int64_t ReadInt64(Scanner *sc) {
	int64_t num;
	fscanf(sc->file, "%lld", &num);
	return num;
}

// Main Function
// The main function reads two integers, n and k, and calculates the sum of combinations from k to n+1.
// It uses a modulo operation to prevent overflow and prints the final result.
int main() {
	Scanner sc = NewScanner(); // Create a new Scanner instance to read input.

	int n = ReadInt(&sc); // Read the first integer, n.
	int k = ReadInt(&sc); // Read the second integer, k.

	int64_t total = 0; // Initialize the total sum of combinations.
	for (int i = k; i <= n+1; i++) {
		total += combi(n, i); // Calculate the combination and add it to the total.
		total = total % (Pow64(10, 9) + 7); // Apply modulo operation to prevent overflow.
	}
	printf("%lld\n", total); // Print the final result.
	return 0;
}

