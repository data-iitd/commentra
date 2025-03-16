#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_N 1000000

int main() {
	int N;
	scanf("%d", &N);
	assert(N <= MAX_N);
	char S[MAX_N];
	scanf("%s", S);
	assert(strlen(S) == N);

	int nr = 0;
	int nb = 0;
	int ng = 0;
	for (int i = 0; i < N; i++) {
		if (S[i] == 'R') {
			nr++;
		}
		if (S[i] == 'B') {
			nb++;
		}
		if (S[i] == 'G') {
			ng++;
		}
	}

	int same = 0;
	for (int a = 1; a < N; a++) {
		int i = 0;
		int j = 1 * a;
		int k = 2 * a;
		if (k >= N) {
			break;
		}
		for (k = 2 * a; k < N; k++) {
			if (S[i]!= S[j] && S[i]!= S[k] && S[j]!= S[k]) {
				same++;
			}
			i++;
			j++;
			k++;
		}
	}

	int tot = nr * nb * ng;
	printf("%d\n", tot - same);
	return 0;
}
