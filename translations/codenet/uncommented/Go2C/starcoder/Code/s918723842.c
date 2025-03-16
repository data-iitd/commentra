#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int H, W, N;
	scanf("%d %d %d", &H, &W, &N);

	int A = (H > W)? H : W;

	printf("%d\n", (N + A - 1) / A);
}
