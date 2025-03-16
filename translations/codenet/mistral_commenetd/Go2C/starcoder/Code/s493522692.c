// Util functions
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Util functions
char* nextStr() {
	// Scans the next token, a rune, into sc.Text().
	scanf("%s", sc.Text());
	// Returns the text scanned into sc.Text() as a string.
	return sc.Text();
}

// With a comment explaining what the function does:
// Scans the next token, a rune, into sc.Text() and returns it as a string.
char* nextStr() {
	// Scans the next token, a rune, into sc.Text().
	scanf("%s", sc.Text());
	// Returns the text scanned into sc.Text() as a string.
	return sc.Text();
}

int nextInt() {
	// Scans the next token, a string, into sc.Text().
	// Converts the string to an integer using atoi() and returns it.
	int i = atoi(sc.Text());
	if (e := recover(); e!= nil) {
		panic(e);
	}
	return i;
}

// With a comment explaining what the function does:
// Scans the next token, a string, into sc.Text() and converts it to an integer.
int nextInt() {
	// Scans the next token, a string, into sc.Text().
	scanf("%s", sc.Text());
	// Converts the string to an integer using atoi().
	int i = atoi(sc.Text());
	// Recovers from any panic that might occur during the conversion.
	if (e := recover(); e!= nil) {
		panic(e);
	}
	// Returns the integer.
	return i;
}

// Helper functions for mathematical operations
int maxInt(int a, int b) {
	// Returns the maximum of two integers.
	if (a > b) {
		return a;
	} else {
		return b;
	}
}

// With a comment explaining what the function does:
// Returns the maximum of two integers.
int maxInt(int a, int b) {
	// If 'a' is greater than 'b', return 'a'.
	if (a > b) {
		return a;
	} else {
		// Otherwise, return 'b'.
		return b;
	}
}

int minInt(int a, int b) {
	// Returns the minimum of two integers.
	if (a > b) {
		return b;
	} else {
		return a;
	}
}

// With a comment explaining what the function does:
// Returns the minimum of two integers.
int minInt(int a, int b) {
	// If 'a' is greater than 'b', return 'b'.
	if (a > b) {
		return b;
	} else {
		// Otherwise, return 'a'.
		return a;
	}
}

int absInt(int a) {
	// Returns the absolute value of an integer.
	if (a >= 0) {
		return a;
	} else {
		return -a;
	}
}

// With a comment explaining what the function does:
// Returns the absolute value of an integer.
int absInt(int a) {
	// If the integer is non-negative, return it as is.
	if (a >= 0) {
		return a;
	} else {
		// Otherwise, return the negative of the integer.
		return -a;
	}
}

float maxFloat64(float a, float b) {
	// Returns the maximum of two floating-point numbers.
	if (a > b) {
		return a;
	} else {
		return b;
	}
}

// With a comment explaining what the function does:
// Returns the maximum of two floating-point numbers.
float maxFloat64(float a, float b) {
	// If 'a' is greater than 'b', return 'a'.
	if (a > b) {
		return a;
	} else {
		// Otherwise, return 'b'.
		return b;
	}
}

float minFloat64(float a, float b) {
	// Returns the minimum of two floating-point numbers.
	if (a > b) {
		return b;
	} else {
		return a;
	}
}

// With a comment explaining what the function does:
// Returns the minimum of two floating-point numbers.
float minFloat64(float a, float b) {
	// If 'a' is greater than 'b', return 'b'.
	if (a > b) {
		return b;
	} else {
		// Otherwise, return 'a'.
		return a;
	}
}

int str2Int(char* s) {
	// Converts a string to an integer.
	int n = atoi(s);
	return n;
}

// With a comment explaining what the function does:
// Converts a string to an integer.
int str2Int(char* s) {
	// Attempts to convert the string to an integer using atoi().
	int n = atoi(s);
	// Returns the integer.
	return n;
}

char* reverse(char* s) {
	// Reverses a given string.
	char* r = malloc(sizeof(char) * strlen(s));
	int i = 0;
	int j = strlen(s) - 1;
	while (i < j) {
		r[i] = s[j];
		r[j] = s[i];
		i++;
		j--;
	}
	return r;
}

// With a comment explaining what the function does:
// Reverses a given string.
char* reverse(char* s) {
	// Initializes a rune slice with the given string.
	char* r = malloc(sizeof(char) * strlen(s));
	int i = 0;
	int j = strlen(s) - 1;
	while (i < j) {
		r[i] = s[j];
		r[j] = s[i];
		i++;
		j--;
	}
	return r;
}

int powInt(int p, int q) {
	// Calculates 'p' raised to the power of 'q'.
	return pow(p, q);
}

// With a comment explaining what the function does:
// Calculates 'p' raised to the power of 'q'.
int powInt(int p, int q) {
	// Calculates 'p' raised to the power of 'q' using the pow() function.
	return pow(p, q);
}

int isPrime(int x) {
	// Checks if a given number is prime.
	if (x == 1) {
		// 1 is not a prime number.
		return 0;
	}
	if (x == 2) {
		// 2 is a prime number.
		return 1;
	}
	// If the number is even, it's not a prime number.
	if (x%2 == 0) {
		return 0;
	}

	// Iterates through the numbers from 3 to the square root of 'x'.
	int rootx = sqrt(x);
	int i = 3;
	// Checks if any of the numbers from 3 to the square root of 'x' divide 'x'.
	while (i <= rootx) {
		// If 'x' is divisible by the current number, it's not a prime number.
		if (x%i == 0) {
			return 0;
		}
		// Increment the current number by 2 to check the next odd number.
		i += 2;
	}
	// Returns the result.
	return 1;
}

// With a comment explaining what the function does:
// Checks if a given number is prime.
int isPrime(int x) {
	// If the number is 1, it's not a prime number.
	if (x == 1) {
		return 0;
	}
	// If the number is 2, it's a prime number.
	if (x == 2) {
		return 1;
	}
	// If the number is even, it's not a prime number.
	if (x%2 == 0) {
		return 0;
	}

	// Iterates through the numbers from 3 to the square root of 'x'.
	int rootx = sqrt(x);
	int i = 3;
	// Checks if any of the numbers from 3 to the square root of 'x' divide 'x'.
	while (i <= rootx) {
		// If 'x' is divisible by the current number, it's not a prime number.
		if (x%i == 0) {
			return 0;
		}
		// Increment the current number by 2 to check the next odd number.
		i += 2;
	}
	// Returns the result.
	return 1;
}

int* PrimeFactors(int n, int* pfs) {
	// Finds the prime factors of a given number.
	// Get the number of 2s that divide n
	while (n%2 == 0) {
		// Appends 2 to the result slice.
		*pfs = append(*pfs, 2);
		// Divides n by 2.
		n = n / 2;
	}

	// n must be odd at this point. so we can skip one element
	// (note i = i + 2)
	int i = 3;
	while (i*i <= n) {
		// While i divides n, appends i to the result slice and divides n by i.
		while (n%i == 0) {
			*pfs = append(*pfs, i);
			n = n / i;
		}
		// Increment the current number by 2 to check the next odd number.
		i += 2;
	}

	// This condition is to handle the case when n is a prime number
	// greater than 2
	if (n > 2) {
		// Appends n to the result slice.
		*pfs = append(*pfs, n);
	}

	// Returns the result.
	return pfs;
}

// With a comment explaining what the function does:
// Finds the prime factors of a given number.
int* PrimeFactors(int n, int* pfs) {
	// Initializes an empty result slice.
	*pfs = make([]int, 0);

	// Get the number of 2s that divide n
	while (n%2 == 0) {
		// Appends 2 to the result slice.
		*pfs = append(*pfs, 2);
		// Divides n by 2.
		n = n / 2;
	}

	// n must be odd at this point. so we can skip one element
	// (note i = i + 2)
	int i = 3;
	while (i*i <= n) {
		// While i divides n, appends i to the result slice and divides n by i.
		while (n%i == 0) {
			*pfs = append(*pfs, i);
			n = n / i;
		}
		// Increment the current number by 2 to check the next odd number.
		i += 2;
	}

	// This condition is to handle the case when n is a prime number
	// greater than 2
	if (n > 2) {
		// Appends n to the result slice.
		*pfs = append(*pfs, n);
	}

	// Returns the result.
	return pfs;
}

int* PrimeFactorsMap(int n, int* pfs) {
	// Finds the prime factors of a given number and returns them as a map.
	*pfs = make(map[int]int);
	// Get the number of 2s that divide n
	while (n%2 == 0) {
		// Sets the key to 2 and the value to the number of occurrences.
		(*pfs)[2]++;
		// Divides n by 2.
		n = n / 2;
	}

	// n must be odd at this point. so we can skip one element
	// (note i = i + 2)
	int i = 3;
	while (i*i <= n) {
		// While i divides n, sets the key to i and the value to the number of occurrences.
		// Then divides n by i.
		while (n%i == 0) {
			(*pfs)[i]++;
			n = n / i;
		}
		// Increment the current number by 2 to check the next odd number.
		i += 2;
	}

	// This condition is to handle the case when n is a prime number
	// greater than 2
	if (n > 2) {
		// Sets the key to n and the value to the number of occurrences.
		(*pfs)[n]++;
	}

	// Returns the result.
	return pfs;
}

// With a comment explaining what the function does:
// Finds the prime factors of a given number and returns them as a map.
int* PrimeFactorsMap(int n, int* pfs) {
	// Initializes an empty map.
	*pfs = make(map[int]int);

	// Get the number of 2s that divide n
	while (n%2 == 0) {
		// Sets the key to 2 and the value to the number of occurrences.
		(*pfs)[2]++;
		// Divides n by 2.
		n = n / 2;
	}

	// n must be odd at this point. so we can skip one element
	// (note i = i + 2)
	int i = 3;
	while (i*i <= n) {
		// While i divides n, sets the key to i and the value to the number of occurrences.
		// Then divides n by i.
		while (n%i == 0) {
			(*pfs)[i]++;
			n = n / i;
		}
		// Increment the current number by 2 to check the next odd number.
		i += 2;
	}

	// This condition is to handle the case when n is a prime number
	// greater than 2
	if (n > 2) {
		// Sets the key to n and the value to the number of occurrences.
		(*pfs)[n]++;
	}

	// Returns the result.
	return pfs;
}

