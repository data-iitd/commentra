#include <stdio.h>

int main() {
	// Declare three integer variables "a", "b", and "c"
	int a, b, c;

	// Read three integers from the standard input and assign them to the variables
	scanf("%d %d %d", &a, &b, &c);

	// Check if the difference between "b" and "a" is equal to the difference between "c" and "b"
	if (b-a == c-b) {
		// If the condition is true, print "YES" to the standard output
		printf("YES");
	} else {
		// If the condition is false, print "NO" to the standard output
		printf("NO");
	}

	// End of the code
}

