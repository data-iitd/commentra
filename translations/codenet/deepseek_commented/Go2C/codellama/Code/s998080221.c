
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_N 100000

int N, A[MAX_N];

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	int maxProfit = 0, maxCnt = 0, maxA = A[N-1];
	for (int i = N - 2; i >= 0; i--) {
		int profit = max(0, maxA - A[i]);
		if (maxProfit < profit) {
			maxProfit = profit;
			maxCnt = 1;
		} else if (maxProfit == profit) {
			maxCnt++;
		}
		maxA = max(maxA, A[i]);
	}
	printf("%d\n", maxCnt);
	return 0;
}

int max(int a, int b) {
	return a > b ? a : b;
}

