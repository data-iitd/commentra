
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>
#include <float.h>
#include <time.h>
#include <ctype.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>
#include <errno.h>
#include <assert.h>
#include <setjmp.h>
#include <signal.h>
#include <fenv.h>
#include <complex.h>
#include <stdarg.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>
#include <float.h>
#include <time.h>
#include <ctype.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>
#include <errno.h>
#include <assert.h>
#include <setjmp.h>
#include <signal.h>
#include <fenv.h>
#include <complex.h>
#include <stdarg.h>
#include <inttypes.h>
#include <stdint.h>

const unsigned long long B = 13131; // Base number for exponentiation
const int N = 500000 + 7; // Maximum size of input string

int n; // Number of symbols in input string
char s[N]; // Input string
unsigned long long f[N]; // Intermediate result array
int g[N]; // Exponent array
unsigned long long map[N]; // Map to store intermediate results for faster calculation
unsigned long long cnt; // Final result

// Function to calculate B raised to the power of k
unsigned long long pow(unsigned long long a, unsigned long long k) {
	if (k < 0) k += (1llu << 63) - 1; // Handle negative exponents by converting them to positive
	unsigned long long t = 1; // Initialize result to 1
	for (; k; a = a * a, k >>= 1) // Calculate exponentiation using bitwise right shift and multiplication
		if (k & 1) t = t * a; // If the current bit is 1, add the current base to the result
	return t; // Return the result
}

int main() {
//	freopen("code.in", "r", stdin); // Uncomment to read input from a file
//	freopen("code.out", "w", stdout); // Uncomment to write output to a file

	scanf("%d%s", &n, s + 1); // Read the number of symbols and the input string from standard input

	// Initialize the first element of f and g arrays
	f[0] = 0;
	g[0] = 0;

	// Process each symbol in the input string
	for (int i = 1; i <= n; ++i) {
		// Update the current element of f array based on the current symbol
		if (s[i] == '+' || s[i] == '-')
			f[i] = f[i - 1] + (s[i] == '+'? 1 : -1) * pow(B, g[i] = g[i - 1]);
		// If the current symbol is not an operator, just copy the previous value of f to the current position
		else
			f[i] = f[i - 1], g[i] = g[i - 1] + (s[i] == '<'? -1 : 1);
	}

	// Calculate the final result
	for (int i = n; i; --i) {
		++map[f[i]]; // Increment the count of the intermediate result in the map
		cnt += map[f[n] * pow(B, g[i - 1]) + f[i - 1]]; // Add the contribution of the current symbol to the final result
	}

	printf("%lld\n", cnt); // Print the final result to standard output

	return 0;
}

