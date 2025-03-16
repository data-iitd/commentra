#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int readInt() {
	int i;
	scanf("%d", &i);
	return i;
}

float readFloat64() {
	float f;
	scanf("%f", &f);
	return f;
}

char* readString() {
	char* s = (char*)malloc(sizeof(char) * 100);
	scanf("%s", s);
	return s;
}

int main() {
	int n, m;
	n = readInt();
	m = readInt();
	int* a = (int*)malloc(sizeof(int) * n);
	int sum = 0;
	for (int i = 0; i < m; i++) {
		a[i] = readInt();
		sum += a[i];
	}
	if (sum > n) {
		printf("-1\n");
		return 0;
	}

	printf("%d\n", n - sum);
	return 0;
}

