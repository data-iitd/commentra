
#include <bits/stdc++.h>

using namespace std;

// Function to read a line from standard input
string nextLine() {
	// Read a line from standard input and return it as a string
	string line;
	getline(cin, line);
	return line;
}

// Function to read an integer from standard input
int nextInt() {
	// Read a line from standard input and convert it to an integer
	int n;
	cin >> n;
	return n;
}

// Function to find the minimum of two integers
int min(int i, int j) {
	// Return the smaller of the two integers
	if (i > j) {
		return j;
	}
	return i;
}

// Function to find the minimum number of digits in a divisor of n
void checkDivisibility() {
	// Read an integer from standard input and initialize n variable
	int n = nextInt();

	// Initialize minimum factor with a large value
	int minf = 100;

	// Calculate the square root of n
	int rt = (int)sqrt(n);

	// Check divisibility for numbers from 1 to the square root of n
	for (int i = 1; i < rt+1; i++) {
		// Check if n is divisible by i
		if (n%i == 0) {
			// Calculate the number of digits in the divisor
			int b = n / i;
			int ndigit = 0;
			while (b > 0) {
				b /= 10;
				ndigit++;
			}
			// Update minimum factor if a divisor with fewer digits is found
			minf = min(minf, ndigit);
		}
	}

	// Print the result
	cout << minf << endl;
}

// Main function
int main() {
	// Read an integer from standard input and initialize n variable
	int n = nextInt();

	// Call the checkDivisibility function to find the minimum number of digits in a divisor of n
	checkDivisibility();

	// Print the result
	cout << minf << endl;
}

// Function to find the minimum number of digits in a divisor of n
void checkDivisibility() {
	// Read an integer from standard input and initialize n variable
	int n = nextInt();

	// Initialize minimum factor with a large value
	int minf = 100;

	// Calculate the square root of n
	int rt = (int)sqrt(n);

	// Check divisibility for numbers from 1 to the square root of n
	for (int i = 1; i < rt+1; i++) {
		// Check if n is divisible by i
		if (n%i == 0) {
			// Calculate the number of digits in the divisor
			int b = n / i;
			int ndigit = 0;
			while (b > 0) {
				b /= 10;
				ndigit++;
			}
			// Update minimum factor if a divisor with fewer digits is found
			minf = min(minf, ndigit);
		}
	}

	// Print the result
	cout << minf << endl;
}

// Main function
int main() {
	// Read an integer from standard input and initialize n variable
	int n = nextInt();

	// Call the checkDivisibility function to find the minimum number of digits in a divisor of n
	checkDivisibility();

	// Print the result
	cout << minf << endl;
}

// Function to find the minimum number of digits in a divisor of n
void checkDivisibility() {
	// Read an integer from standard input and initialize n variable
	int n = nextInt();

	// Initialize minimum factor with a large value
	int minf = 100;

	// Calculate the square root of n
	int rt = (int)sqrt(n);

	// Check divisibility for numbers from 1 to the square root of n
	for (int i = 1; i < rt+1; i++) {
		// Check if n is divisible by i
		if (n%i == 0) {
			// Calculate the number of digits in the divisor
			int b = n / i;
			int ndigit = 0;
			while (b > 0) {
				b /= 10;
				ndigit++;
			}
			// Update minimum factor if a divisor with fewer digits is found
			minf = min(minf, ndigit);
		}
	}

	// Print the result
	cout << minf << endl;
}

// Main function
int main() {
	// Read an integer from standard input and initialize n variable
	int n = nextInt();

	// Call the checkDivisibility function to find the minimum number of digits in a divisor of n
	checkDivisibility();

	// Print the result
	cout << minf << endl;
}

// Function to find the minimum number of digits in a divisor of n
void checkDivisibility() {
	// Read an integer from standard input and initialize n variable
	int n = nextInt();

	// Initialize minimum factor with a large value
	int minf = 100;

	// Calculate the square root of n
	int rt = (int)sqrt(n);

	// Check divisibility for numbers from 1 to the square root of n
	for (int i = 1; i < rt+1; i++) {
		// Check if n is divisible by i
		if (n%i == 0) {
			// Calculate the number of digits in the divisor
			int b = n / i;
			int ndigit = 0;
			while (b > 0) {
				b /= 10;
				ndigit++;
			}
			// Update minimum factor if a divisor with fewer digits is found
			minf = min(minf, ndigit);
		}
	}

	// Print the result
	cout << minf << endl;
}

// Main function
int main() {
	// Read an integer from standard input and initialize n variable
	int n = nextInt();

	// Call the checkDivisibility function to find the minimum number of digits in a divisor of n
	checkDivisibility();

	// Print the result
	cout << minf << endl;
}

// Function to find the minimum number of digits in a divisor of n
void checkDivisibility() {
	// Read an integer from standard input and initialize n variable
	int n = nextInt();

	// Initialize minimum factor with a large value
	int minf = 100;

	// Calculate the square root of n
	int rt = (int)sqrt(n);

	// Check divisibility for numbers from 1 to the square root of n
	for (int i = 1; i < rt+1; i++) {
		// Check if n is divisible by i
		if (n%i == 0) {
			// Calculate the number of digits in the divisor
			int b = n / i;
			int ndigit = 0;
			while (b > 0) {
				b /= 10;
				ndigit++;
			}
			// Update minimum factor if a divisor with fewer digits is found
			minf = min(minf, ndigit);
		}
	}

	// Print the result
	cout << minf << endl;
}

// Main function
int main() {
	// Read an integer from standard input and initialize n variable
	int n = nextInt();

	// Call the checkDivisibility function to find the minimum number of digits in a divisor of n
	checkDivisibility();

	// Print the result
	cout << minf << endl;
}

// Function to find the minimum number of digits in a divisor of n
void checkDivisibility() {
	// Read an integer from standard input and initialize n variable
	int n = nextInt();

	// Initialize minimum factor with a large value
	int minf = 100;

	// Calculate the square root of n
	int rt = (int)sqrt(n);

	// Check divisibility for numbers from 1 to the square root of n
	for (int i = 1; i < rt+1; i++) {
		// Check if n is divisible by i
		if (n%i == 0) {
			// Calculate the number of digits in the divisor
			int b = n / i;
			int ndigit = 0;
			while (b > 0) {
				b /= 10;
				ndigit++;
			}
			// Update minimum factor if a divisor with fewer digits is found
			minf = min(minf, ndigit);
		}
	}

	// Print the result
	cout << minf << endl;
}

// Main function
int main() {
	// Read an integer from standard input and initialize n variable
	int n = nextInt();

	// Call the checkDivisibility function to find the minimum number of digits in a divisor of n
	checkDivisibility();

	// Print the result
	cout << minf << endl;
}

// Function to find the minimum number of digits in a divisor of n
void checkDivisibility() {
	// Read an integer from standard input and initialize n variable
	int n = nextInt();

	// Initialize minimum factor with a large value
	int minf = 100;

	// Calculate the square root of n
	int rt = (int)sqrt(n);

	// Check divisibility for numbers from 1 to the square root of n
	for (int i = 1; i < rt+1; i++) {
		// Check if n is divisible by i
		if (n%i == 0) {
			// Calculate the number of digits in the divisor
			int b = n / i;
			int ndigit = 0;
			while (b > 0) {
				b /= 10;
				ndigit++;
			}
			// Update minimum factor if a divisor with fewer digits is found
			minf = min(minf, ndigit);
		}
	}

	// Print the result
	cout << minf << endl;
}

// Main function
int main() {
	// Read an integer from standard input and initialize n variable
	int n = nextInt();

	// Call the checkDivisibility function to find the minimum number of digits in a divisor of n
	checkDivisibility();

	// Print the result
	cout << minf << endl;
}

// Function to find the minimum number of digits in a divisor of n
void checkDivisibility() {
	// Read an integer from standard input and initialize n variable
	int n = nextInt();

	// Initialize minimum factor with a large value
	int minf = 100;

	// Calculate the square root of n
	int rt = (int)sqrt(n);

	// Check divisibility for numbers from 1 to the square root of n
	for (int i = 1; i < rt+1; i++) {
		// Check if n is divisible by i
		if (n%i == 0) {
			// Calculate the number of digits in the divisor
			int b = n / i;
			int ndigit = 0;
			while (b > 0) {
				b /= 10;
				ndigit++;
			}
			// Update minimum factor if a divisor with fewer digits is found
			minf = min(minf, ndigit);
		}
	}

	// Print the result
	cout << minf << endl;
}

// Main function
int main() {
	// Read an integer from standard input and initialize n variable
	int n = nextInt();

	// Call the checkDivisibility function to find the minimum number of digits in a divisor of n
	checkDivisibility();

	// Print the result
	cout << minf << endl;
}

// Function to find the minimum number of digits in a divisor of n
void checkDivisibility() {
	// Read an integer from standard input and initialize n variable
	int n = nextInt();

	// Initialize minimum factor with a large value
	int minf = 100;

	// Calculate the square root of n
	int rt = (int)sqrt(n);

	// Check divisibility for numbers from 1 to the square root of n
	for (int i = 1; i < rt+1; i++) {
		// Check if n is divisible by i
		if (n%i == 0) {
			// Calculate the number of digits in the divisor
			int b = n / i;
			int ndigit = 0;
			while (b > 0) {
				b /= 10;
				ndigit++;
			}
			// Update minimum factor if a divisor with fewer digits is found
			minf = min(minf, ndigit);
		}
	}

	// Print the result
	cout << minf << endl;
}

// Main function
int main() {
	// Read an integer from standard input and initialize n variable
	int n = nextInt();

	// Call the checkDivisibility function to find the minimum number of digits in a divisor of n
	checkDivisibility();

	// Print the result
	cout << minf << endl;
}

// Function to find the minimum number of digits in a divisor of n
void checkDivisibility() {
	// Read an integer from standard input and ini