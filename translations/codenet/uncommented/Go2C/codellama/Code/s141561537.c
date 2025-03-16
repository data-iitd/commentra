#include <stdio.h>

int main() {
	int a, b, c, x, sum;
	scanf("%d %d %d %d", &a, &b, &c, &x);
	for (int i = 0; i <= a; i++) {
		for (int j = 0; j <= b; j++) {
			for (int k = 0; k <= c; k++) {
				if (500*i+100*j+50*k == x) {
					sum++;
				}
			}
		}
	}
	printf("%d\n", sum);
	return 0;
}
