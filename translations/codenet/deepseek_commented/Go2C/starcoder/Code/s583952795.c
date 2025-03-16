#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 1000000

int main() {
	int N, K;
	scanf("%d %d", &N, &K);

	char s[MAX_N];
	int i, j, n = 0;
	for (i = N; i > 0; i /= K) {
		s[n++] = '0' + i % K;
	}
	s[n] = '\0';
	printf("%d\n", n);
	printf("%s\n", s);
	return 0;
}

