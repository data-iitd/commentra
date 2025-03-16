
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Block represents a run-length encoded block of characters
typedef struct {
	char Value;
	int Len;
} Block;

// RunLength performs run-length encoding on the input string
Block* RunLength(char* s) {
	int N = strlen(s);
	if (N == 0) {
		return NULL;
	}
	Block* r = (Block*)malloc(sizeof(Block) * N);
	Block t = {s[0], 1};
	for (int i = 1; i < N; i++) {
		if (t.Value == s[i]) {
			t.Len++;
		} else {
			r[i - 1] = t;
			t = (Block){s[i], 1};
		}
	}
	r[N - 1] = t;
	return r;
}

// Max returns the maximum of two integers
int Max(int a, int b) {
	if (b > a) {
		return b;
	}
	return a;
}

int main() {
	int N, K, ans = 0, zero = 0, l = 0, sum = 0;
	scanf("%d %d", &N, &K);
	char* S = (char*)malloc(sizeof(char) * N);
	scanf("%s", S);
	Block* blocks = RunLength(S);
	for (int r = 0; r < N; r++) {
		sum += blocks[r].Len;
		if (blocks[r].Value == '0') {
			zero++;
		}
		// Adjust the window size if the number of '0' blocks exceeds K
		for (int k = 0; k < K && zero > K; k++) {
			sum -= blocks[l].Len;
			if (blocks[l].Value == '0') {
				zero--;
			}
			l++;
		}
		ans = Max(ans, sum);
	}
	printf("%d\n", ans);
	return 0;
}

