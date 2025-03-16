
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main() {
	int n;
	scanf("%d", &n);
	int rt = (int)sqrt(n);
	int minf = 100;
	for (int i = 1; i < rt+1; i++) {
		if (n % i == 0) {
			int b = n / i;
			int ndigit = 0;
			for (; b > 0; b /= 10) {
				ndigit++;
			}
			minf = min(minf, ndigit);
		}
	}
	printf("%d\n", minf);
	return 0;
}

int min(int i, int j) {
	if (i > j) {
		return j;
	}
	return i;
}

