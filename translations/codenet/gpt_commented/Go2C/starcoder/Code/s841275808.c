

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// ScanInt reads an integer from the standard input and returns it
int ScanInt(void) {
	int i;
	scanf("%d", &i);
	return i;
}

// ScanFloat64 reads a float64 from the standard input and returns it
double ScanFloat64(void) {
	double f;
	scanf("%lf", &f);
	return f;
}

// ScanText reads a string from the standard input and returns it
char* ScanText(void) {
	char* s = malloc(10000);
	scanf("%s", s);
	return s;
}

// Max returns the maximum of two integers
int Max(int a, int b) {
	if (a < b) {
		return b;
	}
	return a;
}

// Min returns the minimum of two integers
int Min(int a, int b) {
	if (a > b) {
		return b;
	}
	return a;
}

// Abs returns the absolute value of an integer
int Abs(int a) {
	if (a < 0) {
		a *= -1;
	}
	return a;
}

// main is the entry point of the program
int main(void) {
	// Read the number of elements
	int N = ScanInt();
	// Initialize slices to hold the original values and a sorted copy
	int* X = malloc(N * sizeof(int));
	int* Y = malloc(N * sizeof(int));
	
	// Read N integers into slice X and copy them to slice Y
	for (int i = 0; i < N; i++) {
		X[i] = ScanInt();
		Y[i] = X[i];
	}
	
	// Sort the slice Y to find the median values
	qsort(Y, N, sizeof(int), (int (*)(const void*, const void*)) &Max);
	// Calculate the two middle values (medians) for even-sized arrays
	int m1 = Y[N / 2 - 1]; // First median
	int m2 = Y[N / 2];     // Second median
	
	// For each element in X, print the appropriate median based on its value
	for (int i = 0; i < N; i++) {
		if (X[i] <= m1) {
			printf("%d\n", m2); // If X[i] is less than or equal to m1, print m2
		} else {
			printf("%d\n", m1); // Otherwise, print m1
		}
	}
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// ScanInt reads an integer from the standard input and returns it
int ScanInt(void) {
	int i;
	scanf("%d", &i);
	return i;
}

// ScanFloat64 reads a float64 from the standard input and returns it
double ScanFloat64(void) {
	double f;
	scanf("%lf", &f);
	return f;
}

// ScanText reads a string from the standard input and returns it
char* ScanText(void) {
	char* s = malloc(10000);
	scanf("%s", s);
	return s;
}

// Max returns the maximum of two integers
int Max(int a, int b) {
	if (a < b) {
		return b;
	}
	return a;
}

// Min returns the minimum of two integers
int Min(int a, int b) {
	if (a > b) {
		return b;
	}
	return a;
}

// Abs returns the absolute value of an integer
int Abs(int a) {
	if (a < 0) {
		a *= -1;
	}
	return a;
}

// main is the entry point of the program
int main(void) {
	// Read the number of elements
	int N = ScanInt();
	// Initialize slices to hold the original values and a sorted copy
	int* X = malloc(N * sizeof(int));
	int* Y = malloc(N * sizeof(int));
	
	// Read N integers into slice X and copy them to slice Y
	for (int i = 0; i < N; i++) {
		X[i] = ScanInt();
		Y[i] = X[i];
	}
	
	// Sort the slice Y to find the median values
	qsort(Y, N, sizeof(int), (int (*)(const void*, const void*)) &Max);
	// Calculate the two middle values (medians) for even-sized arrays
	int m1 = Y[N / 2 - 1]; // First median
	int m2 = Y[N / 2];     // Second median
	
	// For each element in X, print the appropriate median based on its value
	for (int i = 0; i < N; i++) {
		if (X[i] <= m1) {
			printf("%d\n", m2); // If X[i] is less than or equal to m1, print m2
		} else {
			printf("%d\n", m1); // Otherwise, print m1
		}
	}
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// ScanInt reads an integer from the standard input and returns it
int ScanInt(void) {
	int i;
	scanf("%d", &i);
	return i;
}

// ScanFloat64 reads a float64 from the standard input and returns it
double ScanFloat64(void) {
	double f;
	scanf("%lf", &f);
	return f;
}

// ScanText reads a string from the standard input and returns it
char* ScanText(void) {
	char* s = malloc(10000);
	scanf("%s", s);
	return s;
}

// Max returns the maximum of two integers
int Max(int a, int b) {
	if (a < b) {
		return b;
	}
	return a;
}

// Min returns the minimum of two integers
int Min(int a, int b) {
	if (a > b) {
		return b;
	}
	return a;
}

// Abs returns the absolute value of an integer
int Abs(int a) {
	if (a < 0) {
		a *= -1;
	}
	return a;
}

// main is the entry point of the program
int main(void) {
	// Read the number of elements
	int N = ScanInt();
	// Initialize slices to hold the original values and a sorted copy
	int* X = malloc(N * sizeof(int));
	int* Y = malloc(N * sizeof(int));
	
	// Read N integers into slice X and copy them to slice Y
	for (int i = 0; i < N; i++) {
		X[i] = ScanInt();
		Y[i] = X[i];
	}
	
	// Sort the slice Y to find the median values
	qsort(Y, N, sizeof(int), (int (*)(const void*, const void*)) &Max);
	// Calculate the two middle values (medians) for even-sized arrays
	int m1 = Y[N / 2 - 1]; // First median
	int m2 = Y[N / 2];     // Second median
	
	// For each element in X, print the appropriate median based on its value
	for (int i = 0; i < N; i++) {
		if (X[i] <= m1) {
			printf("%d\n", m2); // If X[i] is less than or equal to m1, print m2
		} else {
			printf("%d\n", m1); // Otherwise, print m1
		}
	}
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// ScanInt reads an integer from the standard input and returns it
int ScanInt(void) {
	int i;
	scanf("%d", &i);
	return i;
}

// ScanFloat64 reads a float64 from the standard input and returns it
double ScanFloat64(void) {
	double f;
	scanf("%lf", &f);
	return f;
}

// ScanText reads a string from the standard input and returns it
char* ScanText(void) {
	char* s = malloc(10000);
	scanf("%s", s);
	return s;
}

// Max returns the maximum of two integers
int Max(int a, int b) {
	if (a < b) {
		return b;
	}
	return a;
}

// Min returns the minimum of two integers
int Min(int a, int b) {
	if (a > b) {
		return b;
	}
	return a;
}

// Abs returns the absolute value of an integer
int Abs(int a) {
	if (a < 0) {
		a *= -1;
	}
	return a;
}

// main is the entry point of the program
int main(void) {
	// Read the number of elements
	int N = ScanInt();
	// Initialize slices to hold the original values and a sorted copy
	int* X = malloc(N * sizeof(int));
	int* Y = malloc(N * sizeof(int));
	
	// Read N integers into slice X and copy them to slice Y
	for (int i = 0; i < N; i++) {
		X[i] = ScanInt();
		Y[i] = X[i];
	}
	
	// Sort the slice Y to find the median values
	qsort(Y, N, sizeof(int), (int (*)(const void*, const void*)) &Max);
	// Calculate the two middle values (medians) for even-sized arrays
	int m1 = Y[N / 2 - 1]; // First median
	int m2 = Y[N / 2];     // Second median
	
	// For each element in X, print the appropriate median based on its value
	for (int i = 0; i < N; i++) {
		if (X[i] <= m1) {
			printf("%d\n", m2); // If X[i] is less than or equal to m1, print m2
		} else {
			printf("%d\n", m1); // Otherwise, print m1
		}
	}
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// ScanInt reads an integer from the standard input and returns it
int ScanInt(void) {
	int i;
	scanf("%d", &i);
	return i;
}

// ScanFloat64 reads a float64 from the standard input and returns it
double ScanFloat64(void) {
	double f;
	scanf("%lf", &f);
	return f;
}

// ScanText reads a string from the standard input and returns it
char* ScanText(void) {
	char* s = malloc(10000);
	scanf("%s", s);
	return s;
}

// Max returns the maximum of two integers
int Max(int a, int b) {
	if (a < b) {
		return b;
	}
	return a;
}

// Min returns the minimum of two integers
int Min(int a, int b) {
	if (a > b) {
		return b;
	}
	return a;
}

// Abs returns the absolute value of an integer
int Abs(int a) {
	if (a < 0) {
		a *= -1;
	}
	return a;
}

// main is the entry point of the program
int main(void) {
	// Read the number of elements
	int N = ScanInt();
	// Initialize slices to hold the original values and a sorted copy
	int* X = malloc(N * sizeof(int));
	int* Y = malloc(N * sizeof(int));
	
	// Read N integers into slice X and copy them to slice Y
	for (int i = 0; i < N; i++) {
		X[i] = ScanInt();
		Y[i] = X[i];
	}
	
	// Sort the slice Y to find the median values
	qsort(Y, N, sizeof(int), (int (*)(const void*, const void*)) &Max);
	// Calculate the two middle values (medians) for even-sized arrays
	int m1 = Y[N / 2 - 1]; // First median
	int m2 = Y[N / 2];     // Second median
	
	// For each element in X, print the appropriate median based on its value
	for (int i = 0; i < N; i++) {
		if (X[i] <= m1) {
			printf("%d\n", m2); // If X[i] is less than or equal to m1, print m2
		} else {
			printf("%d\n", m1); // Otherwise, print m1
		}
	}
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// ScanInt reads an integer from the standard input and returns it
int ScanInt(void) {
	int i;
	scanf("%d", &i);
	return i;
}

// ScanFloat64 reads a float64 from the standard input and returns it
double ScanFloat64(void) {
	double f;
	scanf("%lf", &f);
	return f;
}

// ScanText reads a string from the standard input and returns it
char* ScanText(void) {
	char* s = malloc(10000);
	scanf("%s", s);
	return s;
}

// Max returns the maximum of two integers
int Max(int a, int b) {
	if (a < b) {
		return b;
	}
	return a;
}

// Min returns the minimum of two integers
int Min(int a, int b) {
	if (a > b) {
		return b;
	}
	return a;
}

// Abs returns the absolute value of an integer
int Abs(int a) {
	if (a < 0) {
		a *= -1;
	}
	return a;
}

// main is the entry point of the program
int main(void) {
	// Read the number of elements
	int N = ScanInt();
	// Initialize slices to hold the original values and a sorted copy
	int* X = malloc(N * sizeof(int));
	int* Y = malloc(N * sizeof(int));
	
	// Read N integers into slice X and copy them to slice Y
	for (int i = 0; i < N; i++) {
		X[i] = ScanInt();
		Y[i] = X[i];
	}
	
	// Sort the slice