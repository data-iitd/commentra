#include <stdio.h>

int main() {
	int a, b, c, d, e;
	int al[5];

	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);

	al[0] = a;
	al[1] = b;
	al[2] = c;
	al[3] = d;
	al[4] = e;

	for (int n = 0; n < 5; n++) {
		if (al[n] == 0) {
			printf("%d\n", n + 1);
			break;
		}
	}

	return 0;
}

