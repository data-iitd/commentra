#include <stdio.h>
int main(void) {
	long long int a, b;
	scanf("%lld %lld", &a, &b);
	if ((a + b) % 2 == 0) {
		printf("%lld\n", (a + b) / 2);
	} else {
		printf("IMPOSSIBLE\n");
	}
}
