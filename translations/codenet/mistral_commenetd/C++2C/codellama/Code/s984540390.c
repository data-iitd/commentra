#include <stdio.h>
#include <stdlib.h>

int main() {
	int h;
	long long ans, mx, sum, mn = 1e8, cnt = 1;

	scanf("%d", &h);

	while (h != 1) {
		if (h % 2 != 0) h--;
		h /= 2;
		cnt *= 2;
		ans += cnt;
	}

	printf("%lld\n", ans + 1);
}

