
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <float.h>
#include <ctype.h>
#include <stdarg.h>
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <setjmp.h>
#include <errno.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>
#include <fenv.h>
#include <inttypes.h>
#include <stdint.h>
#include <complex.h>
#include <stdbool.h>
#include <tgmath.h>
#include <stdalign.h>
#include <stdatomic.h>
#include <stdnoreturn.h>
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
#include <tgmath.h>
#include <time.h>
#include <uchar.h>
#include <wchar.h>
#include <wctype.h>

int main() {
	// Create a map to store the counts of integers
	int *m = (int *)malloc(sizeof(int) * 1000000);
	memset(m, 0, sizeof(int) * 1000000);
	
	// Read the number of initial elements (N) and the number of operations (M)
	int N = 0, M = 0;
	scanf("%d %d", &N, &M);
	
	// Read N integers and store their counts in the map
	for (int i = 0; i < N; i++) {
		int x = 0;
		scanf("%d", &x);
		m[x]++;
	}
	
	// Perform M operations to update the map with new integers and their counts
	for (int i = 0; i < M; i++) {
		int B = 0, C = 0;
		scanf("%d %d", &B, &C);
		m[C] += B;
	}
	
	// Create a slice of integers from the map keys
	int *ints = (int *)malloc(sizeof(int) * 1000000);
	memset(ints, 0, sizeof(int) * 1000000);
	int j = 0;
	for (int i = 0; i < 1000000; i++) {
		if (m[i] > 0) {
			ints[j++] = i;
		}
	}
	
	// Sort the slice of integers in descending order
	qsort(ints, j, sizeof(int), (int (*)(const void *, const void *))qsort_cmp);
	
	// Initialize variables to keep track of the remaining elements and the sum
	int rest = N;
	int sum = 0;
	
	// Iterate through the sorted integers and calculate the sum based on the conditions
	for (int i = 0; i < j; i++) {
		int num = m[ints[i]];
		if (num >= rest) {
			sum += rest * ints[i];
			break;
		}
		sum += num * ints[i];
		rest -= num;
	}
	
	// Print the calculated sum
	printf("%d\n", sum);
}

// Helper function to compare two integers
int qsort_cmp(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}

