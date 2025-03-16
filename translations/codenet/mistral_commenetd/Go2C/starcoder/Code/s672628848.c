#include <stdio.h>

int main() {
	int a, b, c, d, e;
	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
	int al[] = {a, b, c, d, e};
	for (int n = 0; n < 5; n++) {
		int i = al[n];
		if (i == 0) {
			printf("%d", n + 1);
			break;
		}
	}
	return 0;
}
