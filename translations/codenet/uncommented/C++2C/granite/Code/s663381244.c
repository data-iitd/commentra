
#include <stdio.h>
#include <stdlib.h>

int main() {
	int m[4] = {10, 50, 100, 500};
	bool first = true;
	while(1) {
		int money;
		if(scanf("%d", &money)!= 1 || money == 0)
			break;

		if(!first)
			puts("");

		first = false;
		int sum = 0;
		int num[4];
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

	return 0;
}

