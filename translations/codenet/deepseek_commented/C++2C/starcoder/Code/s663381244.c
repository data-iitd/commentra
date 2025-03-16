#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	setbuf(stdout, NULL);
	int m[4] = {10, 50, 100, 500};
	int num[4] = {0};
	int sum = 0;
	int change;
	int money;
	int i;
	while(scanf("%d", &money) == 1 && money) {
		if(sum)
			printf("\n");
		sum = 0;
		for(i = 0; i < 4; ++i) {
			scanf("%d", &num[i]);
			sum += num[i] * m[i];
		}
		change = sum - money;
		for(i = 3; i >= 0; --i) {
			if(change / m[i]) {
				num[i] = num[i] - change / m[i];
				change %= m[i];
			}
		}
		for(i = 0; i < 4; ++i)
			if(num[i] > 0)
				printf("%d %d\n", m[i], num[i]);
	}
	return EXIT_SUCCESS;
}

