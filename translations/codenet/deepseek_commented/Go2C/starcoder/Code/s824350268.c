#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define initialBufSize 10000
#define maxBufSize 1000000
#define mod 1e9 + 7

int getInt();
char *getString();

int main() {
	int N = getInt();
	int sqrtN = (int) sqrt(N);

	int min = N;
	for (int i = 1; i <= sqrtN; i++) {
		if (N % i!= 0) {
			continue;
		}

		int num = i + (N / i) - 2;
		if (num < min) {
			min = num;
		}
	}

	printf("%d\n", min);
}

int getInt() {
	char *s = getString();
	int i = atoi(s);
	free(s);
	return i;
}

char *getString() {
	char *s = malloc(initialBufSize);
	char *p = s;
	int i = 0;
	while (1) {
		if (i == initialBufSize - 1) {
			s = realloc(s, initialBufSize * 2);
			p = s + i;
			initialBufSize *= 2;
		}
		p[i] = getchar();
		if (p[i] == '\n' || p[i] == EOF) {
			p[i] = '\0';
			break;
		}
		i++;
	}
	return s;
}

