#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
	int m[] = {10, 50, 100, 500};
	int num[4];
	int sum = 0;
	bool first = true;
	int money;

	while(scanf("%d", &money) == 1) {
		if(!first)
			printf("\n");

		first = false;
		sum = 0;
		for(int i = 0; i < 4; ++i) {
			scanf("%d", &num[i]);
			sum += num[i] * m[i];
		}

		int change = sum - money;
		for(int i = 3; i >= 0; --i) {
			if(change / m[i]) {
				num[i] = num[i] - change / m[i];
				change %= m[i];
			}
		}

		for(int i = 0; i < 4; ++i)
			if(num[i] > 0)
				printf("%d %d\n", m[i], num[i]);
	}

	return EXIT_SUCCESS;
}

