#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Block {
	char Value;
	int Len;
} Block;

int main() {
	int N, K, ans, sum, zero, l;
	scanf("%d %d", &N, &K);
	char *S = (char *)malloc(sizeof(char) * 1000000);
	scanf("%s", S);
	Block *blocks = (Block *)malloc(sizeof(Block) * N);
	int i, r;
	for (i = 0; i < N; i++) {
		blocks[i].Value = S[i];
		blocks[i].Len = 1;
	}
	for (i = 1; i < N; i++) {
		if (blocks[i].Value == blocks[i - 1].Value) {
			blocks[i].Len = blocks[i - 1].Len + 1;
		}
	}
	sum = zero = l = 0;
	for (r = 0; r < N; r++) {
		sum += blocks[r].Len;
		if (blocks[r].Value == '0') {
			zero++;
		}
		for (K < zero) {
			sum -= blocks[l].Len;
			if (blocks[l].Value == '0') {
				zero--;
			}
			l++;
		}
		ans = (ans > sum)? ans : sum;
	}
	printf("%d\n", ans);
	return 0;
}

