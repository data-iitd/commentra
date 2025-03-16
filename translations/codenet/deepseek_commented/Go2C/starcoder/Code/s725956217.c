#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <float.h>
#include <ctype.h>
#include <time.h>
#include <limits.h>
#include <stdarg.h>
#include <inttypes.h>
#include <setjmp.h>
#include <signal.h>
#include <stdbool.h>
#include <complex.h>
#include <stdalign.h>
#include <stdatomic.h>
#include <stdnoreturn.h>
#include <tgmath.h>
#include <threads.h>
#include <stdalign.h>
#include <stdarg.h>
#include <stdatomic.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <wchar.h>
#include <wctype.h>

// Helper function to print output.
void out(int x,...) {
	va_list args;
	va_start(args, x);
	vprintf(x, args);
	va_end(args);
}

// Scanner to read input from standard input.
typedef struct {
	char *s;
	int len;
	int pos;
} Scanner;

// Function to read an integer from input.
int getInt(Scanner *sc) {
	while (isspace(sc->s[sc->pos])) {
		sc->pos++;
	}
	int x = 0;
	bool neg = false;
	if (sc->s[sc->pos] == '-') {
		neg = true;
		sc->pos++;
	}
	while (isdigit(sc->s[sc->pos])) {
		x = x * 10 + sc->s[sc->pos] - '0';
		sc->pos++;
	}
	if (neg) {
		x = -x;
	}
	return x;
}

// Function to read a string from input.
char *getString(Scanner *sc) {
	while (isspace(sc->s[sc->pos])) {
		sc->pos++;
	}
	char *x = sc->s + sc->pos;
	while (!isspace(sc->s[sc->pos])) {
		sc->pos++;
	}
	sc->s[sc->pos] = 0;
	sc->pos++;
	return x;
}

// Function to return the maximum of two integers.
int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

// Function to return the minimum of two integers.
int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

// Function to return the absolute difference between two integers.
int asub(int a, int b) {
	if (a > b) {
		return a - b;
	}
	return b - a;
}

// Function to return the absolute value of an integer.
int abs(int a) {
	if (a >= 0) {
		return a;
	}
	return -a;
}

// Function to find the lower bound index of a value in a sorted array.
int lowerBound(int *a, int x, int n) {
	int idx = 0;
	while (idx < n && a[idx] < x) {
		idx++;
	}
	return idx;
}

// Function to find the upper bound index of a value in a sorted array.
int upperBound(int *a, int x, int n) {
	int idx = 0;
	while (idx < n && a[idx] <= x) {
		idx++;
	}
	return idx;
}

// Struct to represent a shop with its price and stock.
typedef struct {
	int a, b;
} shop;

// Slice of shops to implement sorting.
typedef struct {
	shop *data;
	int len;
} Datas;

// Implementing sort.Interface for Datas.
int DatasLen(Datas p) {
	return p.len;
}

void DatasSwap(Datas p, int i, int j) {
	shop tmp = p.data[i];
	p.data[i] = p.data[j];
	p.data[j] = tmp;
}

bool DatasLess(Datas p, int i, int j) {
	return p.data[i].a < p.data[j].a;
}

// Main function to execute the program logic.
int main() {
	Scanner sc;
	sc.s = calloc(1000000, sizeof(char));
	scanf("%s", sc.s);
	sc.len = strlen(sc.s);
	sc.pos = 0;

	// Read the number of shops and the amount of items to buy.
	int N = getInt(&sc);
	int M = getInt(&sc);

	// Create a slice of shops and read each shop's price and stock.
	Datas s = {calloc(N, sizeof(shop)), N};
	for (int i = 0; i < N; i++) {
		s.data[i].a = getInt(&sc);
		s.data[i].b = getInt(&sc);
	}

	// Sort the shops by price.
	qsort(s.data, N, sizeof(shop), (int (*)(const void *, const void *)) DatasLess);

	// Calculate the total cost of buying the required number of items.
	int total = 0;
	for (int i = 0; i < N; i++) {
		// Determine the number of items to buy from the current shop.
		int n = min(s.data[i].b, M);
		// Update the total cost and the remaining items to buy.
		total += n * s.data[i].a;
		M -= n;
		// Break if all items are bought.
		if (M == 0) {
			break;
		}
	}

	// Print the total cost.
	out("%d", total);
}

