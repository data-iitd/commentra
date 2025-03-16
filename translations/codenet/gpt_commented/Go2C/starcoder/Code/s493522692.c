

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Utility functions for input and mathematical operations

// nextStr reads the next string from input
char* nextStr() {
	char* s = NULL;
	size_t len = 0;
	getline(&s, &len, stdin);
	return s;
}

// nextInt reads the next integer from input
int nextInt() {
	int n = 0;
	scanf("%d", &n);
	return n;
}

// maxInt returns the maximum of two integers
int maxInt(int a, int b) {
	if (a > b) {
		return a;
	} else {
		return b;
	}
}

// minInt returns the minimum of two integers
int minInt(int a, int b) {
	if (a > b) {
		return b;
	} else {
		return a;
	}
}

// absInt returns the absolute value of an integer
int absInt(int a) {
	if (a >= 0) {
		return a;
	} else {
		return -a;
	}
}

// absFloat64 returns the absolute value of a float64
double absFloat64(double a) {
	if (a >= 0) {
		return a;
	} else {
		return -a;
	}
}

// maxFloat64 returns the maximum of two float64 values
double maxFloat64(double a, double b) {
	if (a > b) {
		return a;
	} else {
		return b;
	}
}

// minFloat64 returns the minimum of two float64 values
double minFloat64(double a, double b) {
	if (a > b) {
		return b;
	} else {
		return a;
	}
}

// str2Int converts a string to an integer
int str2Int(char* s) {
	int n = 0;
	sscanf(s, "%d", &n);
	return n;
}

// reverse returns the reversed string
char* reverse(char* s) {
	char* r = (char*)malloc(sizeof(char) * (strlen(s) + 1));
	int i = 0;
	int j = strlen(s) - 1;
	while (i < j) {
		r[i] = s[j];
		r[j] = s[i];
		i++;
		j--;
	}
	r[i] = '\0';
	return r;
}

// powInt calculates p raised to the power of q
int powInt(int p, int q) {
	return (int)pow(p, q);
}

// isPrime checks if a number is prime
int isPrime(int x) {
	if (x == 1) {
		return 0;
	}
	if (x == 2) {
		return 1;
	}
	if (x%2 == 0) {
		return 0;
	}

	int rootx = (int)sqrt(x);
	int i = 3;
	while (i <= rootx) {
		if (x%i == 0) {
			return 0;
		}
		i += 2;
	}
	return 1;
}

// PrimeFactors returns the prime factors of a number
int* PrimeFactors(int n, int* len) {
	// Get the number of 2s that divide n
	int* pfs = (int*)malloc(sizeof(int) * 100);
	int i = 0;
	while (n%2 == 0) {
		pfs[i] = 2;
		i++;
		n = n / 2;
	}

	// n must be odd at this point, so we can skip one element
	for (int i = 3; i*i <= n; i = i + 2) {
		// while i divides n, append i and divide n
		while (n%i == 0) {
			pfs[i] = i;
			i++;
			n = n / i;
		}
	}

	// Handle the case when n is a prime number greater than 2
	if (n > 2) {
		pfs[i] = n;
		i++;
	}

	*len = i;
	return pfs;
}

// PrimeFactorsMap returns a map of prime factors and their counts
int* PrimeFactorsMap(int n, int* len) {
	int* pfs = (int*)malloc(sizeof(int) * 100);
	int i = 0;
	// Get the number of 2s that divide n
	while (n%2 == 0) {
		pfs[i] = 2;
		i++;
		n = n / 2;
	}

	// n must be odd at this point, so we can skip one element
	for (int i = 3; i*i <= n; i = i + 2) {
		// while i divides n, append i and divide n
		while (n%i == 0) {
			pfs[i] = i;
			i++;
			n = n / i;
		}
	}

	// Handle the case when n is a prime number greater than 2
	if (n > 2) {
		pfs[i] = n;
		i++;
	}

	*len = i;
	return pfs;
}

// sumInts returns the sum of a slice of integers
int sumInts(int* x, int len) {
	int total = 0;
	for (int i = 0; i < len; i++) {
		total += x[i];
	}
	return total;
}

// gcd calculates the greatest common divisor of two integers
int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a%b);
}

// lcm calculates the least common multiple of two integers
int lcm(int x, int y) {
	return x * y / gcd(x, y);
}

// Main function
int main() {
	// Read the number of 'S' and 'c'
	int N = nextInt();
	int M = nextInt();
	int tmp = minInt(N, M/2); // Calculate the minimum of N and half of M
	int ans = 0;
	ans += tmp; // Add the temporary value to the answer
	N -= tmp; // Decrease N by the temporary value
	M -= tmp * 2; // Decrease M by twice the temporary value
	// Output the final answer, which includes the remaining M divided by 4
	printf("%d\n", ans + M/4);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Utility functions for input and mathematical operations

// nextStr reads the next string from input
char* nextStr() {
	char* s = NULL;
	size_t len = 0;
	getline(&s, &len, stdin);
	return s;
}

// nextInt reads the next integer from input
int nextInt() {
	int n = 0;
	scanf("%d", &n);
	return n;
}

// maxInt returns the maximum of two integers
int maxInt(int a, int b) {
	if (a > b) {
		return a;
	} else {
		return b;
	}
}

// minInt returns the minimum of two integers
int minInt(int a, int b) {
	if (a > b) {
		return b;
	} else {
		return a;
	}
}

// absInt returns the absolute value of an integer
int absInt(int a) {
	if (a >= 0) {
		return a;
	} else {
		return -a;
	}
}

// absFloat64 returns the absolute value of a float64
double absFloat64(double a) {
	if (a >= 0) {
		return a;
	} else {
		return -a;
	}
}

// maxFloat64 returns the maximum of two float64 values
double maxFloat64(double a, double b) {
	if (a > b) {
		return a;
	} else {
		return b;
	}
}

// minFloat64 returns the minimum of two float64 values
double minFloat64(double a, double b) {
	if (a > b) {
		return b;
	} else {
		return a;
	}
}

// str2Int converts a string to an integer
int str2Int(char* s) {
	int n = 0;
	sscanf(s, "%d", &n);
	return n;
}

// reverse returns the reversed string
char* reverse(char* s) {
	char* r = (char*)malloc(sizeof(char) * (strlen(s) + 1));
	int i = 0;
	int j = strlen(s) - 1;
	while (i < j) {
		r[i] = s[j];
		r[j] = s[i];
		i++;
		j--;
	}
	r[i] = '\0';
	return r;
}

// powInt calculates p raised to the power of q
int powInt(int p, int q) {
	return (int)pow(p, q);
}

// isPrime checks if a number is prime
int isPrime(int x) {
	if (x == 1) {
		return 0;
	}
	if (x == 2) {
		return 1;
	}
	if (x%2 == 0) {
		return 0;
	}

	int rootx = (int)sqrt(x);
	int i = 3;
	while (i <= rootx) {
		if (x%i == 0) {
			return 0;
		}
		i += 2;
	}
	return 1;
}

// PrimeFactors returns the prime factors of a number
int* PrimeFactors(int n, int* len) {
	// Get the number of 2s that divide n
	int* pfs = (int*)malloc(sizeof(int) * 100);
	int i = 0;
	while (n%2 == 0) {
		pfs[i] = 2;
		i++;
		n = n / 2;
	}

	// n must be odd at this point, so we can skip one element
	for (int i = 3; i*i <= n; i = i + 2) {
		// while i divides n, append i and divide n
		while (n%i == 0) {
			pfs[i] = i;
			i++;
			n = n / i;
		}
	}

	// Handle the case when n is a prime number greater than 2
	if (n > 2) {
		pfs[i] = n;
		i++;
	}

	*len = i;
	return pfs;
}

// PrimeFactorsMap returns a map of prime factors and their counts
int* PrimeFactorsMap(int n, int* len) {
	int* pfs = (int*)malloc(sizeof(int) * 100);
	int i = 0;
	// Get the number of 2s that divide n
	while (n%2 == 0) {
		pfs[i] = 2;
		i++;
		n = n / 2;
	}

	// n must be odd at this point, so we can skip one element
	for (int i = 3; i*i <= n; i = i + 2) {
		// while i divides n, append i and divide n
		while (n%i == 0) {
			pfs[i] = i;
			i++;
			n = n / i;
		}
	}

	// Handle the case when n is a prime number greater than 2
	if (n > 2) {
		pfs[i] = n;
		i++;
	}

	*len = i;
	return pfs;
}

// sumInts returns the sum of a slice of integers
int sumInts(int* x, int len) {
	int total = 0;
	for (int i = 0; i < len; i++) {
		total += x[i];
	}
	return total;
}

// gcd calculates the greatest common divisor of two integers
int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a%b);
}

// lcm calculates the least common multiple of two integers
int lcm(int x, int y) {
	return x * y / gcd(x, y);
}

// Main function
int main() {
	// Read the number of 'S' and 'c'
	int N = nextInt();
	int M = nextInt();
	int tmp = minInt(N, M/2); // Calculate the minimum of N and half of M
	int ans = 0;
	ans += tmp; // Add the temporary value to the answer
	N -= tmp; // Decrease N by the temporary value
	M -= tmp * 2; // Decrease M by twice the temporary value
	// Output the final answer, which includes the remaining M divided by 4
	printf("%d\n", ans + M/4);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Utility functions for input and mathematical operations

// nextStr reads the next string from input
char* nextStr() {
	char* s = NULL;
	size_t len = 0;
	getline(&s, &len, stdin);
	return s;
}

// nextInt reads the next integer from input
int nextInt() {
	int n = 0;
	scanf("%d", &n);
	return n;
}

// maxInt returns the maximum of two integers
int maxInt(int a, int b) {
	if (a > b) {
		return a;
	} else {
		return b;
	}
}

// minInt returns the minimum of two integers
int minInt(int a, int b) {
	if (a > b) {
		return b;
	} else {
		return a;
	}
}

// absInt returns the absolute value of an integer
int absInt(int a) {
	if (a >= 0) {
		return a;
	} else {
		return -a;
	}
}

// absFloat64 returns the absolute value of a float64
double absFloat64(double a) {
	if (a >= 0) {
		return a;
	} else {
		return -a;
	}
}

// maxFloat64 returns the maximum of two float64 values
double maxFloat64(double a, double b) {
	if (a > b) {
		return a;
	} else {
		return b;
	}
}

// minFloat64 returns the minimum of two float64 values
double minFloat64(double a, double b) {
	if (a > b) {
		return b;
	} else {
		return a;
	}
}

// str2Int converts a string to an integer
int str2Int(char* s) {
	int n = 0;
	sscanf(s, "%d", &n);
	return n;
}

// reverse returns the reversed string
char* reverse(char* s) {
	char* r = (char*)malloc(sizeof(char) * (strlen(s) + 1));
	int i = 0;
	int j = strlen(s) - 1;
	while (i < j) {
		r[i] = s[j];
		r[j] = s[i];
		i++;
		j--;
	}
	r[i] = '\0';
	return r;
}

// powInt calculates p raised to the power of q
int powInt(int p, int q) {
	return (int)pow(p, q);
}

// isPrime checks if a number is prime
int isPrime(int x) {
	if (x == 1) {
		return 0;
	}
	if (x == 2) {
		return 1;
	}
	if (x%2 == 0) {
		return 0;
	}

	int rootx = (int)sqrt(x);
	int i = 3;
	while (i <= rootx) {
		if (x%i == 0) {
			return 0;
		}
		i += 2;
	}
	return 1;
}

// PrimeFactors returns the pri