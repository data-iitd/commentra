
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
#include <stdarg.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <math.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define eprintf(...) fprintf(stderr, __VA_ARGS__)

#define MAX(a, b) ((a) > (b)? (a) : (b))
#define MIN(a, b) ((a) < (b)? (a) : (b))

#define ReadInt() (int)scanf("%d", &i)

int main() {
	// Initialize an empty map to store the frequency of each number
	int m[1000000] = {0};

	// Read the number of test cases N
	int N;
	ReadInt();
	// Read the N integers and store their frequencies in the map
	for (int i = 0; i < N; i++) {
		int num;
		ReadInt();
		m[num]++;
	}

	// Read the number of queries M
	int M;
	ReadInt();
	// For each query, read the number B and the index C, and update the frequency of the number at index C in the map
	for (int i = 0; i < M; i++) {
		int B, C;
		ReadInt();
		ReadInt();
		m[C] += B;
	}

	// Create a slice of integers from the map keys
	int ints[1000000];
	int i = 0;
	// Populate the slice with the map keys
	for (int k = 0; k < 1000000; k++) {
		if (m[k] > 0) {
			ints[i] = k;
			i++;
		}
	}

	// Sort the slice in descending order
	qsort(ints, i, sizeof(int), compare);

	// Initialize variables for calculating the sum
	int rest = N;
	int sum = 0;
	// Iterate through the sorted slice of integers
	for (int j = 0; j < i; j++) {
		int num = m[ints[j]];
		// If the number's frequency is greater than or equal to the remaining number of elements, calculate the sum and break the loop
		if (num >= rest) {
			sum += rest * ints[j];
			break;
		}
		// Otherwise, add the product of the number's frequency and its index to the sum, and subtract the number's frequency from the remaining number of elements
		sum += num * ints[j];
		rest -= num;
	}

	// Print the result
	printf("%d\n", sum);
}

int compare(const void *a, const void *b) {
	return *(int *)b - *(int *)a;
}

