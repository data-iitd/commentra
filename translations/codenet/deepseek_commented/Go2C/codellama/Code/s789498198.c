
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Main function of the program
int main() {
	// Read two integers A and B from standard input
	int A, B;
	scanf("%d %d", &A, &B);

	// Check if the sum of A and B is even
	if ((A+B)%2 == 0) {
		// If even, print the average of A and B
		printf("%d\n", (A + B) / 2);
		return 0;
	}
	// If not even, print "IMPOSSIBLE"
	printf("IMPOSSIBLE\n");
	return 0;
}

