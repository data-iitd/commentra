#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define mod 1000000007

// 1MB
#define ioBufferSize 1 * 1024 * 1024

int main() {
	char buf[ioBufferSize];
	char *p = buf;
	char *end = buf + ioBufferSize;
	char *line = NULL;
	size_t line_size = 0;
	ssize_t line_len = 0;

	int h, n;
	int a = 0;

	line = fgets(buf, ioBufferSize, stdin);
	if (line == NULL) {
		return 1;
	}
	h = atoi(line);

	line = fgets(buf, ioBufferSize, stdin);
	if (line == NULL) {
		return 1;
	}
	n = atoi(line);

	for (int i = 0; i < n; i++) {
		line = fgets(buf, ioBufferSize, stdin);
		if (line == NULL) {
			return 1;
		}
		a += atoi(line);
	}

	if (h > a) {
		printf("No\n");
	} else {
		printf("Yes\n");
	}

	return 0;
}

