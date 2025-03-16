#include <stdio.h>
#include <stdlib.h>

int scanInt() {
	int num;
	scanf("%d", &num);
	return num;
}

char* scanString() {
	char* str = (char*)malloc(sizeof(char) * 100);
	scanf("%s", str);
	return str;
}

int* scanInts(int n) {
	int* sl = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		sl[i] = scanInt();
	}
	return sl;
}

char** scanStrings(int n) {
	char** sl = (char**)malloc(sizeof(char*) * n);
	for (int i = 0; i < n; i++) {
		sl[i] = scanString();
	}
	return sl;
}

int main() {
	int r, D, x;
	r = scanInt();
	D = scanInt();
	x = scanInt();
	for (int i = 1; i <= 10; i++) {
		x = r*x - D;
		printf("%d\n", x);
	}
	return 0;
}

