#include <stdio.h>
#include <stdlib.h>

int main()
{
	// Initialize three integer variables 'a', 'b', and 'c'
	int a, b, c;

	// Read values of 'a', 'b', and 'c' from the standard input
	scanf("%d %d %d", &a, &b, &c);

	// Check if the given condition is true
	if ((100*a + 10*b + c) % 4 == 0) {
		// If the condition is true, print 'YES' to the standard output
		printf("YES\n");
	}
	else {
		// If the condition is false, print 'NO' to the standard output
		printf("NO\n");
	}

	// End of code
	return 0;
}

