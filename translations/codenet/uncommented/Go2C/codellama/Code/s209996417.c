#include <stdio.h>
#include <math.h>

int main() {
	double n, k;
	scanf("%lf %lf", &n, &k);

	double x = 0.0;
	for (;;) {
		double under = pow(k, x);
		double upper = pow(k, x+1);

		if (under <= n && n < upper) {
			printf("%.0lf\n", x+1);
			return 0;
		}
		x++;
	}

	// 