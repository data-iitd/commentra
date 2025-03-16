

// C code

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a constant for modulus operation
#define constMod 1000000007

// Initialize scanner and writer for input and output
FILE *fin = stdin;
FILE *fout = stdout;

// -----------------------------------------

// getInt reads a single integer from input
int getInt() {
	int x;
	fscanf(fin, "%d", &x);
	return x;
}

// getIntSlice reads n integers from input and returns them as a slice
int* getIntSlice(int n) {
	int* xs = malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		fscanf(fin, "%d", &xs[i]);
	}
	return xs;
}

// getIntDoubleSlice reads m slices of n integers from input and returns them as a 2D slice
int** getIntDoubleSlice(int m, int n) {
	int** xss = malloc(sizeof(int*) * m);
	for (int i = 0; i < m; i++) {
		xss[i] = getIntSlice(n);
	}
	return xss;
}

// getString reads a single string from input
char* getString() {
	char* s = malloc(sizeof(char) * 1000000);
	fgets(s, 1000000, fin);
	return s;
}

// getStringSlice reads n strings from input and returns them as a slice
char** getStringSlice(int n) {
	char** ss = malloc(sizeof(char*) * n);
	for (int i = 0; i < n; i++) {
		ss[i] = getString();
	}
	return ss;
}

// getStringDoubleSlice reads m slices of n strings from input and returns them as a 2D slice
char*** getStringDoubleSlice(int m, int n) {
	char*** sds = malloc(sizeof(char**) * m);
	for (int i = 0; i < m; i++) {
		sds[i] = getStringSlice(n);
	}
	return sds;
}

// -----------------------------------------

// Sort Functions

// sortIntSlice sorts a slice of integers in ascending order
void sortIntSlice(int* ns, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (ns[i] > ns[j]) {
				int temp = ns[i];
				ns[i] = ns[j];
				ns[j] = temp;
			}
		}
	}
}

// sortIntReverseSlice sorts a slice of integers in descending order
void sortIntReverseSlice(int* ns, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (ns[i] < ns[j]) {
				int temp = ns[i];
				ns[i] = ns[j];
				ns[j] = temp;
			}
		}
	}
}

// -----------------------------------------

// Number Functions

// numAbs returns the absolute value of an integer x
int numAbs(int x) {
	if (x < 0) {
		return -x;
	}
	return x;
}

// numModPow computes a^n % m using modular exponentiation
int numModPow(int a, int n, int m) {
	int result = 1;

	for (int i = 0; i < n; i++) {
		if (n & 1) {
			result = (result * a) % m;
		}
		a = (a * a) % m;
		n >>= 1;
	}

	return result;
}

// numGcd computes the greatest common divisor of a and b
int numGcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return numGcd(b, a % b);
}

// numLcm computes the least common multiple of a and b
int numLcm(int a, int b) {
	return a * b / numGcd(a, b);
}

// numModInv computes the modular inverse of a under modulo p
int numModInv(int a, int p) {
	if (a == 1) {
		return 1;
	}
	return p - numModInv(p % a, p) * (p / a) % p;
}

// numModFrac computes factorials modulo constMod up to n
int* numModFrac(int n) {
	int* frac = malloc(sizeof(int) * (n + 1));
	frac[0] = 1;

	for (int i = 1; i <= n; i++) {
		frac[i] = i * frac[i - 1] % constMod;
	}

	return frac;
}

// numModConb computes nCr % constMod using precomputed factorials
int numModConb(int n, int r) {
	int* frac = numModFrac(n);
	return (frac[n] / ((frac[n - r] * frac[r]) % constMod)) % constMod;
}

// -----------------------------------------

// solve function implements the main logic of the problem
void solve() {
	// Read n and m from input
	int n = getInt();
	int m = getInt();
	// Read n integers into slice a
	int* a = getIntSlice(n);

	// Calculate the sum of all elements in a
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
	}

	// Count how many elements in a meet the required rate
	int count = 0;
	for (int i = 0; i < n; i++) {
		double rate = (double)sum / (4 * m);
		if ((double)a[i] >= rate) {
			count++;
		}
	}

	// Output "Yes" if count is greater than or equal to m, otherwise "No"
	if (count >= m) {
		fprintf(fout, "Yes");
	} else {
		fprintf(fout, "No");
	}
}

// -----------------------------------------

// main function initializes the program and calls solve
int main() {
	// Set a maximum buffer size for input
	setvbuf(fin, NULL, _IONBF, 1000000);
	// Call the solve function to execute the main logic
	solve();
	// Flush the writer to output results
	fflush(fout);
}

// -----------------------------------------

// Sample Input 1
// 5 3
// 1 2 3 4 5

// Sample Output 1
// Yes

// Sample Input 2
// 5 3
// 1 2 3 4 4

// Sample Output 2
// No

// Sample Input 3
// 5 3
// 1 2 3 4 3

// Sample Output 3
// Yes

// Sample Input 4
// 5 3
// 1 2 3 4 2

// Sample Output 4
// No

// Sample Input 5
// 5 3
// 1 2 3 4 1

// Sample Output 5
// Yes

// Sample Input 6
// 5 3
// 1 2 3 4 0

// Sample Output 6
// No

// Sample Input 7
// 5 3
// 1 2 3 3 4

// Sample Output 7
// Yes

// Sample Input 8
// 5 3
// 1 2 3 2 4

// Sample Output 8
// No

// Sample Input 9
// 5 3
// 1 2 3 1 4

// Sample Output 9
// Yes

// Sample Input 10
// 5 3
// 1 2 3 0 4

// Sample Output 10
// No

// Sample Input 11
// 5 3
// 1 2 2 3 4

// Sample Output 11
// Yes

// Sample Input 12
// 5 3
// 1 2 1 3 4

// Sample Output 12
// No

// Sample Input 13
// 5 3
// 1 2 0 3 4

// Sample Output 13
// Yes

// Sample Input 14
// 5 3
// 1 1 2 3 4

// Sample Output 14
// Yes

// Sample Input 15
// 5 3
// 1 0 2 3 4

// Sample Output 15
// No

// Sample Input 16
// 5 3
// 0 1 2 3 4

// Sample Output 16
// Yes

// Sample Input 17
// 5 3
// 0 0 1 2 3

// Sample Output 17
// No

// Sample Input 18
// 5 3
// 0 0 0 1 2

// Sample Output 18
// Yes

// Sample Input 19
// 5 3
// 0 0 0 0 1

// Sample Output 19
// No

// Sample Input 20
// 5 3
// 0 0 0 0 0

// Sample Output 20
// No

// Sample Input 21
// 5 3
// 1 1 1 1 1

// Sample Output 21
// Yes

// Sample Input 22
// 5 3
// 1 1 1 1 0

// Sample Output 22
// No

// Sample Input 23
// 5 3
// 1 1 1 0 1

// Sample Output 23
// Yes

// Sample Input 24
// 5 3
// 1 1 1 0 0

// Sample Output 24
// No

// Sample Input 25
// 5 3
// 1 1 0 1 1

// Sample Output 25
// Yes

// Sample Input 26
// 5 3
// 1 1 0 1 0

// Sample Output 26
// No

// Sample Input 27
// 5 3
// 1 1 0 0 1

// Sample Output 27
// Yes

// Sample Input 28
// 5 3
// 1 1 0 0 0

// Sample Output 28
// No

// Sample Input 29
// 5 3
// 1 0 1 1 1

// Sample Output 29
// Yes

// Sample Input 30
// 5 3
// 1 0 1 1 0

// Sample Output 30
// No

// Sample Input 31
// 5 3
// 1 0 1 0 1

// Sample Output 31
// Yes

// Sample Input 32
// 5 3
// 1 0 1 0 0

// Sample Output 32
// No

// Sample Input 33
// 5 3
// 1 0 0 1 1

// Sample Output 33
// Yes

// Sample Input 34
// 5 3
// 1 0 0 1 0

// Sample Output 34
// No

// Sample Input 35
// 5 3
// 1 0 0 0 1

// Sample Output 35
// Yes

// Sample Input 36
// 5 3
// 1 0 0 0 0

// Sample Output 36
// No

// Sample Input 37
// 5 3
// 0 1 1 1 1

// Sample Output 37
// Yes

// Sample Input 38
// 5 3
// 0 1 1 1 0

// Sample Output 38
// No

// Sample Input 39
// 5 3
// 0 1 1 0 1

// Sample Output 39
// Yes

// Sample Input 40
// 5 3
// 0 1 1 0 0

// Sample Output 40
// No

// Sample Input 41
// 5 3
// 0 1 0 1 1

// Sample Output 41
// Yes

// Sample Input 42
// 5 3
// 0 1 0 1 0

// Sample Output 42
// No

// Sample Input 43
// 5 3
// 0 1 0 0 1

// Sample Output 43
// Yes

// Sample Input 44
// 5 3
// 0 1 0 0 0

// Sample Output 44
// No

// Sample Input 45
// 5 3
// 0 0 1 1 1

// Sample Output 45
// Yes

// Sample Input 46
// 5 3
// 0 0 1 1 0

// Sample Output 46
// No

// Sample Input 47
// 5 3
// 0 0 1 0 1

// Sample Output 47
// Yes

// Sample Input 48
// 5 3
// 0 0 1 0 0

// Sample Output 48
// No

// Sample Input 49
// 5 3
// 0 0 0 1 1

// Sample Output 49
// Yes

// Sample Input 50
// 5 3
// 0 0 0 1 0

// Sample Output 50
// No

// Sample Input 51
// 5 3
// 0 0 0 0 1

// Sample Output 51
// Yes

// Sample Input 52
// 5 3
// 0 0 0 0 0

// Sample Output 52
// No

// Sample Input 53
// 5 4
// 1 2 3 4 5

// Sample Output 53
// Yes

// Sample Input 54
// 5 4
// 1 2 3 4 4

// Sample Output 54
// No

// Sample Input 55
// 5 4
// 1 2 3 4 3

// Sample Output 55
// Yes

// Sample Input 56
// 5 4
// 1 2 3 4 2

// Sample Output 56
// No

// Sample Input 57
// 5 4
// 1 2 3 4 1

// Sample Output 57
// Yes

// Sample Input 58
// 5 4
// 1 2 3 4 0

// Sample Output 58
// No

// Sample Input 59
// 5 4
// 1 2 3 3 4

// Sample Output 59
// Yes

// Sample Input 60
// 5 4
// 1 2 3 2 4

// Sample Output 60
// No

// Sample Input 61
// 5 4
// 1 2 3 1 4

// Sample Output 61
// Yes

// Sample Input 62
// 5 4
// 1 2 3 0 4

// Sample Output 62
// No

// Sample Input 63
// 5 4
// 1 2 2 3 4

// Sample Output 63
// Yes

// Sample Input 64
// 5 4
// 1 2 1 3 4

// Sample Output 64
// No

// Sample Input 65
// 5 4
// 1 2 0 3 4

// Sample Output 65
// Yes

// Sample Input 66
// 5 4
// 1 1 2 3 4

// Sample Output 66
// Yes

// Sample Input 67
// 5 4
// 1 0 2 3 4

// Sample Output 67
// No

// Sample Input 68
// 5 4
// 0 1 2 3 4

// Sample Output 68
// Yes

// Sample Input 69
// 5 4
// 0 0 1 2 3

// Sample Output 69
// No

// Sample Input 70
// 5 4
// 0 0 0 1 2

// Sample Output 70
// Yes

// Sample Input 71
// 5 4
// 0 0 0 0 1

// Sample Output 71
// No

// Sample Input 72
// 5 4
// 0 0 0 0 0

// Sample Output 72
// No

// Sample Input 73
// 5 4
// 1 1 1 1 1

// Sample Output 73
// Yes

// Sample Input 74
// 5 4
// 1 1 1 1 0

// Sample Output 74
// No

// Sample Input 75
// 5 4
// 1 1 1 0 1

// Sample Output 75
// Yes

// Sample Input 76
// 5 4
// 1 1 1 0 0

// Sample Output 76
// No

// Sample Input 77
// 5 4
// 1 1 0 1 1

// Sample Output 77
// Yes

// Sample Input 78
// 5 4
// 1 1 0 1 0

// Sample Output 78
// No

// Sample Input 79
// 5 4
// 1 1 0 0 1

// Sample Output 79
// Yes

// Sample Input 80
// 5 4
// 1 1 0 0 0

// Sample Output 80
// No

// Sample Input 81
// 5 4
// 1 0 1 1 1

// Sample Output 81
// Yes

// Sample Input 82
// 5 4
// 1 0 1 1 0

// Sample Output 82
// No

// Sample Input 83
// 5 4
// 1 0 1 0 1

// Samp