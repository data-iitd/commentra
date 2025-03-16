#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main()
{
	// Read the number of elements N
	int N;
	scanf("%d", &N);
	
	// Read N integers into a vector `a`
	int a[N];
	REP(i, N) scanf("%d", &a[i]);

	// Initialize idx to 1 and ans to 0
	int idx = 1;
	int ans = 0;

	// Iterate through the vector `a`
	REP(i, N) {
		// If the current element is equal to `idx`, increment `idx`
		if (a[i] == idx) {
			idx++;
		} else {
			// If not, increment `ans`
			ans++;
		}
	}

	// If `idx` is still 1, it means no elements matched, so print `-1`
	if (idx == 1) {
		printf("-1\n");
	} else {
		// Otherwise, print `ans`
		printf("%d\n", ans);
	}

	return 0;
}

