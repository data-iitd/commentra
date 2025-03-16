
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Util functions

// With a comment explaining what the function does:
// Scans the next token, a string, into sc.Text() and returns it as a string.
char* nextStr() {
	// Scans the next token, a string, into sc.Text().
	scanf("%s", sc.Text());
	// Returns the text scanned into sc.Text() as a string.
	return sc.Text();
}

int nextInt() {
	// Scans the next token, a string, into sc.Text().
	// Converts the string to an integer using strconv.Atoi() and returns it.
	scanf("%d", &i);
	if (e != NULL) {
		panic(e);
	}
	return i;
}

// With a comment explaining what the function does:
// Scans the next token, a string, into sc.Text() and converts it to an integer.
int nextInt() {
	// Scans the next token, a string, into sc.Text().
	scanf("%d", &i);
	// Recovers from any panic that might occur during the conversion.
	if (e != NULL) {
		panic(e);
	}
	// Returns the integer.
	return i;
}

// Helper functions for mathematical operations

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

// With a comment explaining what the function does:
// Returns the absolute value of a floating-point number.
float absFloat64(float a) {
	// If the floating-point number is non-negative, return it as is.
	if (a >= 0) {
		return a;
	} else {
		// Otherwise, return the negative of the floating-point number.
		return -a;
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

// With a comment explaining what the function does:
// Converts a string to an integer.
int str2Int(char* s) {
	// Attempts to convert the string to an integer using strconv.Atoi().
	n = atoi(s);
	// Returns the integer.
	return n;
}

// With a comment explaining what the function does:
// Reverses a given string.
char* reverse(char* s) {
	// Initializes a rune slice with the given string.
	runes = (char*)malloc(sizeof(char) * strlen(s));
	// Iterates through the rune slice from both ends and swaps the elements.
	for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		// Swaps the elements at the current indices.
		runes[i] = s[j];
		runes[j] = s[i];
	}
	// Returns the reversed string.
	return runes;
}

// With a comment explaining what the function does:
// Calculates 'p' raised to the power of 'q'.
int powInt(int p, int q) {
	// Calculates 'p' raised to the power of 'q' using the math.Pow() function.
	return (int)pow(p, q);
}

// With a comment explaining what the function does:
// Checks if a given number is prime.
bool isPrime(int x) {
	// If the number is 1, it's not a prime number.
	if (x == 1) {
		return false;
	}
	// If the number is 2, it's a prime number.
	if (x == 2) {
		return true;
	}
	// If the number is even, it's not a prime number.
	if (x % 2 == 0) {
		return false;
	}

	// Iterates through the numbers from 3 to the square root of 'x'.
	b = true;
	rootx = (int)sqrt(x);
	i = 3;
	// Checks if any of the numbers from 3 to the square root of 'x' divide 'x'.
	for (i = 3; i <= rootx; i = i + 2) {
		// If 'x' is divisible by the current number, it's not a prime number.
		if (x % i == 0) {
			b = false;
			break;
		}
	}
	// Returns the result.
	return b;
}

// With a comment explaining what the function does:
// Finds the prime factors of a given number.
int* PrimeFactors(int n) {
	// Initializes an empty result slice.
	pfs = (int*)malloc(sizeof(int) * 100);

	// Get the number of 2s that divide n
	for (n % 2 == 0) {
		// Appends 2 to the result slice.
		pfs[i++] = 2;
		// Divides n by 2.
		n = n / 2;
	}

	// n must be odd at this point. so we can skip one element
	// (note i = i + 2)
	for (i = 3; i * i <= n; i = i + 2) {
		// While i divides n, appends i to the result slice and divides n by i.
		for (n % i == 0) {
			pfs[i++] = i;
			n = n / i;
		}
	}

	// This condition is to handle the case when n is a prime number
	// greater than 2
	if (n > 2) {
		// Appends n to the result slice.
		pfs[i++] = n;
	}

	// Returns the result.
	return pfs;
}

// With a comment explaining what the function does:
// Finds the prime factors of a given number and returns them as a map.
int* PrimeFactorsMap(int n) {
	// Initializes an empty map.
	pfs = (int*)malloc(sizeof(int) * 100);

	// Get the number of 2s that divide n
	for (n % 2 == 0) {
		// Sets the key to 2 and the value to the number of occurrences.
		pfs[2]++;
		// Divides n by 2.
		n = n / 2;
	}

	// n must be odd at this point. so we can skip one element
	// (note i = i + 2)
	for (i = 3; i * i <= n; i = i + 2) {
		// While i divides n, sets the key to i and the value to the number of occurrences.
		// Then divides n by i.
		for (n % i == 0) {
			pfs[i]++;
			n = n / i;
		}
	}

	// This condition is to handle the case when n is a prime number
	// greater than 2
	if (n > 2) {
		// Sets the key to n and the value to the number of occurrences.
		pfs[n]++;
	}

	// Returns the result.
	return pfs;
}

