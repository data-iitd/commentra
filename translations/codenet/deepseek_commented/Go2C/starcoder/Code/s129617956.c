#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	// Read an integer n from the standard input
	int n = nextInt();
	
	// Calculate the square root of n and store it in rt
	int rt = (int) sqrt(n);
	
	// Initialize minf to 100, which will hold the minimum number of digits
	int minf = 100;
	
	// Iterate from 1 to rt + 1 to find divisors of n
	for (int i = 1; i < rt+1; i++) {
		if (n % i == 0) {
			// If i is a divisor of n, calculate the quotient b
			int b = n / i;
			
			// Count the number of digits in b
			int ndigit = 0;
			while (b > 0) {
				b /= 10;
				ndigit++;
			}
			
			// Update minf with the minimum number of digits found
			minf = min(minf, ndigit);
		}
	}
	
	// Print the minimum number of digits
	printf("%d\n", minf);
}

const int size = 1000000;

char buffer[size];

// Read a line from the standard input
char* nextLine() {
	fgets(buffer, size, stdin);
	return buffer;
}

// Read an integer from the standard input
int nextInt() {
	int n;
	scanf("%d", &n);
	return n;
}

// Return the minimum of two integers
int min(int i, int j) {
	if (i > j) {
		return j;
	}
	return i;
}

