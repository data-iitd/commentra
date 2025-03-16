#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>
#include <float.h>
#include <time.h>
#include <limits.h>
#include <stdarg.h>
#include <setjmp.h>
#include <signal.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>
#include <float.h>
#include <time.h>
#include <limits.h>
#include <stdarg.h>
#include <setjmp.h>
#include <signal.h>
#include <stddef.h>

int main() {
	// Read the number of elements N
	int N;
	scanf("%d", &N);

	// Create a slice A to store N integers
	int A[N];
	for (int i = 0; i < N; i++) {
		// Read each integer and store it in slice A
		scanf("%d", &A[i]);
	}

	// Sort the slice A in ascending order
	qsort(A, N, sizeof(int), compare);

	// Initialize the answer variable to store the result
	int ans = 0;
	for (int i = 1; i < N; i++) {
		// Calculate the sum of differences between consecutive elements
		ans += A[i] - A[i-1];
	}

	// Print the result
	printf("%d", ans);
}

