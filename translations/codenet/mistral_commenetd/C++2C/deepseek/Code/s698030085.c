#include <stdio.h> // We include the stdio library to use input and output streams

int main(void) { // The main function is the entry point of the program
	long long int a, b; // We declare two long long integers named a and b to store user input

	// We use the scanf function to read user input and store it in variables a and b
	scanf("%lld %lld", &a, &b);

	if ((a + b) % 2 == 0) { // We check if the sum of a and b is even
		// If the sum is even, we print the result by dividing it by 2
		printf("%lld\n", (a + b) / 2);
	} else { // If the sum is odd, we print "IMPOSSIBLE"
		printf("IMPOSSIBLE\n");
	}
}
