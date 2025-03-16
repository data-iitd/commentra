
#include <stdio.h>

int solve(int a, int b, int c) {
	int temp_;
	// Check if c is equal to the sum of a and b
	if (c == a + b) {
		temp_ = b + c;
	} else if (c - 1 > a + b) { // Check if c-1 is greater than the sum of a and b
		int temp = (c - 1) - (a + b);
		temp_ = b + c - temp; // Calculate temp_ based on the difference
	} else { // If neither condition is met
		temp_ = b + c;
	}
	return temp_;
}

int main() {
	int a, b, c;
	scanf("%d %d %d\n", &a, &b, &c);

	int ans = solve(a, b, c);
	printf("%d\n", ans);
}

