#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_BUF_SIZE 10000
#define MAX_BUF_SIZE 100000000

char *next() {
	static char *buf = NULL;
	static size_t buf_size = 0;
	char *ret = NULL;
	if (buf_size < MAX_BUF_SIZE) {
		buf_size *= 2;
		buf = realloc(buf, buf_size);
	}
	ret = fgets(buf, buf_size, stdin);
	return ret;
}

int min(int x, int y) {
	if (x > y) {
		return y;
	} else {
		return x;
	}
}

int main() {
	char *S = next();

	int l0, l1;
	l0 = l1 = 0;
	for (int i = 0; i < strlen(S); i++) {
		if (S[i] == '0') {
			l0++;
		} else {
			l1++;
		}
	}
	printf("%d\n", 2 * min(l0, l1));
	return 0;
}

