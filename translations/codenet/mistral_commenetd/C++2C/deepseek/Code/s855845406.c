#include <stdio.h>

// Main function is the entry point of the program
int main() {
	// Declare and initialize two integer variables, N and A
	int N, A;
	scanf("%d", &N);	// Read the value of N from the standard input
	scanf("%d", &A);	// Read the value of A from the standard input

	// Calculate the result and print it to the standard output
	printf("%d\n", N * N - A);
}

