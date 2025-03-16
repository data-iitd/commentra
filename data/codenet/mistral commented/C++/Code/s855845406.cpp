
#include <iostream>

// Main function is the entry point of the program
int main() {
	// Declare and initialize two integer variables, N and A
	int N, A;
	std::cin >> N;	// Read the value of N from the standard input
	std::cin >> A;	// Read the value of A from the standard input

	// Calculate the result and print it to the standard output
	std::cout << N * N - A << std::endl;
}