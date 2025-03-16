
#include <stdio.h>
#include <math.h>

int main() {
	double n, k;
	scanf("%lf %lf", &n, &k);

	// Read two floating-point numbers, n and k, from standard input.
	// These represent the number to be converted and the base of the number system, respectively.

	// Calculate the number of digits in the base k representation of n.
	// The logic involves finding the smallest integer x such that k^x is less than or equal to n and n is less than k^(x+1).
	// Output x + 1 as the number of digits in the base k representation of n.

	double x = 0.0;
	while (1) {
		double under = pow(k, x);
		double upper = pow(k, x+1);

		if (under <= n && n < upper) {
			printf("%.0lf\n", x + 1);
			return 0;
		}
		x++;
	}
}

