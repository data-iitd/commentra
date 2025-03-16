#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int N, K;
	scanf("%d %d", &N, &K);
	char s[1000000];
	int i, j, tmp;
	for (i = 0; i < N; i++) {
		tmp = i;
		for (j = 0; j < K; j++) {
			s[i] = tmp % K + '0';
			if (tmp < K) {
				break;
			}
			tmp /= K;
		}
	}
	printf("%d\n", strlen(s));
	return 0;
}

