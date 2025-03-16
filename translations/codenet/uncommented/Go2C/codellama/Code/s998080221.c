
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
	int N, M;
	int A[100000];
} Input;

typedef struct {
	int maxProfit;
	int maxCnt;
} Output;

void solve(Input *input, Output *output) {
	int N = input->N;
	int A[100000];
	for (int i = 0; i < N; i++) {
		A[i] = input->A[i];
	}
	int maxProfit = 0;
	int maxCnt = 0;
	int maxA = A[N-1];
	for (int i = N - 2; i >= 0; i--) {
		int profit = max(0, maxA-A[i]);
		if (maxProfit < profit) {
			maxProfit = profit;
			maxCnt = 1;
		} else if (maxProfit == profit) {
			maxCnt++;
		}
		maxA = max(maxA, A[i]);
	}
	output->maxProfit = maxProfit;
	output->maxCnt = maxCnt;
}

int max(int x, int y) {
	if (x > y) {
		return x;
	}
	return y;
}

int main() {
	Input input;
	Output output;
	scanf("%d %d", &input.N, &input.M);
	for (int i = 0; i < input.N; i++) {
		scanf("%d", &input.A[i]);
	}
	solve(&input, &output);
	printf("%d\n", output.maxCnt);
	return 0;
}

