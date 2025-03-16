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

// Define constants for base and maximum size
#define B 13131
#define N 500000 + 7

// Declare global variables
int n; // Length of the input string
char s[N]; // Input string
u64 f[N]; // Array to store computed values based on the input string
int g[N]; // Array to store the shift values
std::map<u64, u64> map; // Map to count occurrences of computed values
u64 cnt; // Counter for the final result

// Function to compute power of a number with a given exponent
u64 pow(u64 a, u64 k) {
    // Adjust exponent if negative
    if (k < 0) k += (1llu << 63) - 1;
    u64 t = 1; // Initialize result
    // Exponentiation by squaring
    for (; k; a = a * a, k >>= 1)
        if (k & 1) t = t * a; // Multiply result if current bit is set
    return t; // Return computed power
}

int main() {
    // Uncomment the following lines to read from a file
    // freopen("code.in", "r", stdin);
    // freopen("code.out", "w", stdout);

    // Read input values: number of operations and the operations string
    scanf("%d%s", &n, s + 1);
    
    // Process each character in the input string
    for (int i = 1; i <= n; ++i) {
        // If the character is '+' or '-', update f and g arrays
        if (s[i] == '+' || s[i] == '-') {
            f[i] = f[i - 1] + (s[i] == '+'? 1 : -1) * pow(B, g[i] = g[i - 1]);
        } else {
            // If the character is '<' or '>', update f and g arrays accordingly
            f[i] = f[i - 1]; // No change in f
            g[i] = g[i - 1] + (s[i] == '<'? -1 : 1); // Update g based on direction
        }
    }

    // Iterate backwards through the string to count valid combinations
    for (int i = n; i; --i) {
        ++map[f[i]]; // Increment the count of the current f value
        // Update the counter with the number of valid combinations found
        cnt += map[f[n] * pow(B, g[i - 1]) + f[i - 1]];
    }

    // Output the final count of valid combinations
    printf("%lld\n", cnt);

    return 0; // End of the program
}

