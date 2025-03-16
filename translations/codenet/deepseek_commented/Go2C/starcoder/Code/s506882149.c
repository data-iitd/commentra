#include <stdio.h>

// comp takes two integers x and a as input and returns an integer.
// It returns 0 if x is less than a, otherwise it returns 10.
int comp(int x, int a) {
	if (x < a) { // Check if x is less than a
		return 0;
	}
	return 10; // Return 10 if x is not less than a
}

int main() {
	int x, a;
	scanf("%d %d", &x, &a); // Read two integers from standard input

	printf("%d\n", comp(x, a)); // Call the comp function with x and a, and print the result
}
