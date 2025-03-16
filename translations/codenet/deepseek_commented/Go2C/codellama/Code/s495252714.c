
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define the constant for modular arithmetic.
const int mod = 1000000007;

// Function to perform modular exponentiation.
int modpow(int a, int n) {
	int res = 1;
	for (n>0) {
		if (n&1 == 1) {
			res = res*a%mod;
		}
		a = a*a%mod;
		n= n>>1;
	}
	return res;
}

// The main function of the program.
int main() {
	// Read the number of elements.
	int n = scanInt();

	// Read n integers into a slice.
	int *c = (int *)malloc(n*sizeof(int));
	for (int i = 0; i < n; i++) {
		c[i] = scanInt();
	}

	// Initialize the answer variable.
	int ans = 0;

	// Sort the slice of integers.
	qsort(c, n, sizeof(int), compare);

	// Calculate the answer based on the sorted slice.
	for (int i = 0; i < n; i++) {
		ans = (ans+(n+1-i)*c[i]%mod)%mod;
	}

	// Print the final answer, multiplied by 4^(n-1) modulo mod.
	printf("%d\n", ans*modpow(4,n-1)%mod);

	// Free the memory allocated for the slice.
	free(c);

	return 0;
}

// Function to compare two integers.
int compare(const void *a, const void *b) {
	return (*(int *)a - *(int *)b);
}

// Function to scan an integer from input.
int scanInt() {
	int a;
	scanf("%d", &a);
	return a;
}

// Function to print a list of integers, separated by spaces.
void printInts(int n, int *a) {
	for (int i = 0; i < n; i++) {
		printf("%d", a[i]);
		if (i != n-1) {
			printf(" ");
		}
	}
	printf("\n");
}

