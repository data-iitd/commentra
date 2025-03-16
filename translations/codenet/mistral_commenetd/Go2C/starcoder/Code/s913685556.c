#include <stdio.h>

int max(int a, int b) {
	return a > b? a : b;
}

int main() {
	int A, B;
	scanf("%d %d", &A, &B);
	int mx = max(A+B, A-B);
	mx = max(mx, A*B);
	printf("%d\n", mx);
}
