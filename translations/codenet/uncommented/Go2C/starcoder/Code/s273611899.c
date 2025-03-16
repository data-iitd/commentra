#include <stdio.h>

int main() {
	int n, x, c, i, j, k;

	while(1) {
		scanf("%d %d", &n, &x);
		if(n == 0 && x == 0) {
			break;
		}

		c = 0;
		for(i = 1; i <= n-2; i++) {
			for(j = i + 1; j <= n-1; j++) {
				for(k = j + 1; k <= n; k++) {
					if(i+j+k == x) {
						c++;
					}
				}
			}
		}
		printf("%d\n", c);
	}
}
