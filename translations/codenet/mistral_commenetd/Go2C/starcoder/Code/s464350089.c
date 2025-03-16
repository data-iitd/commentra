#include <stdio.h>
#include <stdlib.h>

int main() {
	// Reading the first two integers h and n
	int h = atoi(next());
	int n = atoi(next());

	// Initializing variable a to 0
	int a = 0;

	// Iterating through the array of size n and adding each integer to variable a
	for (int i = 0; i < n; i++) {
		a += atoi(next());
	}

	// Checking if h is less than or equal to the sum of all integers and printing the result accordingly.
	if (h > a) {
		printf("No\n");
	} else {
		printf("Yes\n");
	}
}

