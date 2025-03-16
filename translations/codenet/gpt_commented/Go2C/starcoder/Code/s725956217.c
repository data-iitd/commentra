

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>
#include <stdarg.h>
#include <setjmp.h>
#include <time.h>
#include <errno.h>
#include <ctype.h>
#include <locale.h>
#include <wctype.h>
#include <fenv.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>
#include <stdarg.h>
#include <setjmp.h>
#include <time.h>
#include <errno.h>
#include <ctype.h>
#include <locale.h>
#include <wctype.h>
#include <fenv.h>
#include <inttypes.h>
#include <stdint.h>

// out is a utility function to print output to the console.
void out(int x) {
	printf("%d\n", x);
}

// sc is a scanner for reading input from standard input.
int sc;

// getInt reads an integer from input and returns it.
int getInt() {
	scanf("%d", &sc);
	return sc;
}

// getString reads a string from input and returns it.
char* getString() {
	char* s = malloc(1000000);
	scanf("%s", s);
	return s;
}

// max returns the maximum of two integers.
int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

// min returns the minimum of two integers.
int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

// asub returns the absolute difference between two integers.
int asub(int a, int b) {
	if (a > b) {
		return a - b;
	}
	return b - a;
}

// abs returns the absolute value of an integer.
int abs(int a) {
	if (a >= 0) {
		return a;
	}
	return -a;
}

// lowerBound returns the index of the first element in a that is not less than x.
int lowerBound(int* a, int x, int n) {
	int idx = 0;
	while (idx < n && a[idx] < x) {
		idx++;
	}
	return idx;
}

// upperBound returns the index of the first element in a that is greater than x.
int upperBound(int* a, int x, int n) {
	int idx = 0;
	while (idx < n && a[idx] <= x) {
		idx++;
	}
	return idx;
}

// shop represents a shop with a price (a) and available quantity (b).
struct shop {
	int a, b;
};

// Datas is a slice of shop, implementing sort.Interface.
struct Datas {
	int len;
	struct shop* s;
};

// Len returns the number of elements in the slice.
int (Datas) Len() {
	return len;
}

// Swap exchanges the elements with indexes i and j.
void (Datas) Swap(int i, int j) {
	struct shop tmp = s[i];
	s[i] = s[j];
	s[j] = tmp;
}

// Less reports whether the element with index i should sort before the element with index j.
bool (Datas) Less(int i, int j) {
	return s[i].a < s[j].a; // Sort by price (a)
}

// main is the entry point of the program.
int main() {
	sc = 0;
	// Read the number of shops (N) and the total quantity needed (M)
	int N = getInt(), M = getInt();
	struct Datas s = {N, malloc(N * sizeof(struct shop))};

	// Read the price and quantity for each shop
	for (int i = 0; i < N; i++) {
		s.s[i].a = getInt();
		s.s[i].b = getInt();
	}
	qsort(s.s, N, sizeof(struct shop), (int (*)(const void*, const void*)) (s.Less)); // Sort the shops by price

	int total = 0; // Initialize total cost
	// Calculate the total cost based on available quantities and prices
	for (int i = 0; i < N; i++) {
		int n = min(s.s[i].b, M); // Determine how much can be bought from this shop
		total += n * s.s[i].a; // Add to total cost
		M -= n; // Decrease the remaining quantity needed
		if (M == 0) {
			break; // Stop if the required quantity is met
		}
	}
	out(total); // Output the total cost
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>
#include <stdarg.h>
#include <setjmp.h>
#include <time.h>
#include <errno.h>
#include <ctype.h>
#include <locale.h>
#include <wctype.h>
#include <fenv.h>
#include <inttypes.h>
#include <stdint.h>

// out is a utility function to print output to the console.
void out(int x) {
	printf("%d\n", x);
}

// sc is a scanner for reading input from standard input.
int sc;

// getInt reads an integer from input and returns it.
int getInt() {
	scanf("%d", &sc);
	return sc;
}

// getString reads a string from input and returns it.
char* getString() {
	char* s = malloc(1000000);
	scanf("%s", s);
	return s;
}

// max returns the maximum of two integers.
int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

// min returns the minimum of two integers.
int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

// asub returns the absolute difference between two integers.
int asub(int a, int b) {
	if (a > b) {
		return a - b;
	}
	return b - a;
}

// abs returns the absolute value of an integer.
int abs(int a) {
	if (a >= 0) {
		return a;
	}
	return -a;
}

// lowerBound returns the index of the first element in a that is not less than x.
int lowerBound(int* a, int x, int n) {
	int idx = 0;
	while (idx < n && a[idx] < x) {
		idx++;
	}
	return idx;
}

// upperBound returns the index of the first element in a that is greater than x.
int upperBound(int* a, int x, int n) {
	int idx = 0;
	while (idx < n && a[idx] <= x) {
		idx++;
	}
	return idx;
}

// shop represents a shop with a price (a) and available quantity (b).
struct shop {
	int a, b;
};

// Datas is a slice of shop, implementing sort.Interface.
struct Datas {
	int len;
	struct shop* s;
};

// Len returns the number of elements in the slice.
int (Datas) Len() {
	return len;
}

// Swap exchanges the elements with indexes i and j.
void (Datas) Swap(int i, int j) {
	struct shop tmp = s[i];
	s[i] = s[j];
	s[j] = tmp;
}

// Less reports whether the element with index i should sort before the element with index j.
bool (Datas) Less(int i, int j) {
	return s[i].a < s[j].a; // Sort by price (a)
}

// main is the entry point of the program.
int main() {
	sc = 0;
	// Read the number of shops (N) and the total quantity needed (M)
	int N = getInt(), M = getInt();
	struct Datas s = {N, malloc(N * sizeof(struct shop))};

	// Read the price and quantity for each shop
	for (int i = 0; i < N; i++) {
		s.s[i].a = getInt();
		s.s[i].b = getInt();
	}
	qsort(s.s, N, sizeof(struct shop), (int (*)(const void*, const void*)) (s.Less)); // Sort the shops by price

	int total = 0; // Initialize total cost
	// Calculate the total cost based on available quantities and prices
	for (int i = 0; i < N; i++) {
		int n = min(s.s[i].b, M); // Determine how much can be bought from this shop
		total += n * s.s[i].a; // Add to total cost
		M -= n; // Decrease the remaining quantity needed
		if (M == 0) {
			break; // Stop if the required quantity is met
		}
	}
	out(total); // Output the total cost
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>
#include <stdarg.h>
#include <setjmp.h>
#include <time.h>
#include <errno.h>
#include <ctype.h>
#include <locale.h>
#include <wctype.h>
#include <fenv.h>
#include <inttypes.h>
#include <stdint.h>

// out is a utility function to print output to the console.
void out(int x) {
	printf("%d\n", x);
}

// sc is a scanner for reading input from standard input.
int sc;

// getInt reads an integer from input and returns it.
int getInt() {
	scanf("%d", &sc);
	return sc;
}

// getString reads a string from input and returns it.
char* getString() {
	char* s = malloc(1000000);
	scanf("%s", s);
	return s;
}

// max returns the maximum of two integers.
int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

// min returns the minimum of two integers.
int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

// asub returns the absolute difference between two integers.
int asub(int a, int b) {
	if (a > b) {
		return a - b;
	}
	return b - a;
}

// abs returns the absolute value of an integer.
int abs(int a) {
	if (a >= 0) {
		return a;
	}
	return -a;
}

// lowerBound returns the index of the first element in a that is not less than x.
int lowerBound(int* a, int x, int n) {
	int idx = 0;
	while (idx < n && a[idx] < x) {
		idx++;
	}
	return idx;
}

// upperBound returns the index of the first element in a that is greater than x.
int upperBound(int* a, int x, int n) {
	int idx = 0;
	while (idx < n && a[idx] <= x) {
		idx++;
	}
	return idx;
}

// shop represents a shop with a price (a) and available quantity (b).
struct shop {
	int a, b;
};

// Datas is a slice of shop, implementing sort.Interface.
struct Datas {
	int len;
	struct shop* s;
};

// Len returns the number of elements in the slice.
int (Datas) Len() {
	return len;
}

// Swap exchanges the elements with indexes i and j.
void (Datas) Swap(int i, int j) {
	struct shop tmp = s[i];
	s[i] = s[j];
	s[j] = tmp;
}

// Less reports whether the element with index i should sort before the element with index j.
bool (Datas) Less(int i, int j) {
	return s[i].a < s[j].a; // Sort by price (a)
}

// main is the entry point of the program.
int main() {
	sc = 0;
	// Read the number of shops (N) and the total quantity needed (M)
	int N = getInt(), M = getInt();
	struct Datas s = {N, malloc(N * sizeof(struct shop))};

	// Read the price and quantity for each shop
	for (int i = 0; i < N; i++) {
		s.s[i].a = getInt();
		s.s[i].b = getInt();
	}
	qsort(s.s, N, sizeof(struct shop), (int (*)(const void*, const void*)) (s.Less)); // Sort the shops by price

	int total = 0; // Initialize total cost
	// Calculate the total cost based on available quantities and prices
	for (int i = 0; i < N; i++) {
		int n = min(s.s[i].b, M); // Determine how much can be bought from this shop
		total += n * s.s[i].a; // Add to total cost
		M -= n; // Decrease the remaining quantity needed
		if (M == 0) {
			break; // Stop if the required quantity is met
		}
	}
	out(total); // Output the total cost
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>
#include 