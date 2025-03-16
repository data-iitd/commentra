#include <stdio.h>

int main() {
	int m, f, r;

	while (scanf("%d %d %d", &m, &f, &r) == 3) {
		if (m == -1 || f == -1) {
			printf("F");
			continue;
		}

		if (m + f >= 80) {
			printf("A");
			continue;
		}

		if (m + f >= 65) {
			printf("B");
			continue;
		}

		if (m + f >= 50 || r >= 50) {
			printf("C");
			continue;
		}

		if (m + f >= 30) {
			printf("D");
			continue;
		}

		printf("F");
		printf("\n");
	}

	return 0;
}

