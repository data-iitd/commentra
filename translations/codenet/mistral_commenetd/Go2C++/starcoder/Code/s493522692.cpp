// Util functions
#include <bits/stdc++.h>
using namespace std;

// Util functions
string nextStr() {
	// Scans the next token, a rune, into sc.Text().
	sc.Scan();
	// Returns the text scanned into sc.Text() as a string.
	return sc.Text();
}

// With a comment explaining what the function does:
// Scans the next token, a rune, into sc.Text() and returns it as a string.
string nextStr() {
	// Scans the next token, a rune, into sc.Text().
	sc.Scan();
	// Returns the text scanned into sc.Text() as a string.
	return sc.Text();
}

int nextInt() {
	// Scans the next token, a string, into sc.Text().
	// Converts the string to an integer using stoi() and returns it.
	return stoi(sc.Text());
}

// With a comment explaining what the function does:
// Scans the next token, a string, into sc.Text() and converts it to an integer.
int nextInt() {
	// Scans the next token, a string, into sc.Text().
	sc.Scan();
	// Converts the string to an integer using stoi().
	return stoi(sc.Text());
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

double absFloat64(double a) {
	// Returns the absolute value of a floating-point number.
	if (a >= 0) {
		return a;
	} else {
		return -a;
	}
}

// With a comment explaining what the function does:
// Returns the absolute value of a floating-point number.
double absFloat64(double a) {
	// If the floating-point number is non-negative, return it as is.
	if (a >= 0) {
		return a;
	} else {
		// Otherwise, return the negative of the floating-point number.
		return -a;
	}
}

double maxFloat64(double a, double b) {
	// Returns the maximum of two floating-point numbers.
	if (a > b) {
		return a;
	} else {
		return b;
	}
}

// With a comment explaining what the function does:
// Returns the maximum of two floating-point numbers.
double maxFloat64(double a, double b) {
	// If 'a' is greater than 'b', return 'a'.
	if (a > b) {
		return a;
	} else {
		// Otherwise, return 'b'.
		return b;
	}
}

double minFloat64(double a, double b) {
	// Returns the minimum of two floating-point numbers.
	if (a > b) {
		return b;
	} else {
		return a;
	}
}

// With a comment explaining what the function does:
// Returns the minimum of two floating-point numbers.
double minFloat64(double a, double b) {
	// If 'a' is greater than 'b', return 'b'.
	if (a > b) {
		return b;
	} else {
		// Otherwise, return 'a'.
		return a;
	}
}

int str2Int(string s) {
	// Converts a string to an integer.
	return stoi(s);
}

// With a comment explaining what the function does:
// Converts a string to an integer.
int str2Int(string s) {
	// Attempts to convert the string to an integer using stoi().
	return stoi(s);
}

string reverse(string s) {
	// Reverses a given string.
	string rev = "";
	// Iterates through the rune slice from both ends and swaps the elements.
	for (int i = 0; i < s.length(); i++) {
		// Appends the current rune to the reversed string.
		rev += s[s.length() - i - 1];
	}
	// Returns the reversed string.
	return rev;
}

// With a comment explaining what the function does:
// Reverses a given string.
string reverse(string s) {
	// Initializes a string with the given string.
	string rev = "";
	// Iterates through the rune slice from both ends and swaps the elements.
	for (int i = 0; i < s.length(); i++) {
		// Appends the current rune to the reversed string.
		rev += s[s.length() - i - 1];
	}
	// Returns the reversed string.
	return rev;
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

bool isPrime(int x) {
	// Checks if a given number is prime.
	if (x == 1) {
		// 1 is not a prime number.
		return false;
	}
	if (x == 2) {
		// 2 is a prime number.
		return true;
	}
	// If the number is even, it's not a prime number.
	if (x%2 == 0) {
		return false;
	}

	// Iterates through the numbers from 3 to the square root of 'x'.
	for (int i = 3; i <= sqrt(x); i += 2) {
		// If 'x' is divisible by the current number, it's not a prime number.
		if (x%i == 0) {
			return false;
		}
	}
	// Returns the result.
	return true;
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
	if (x%2 == 0) {
		return false;
	}

	// Iterates through the numbers from 3 to the square root of 'x'.
	for (int i = 3; i <= sqrt(x); i += 2) {
		// If 'x' is divisible by the current number, it's not a prime number.
		if (x%i == 0) {
			return false;
		}
	}
	// Returns the result.
	return true;
}

vector<int> PrimeFactors(int n) {
	// Finds the prime factors of a given number.
	// Initializes an empty result vector.
	vector<int> pfs;
	// Get the number of 2s that divide n
	while (n%2 == 0) {
		// Appends 2 to the result vector.
		pfs.push_back(2);
		// Divides n by 2.
		n = n / 2;
	}

	// n must be odd at this point. so we can skip one element
	// (note i = i + 2)
	for (int i = 3; i*i <= n; i = i + 2) {
		// While i divides n, appends i to the result vector and divides n by i.
		while (n%i == 0) {
			pfs.push_back(i);
			n = n / i;
		}
	}

	// This condition is to handle the case when n is a prime number
	// greater than 2
	if (n > 2) {
		// Appends n to the result vector.
		pfs.push_back(n);
	}

	// Returns the result.
	return pfs;
}

// With a comment explaining what the function does:
// Finds the prime factors of a given number.
vector<int> PrimeFactors(int n) {
	// Initializes an empty result vector.
	vector<int> pfs;

	// Get the number of 2s that divide n
	while (n%2 == 0) {
		// Appends 2 to the result vector.
		pfs.push_back(2);
		// Divides n by 2.
		n = n / 2;
	}

	// n must be odd at this point. so we can skip one element
	// (note i = i + 2)
	for (int i = 3; i*i <= n; i = i + 2) {
		// While i divides n, appends i to the result vector and divides n by i.
		while (n%i == 0) {
			pfs.push_back(i);
			n = n / i;
		}
	}

	// This condition is to handle the case when n is a prime number
	// greater than 2
	if (n > 2) {
		// Appends n to the result vector.
		pfs.push_back(n);
	}

	// Returns the result.
	return pfs;
}

map<int, int> PrimeFactorsMap(int n) {
	// Finds the prime factors of a given number and returns them as a map.
	// Initializes an empty map.
	map<int, int> pfs;
	// Get the number of 2s that divide n
	while (n%2 == 0) {
		// Sets the key to 2 and the value to the number of occurrences.
		pfs[2]++;
		// Divides n by 2.
		n = n / 2;
	}

	// n must be odd at this point. so we can skip one element
	// (note i = i + 2)
	for (int i = 3; i*i <= n; i = i + 2) {
		// While i divides n, sets the key to i and the value to the number of occurrences.
		// Then divides n by i.
		while (n%i == 0) {
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

// With a comment explaining what the function does:
// Finds the prime factors of a given number and returns them as a map.
map<int, int> PrimeFactorsMap(int n) {
	// Initializes an empty map.
	map<int, int> pfs;

	// Get the number of 2s that divide n
	while (n%2 == 0) {
		// Sets the key to 2 and the value to the number of occurrences.
		pfs[2]++;
		// Divides n by 2.
		n = n / 2;
	}

	// n must be odd at this point. so we can skip one element
	// (note i = i + 2)
	for (int i = 3; i*i <= n; i = i + 2) {
		// While i divides n, sets the key to i and the value to the number of occurrences.
		// Then divides n by i.
		while (n%i == 0) {
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

