#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char buf[1000];
	int H, W, N;
	int A;
	int max(int a, int b);
	int nextInt(char *buf);
	int nextIntArray(char *buf);
	int nextInt64Array(char *buf);
	int nextMap(char *buf);
	int i;

	fgets(buf, 1000, stdin);
	H = nextInt(buf);
	W = nextInt(buf);
	N = nextInt(buf);

	A = max(H, W);

	printf("%d\n", (N + A - 1) / A);

	return 0;
}

int max(int a, int b) {
	if (a < b) {
		return b;
	}
	return a;
}

int nextInt(char *buf) {
	int i;
	for (i = 0; buf[i] != ' '; i++);
	return atoi(buf);
}

int nextIntArray(char *buf) {
	int i;
	int start = 0;
	int result[1000];
	for (i = 0; i < 1000; i++) {
		if (buf[i] == ' ' || buf[i] == '\0') {
			result[i] = atoi(buf + start);
			start = i + 1;
		}
	}
	return result[i];
}

int nextInt64Array(char *buf) {
	int i;
	int start = 0;
	int result[1000];
	for (i = 0; i < 1000; i++) {
		if (buf[i] == ' ' || buf[i] == '\0') {
			result[i] = atoi(buf + start);
			start = i + 1;
		}
	}
	return result[i];
}

int nextMap(char *buf) {
	int i;
	int start = 0;
	int result[1000];
	for (i = 0; i < 1000; i++) {
		if (buf[i] == ' ' || buf[i] == '\0') {
			result[i] = atoi(buf + start);
			start = i + 1;
		}
	}
	return result[i];
}

