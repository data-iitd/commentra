#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int n;
	scanf("%d", &n);
	double ans = 0.0;
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		ans += 1.0 / (double)tmp;
	}
	printf("%.10f\n", 1.0 / ans);
}

