#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b) {
	if (a < b) {
		return b;
	}
	return a;
}

int main() {
	char buf[1000];
	int A, B;
	scanf("%d %d", &A, &B);

	int mx = max(A + B, A - B);
	mx = max(mx, A * B);
	printf("%d\n", mx);

	return 0;
}
