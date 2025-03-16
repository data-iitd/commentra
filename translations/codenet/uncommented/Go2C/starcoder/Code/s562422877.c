#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>
#include <time.h>
#include <stdarg.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>
#include <time.h>
#include <stdarg.h>
#include <inttypes.h>
#include <stdint.h>

int main() {
	// Code for B - Traveling AtCoDeer Problem
	int N;
	scanf("%d", &N);

	int A[N];
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}

	qsort(A, N, sizeof(int), compare);

	int ans = 0;
	for (int i = 1; i < N; i++) {
		ans += A[i] - A[i-1];
	}

	printf("%d\n", ans);
}

