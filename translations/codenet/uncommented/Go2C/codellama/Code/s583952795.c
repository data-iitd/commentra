#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define initialBufSize 10000
#define maxBufSize 100000000

typedef struct {
	int p1;
	int p2;
} Pair;

int readInt() {
	int read;
	scanf("%d", &read);
	return read;
}

int TenToN(int number, int n) {
	char s[1000000];
	int tmp = number;
	while (1) {
		sprintf(s, "%d%s", tmp % n, s);
		if (tmp < n) {
			break;
		}
		tmp /= n;
	}
	return strlen(s);
}

int main() {
	int N, K;
	N = readInt();
	K = readInt();
	printf("%d\n", TenToN(N, K));
	return 0;
}

