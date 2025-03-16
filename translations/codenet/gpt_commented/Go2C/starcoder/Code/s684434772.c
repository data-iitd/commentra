

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// combi calculates the number of combinations based on the given n and k
int64_t combi(int64_t n, int64_t k) {
	// Calculate the minimum and maximum possible values for combinations
	int64_t min = (k-1) * (k) / 2;
	int64_t max = (2*n-k+1) * (k) / 2;
	// Return the count of combinations
	return max - min + 1;
}

int main(int argc, char *argv[]) {
	// Initialize a new scanner for reading input
	Scanner *sc = NewScanner();

	// Read two integers n and k from input
	int64_t n = sc->ReadInt64();
	int64_t k = sc->ReadInt64();

	// Initialize a variable to hold the total count
	int64_t total = 0;

	// Calculate the total combinations from k to n+1
	for (int64_t i = k; i <= n+1; i++) {
		total += combi(n, i); // Add combinations for the current i
		total = total % (int64_t)(1e9 + 7); // Apply modulo to prevent overflow
	}

	// Print the final total
	printf("%ld\n", total);
	return 0;
}

// util
// *   math/simple

// Abs returns the absolute value of an integer
int64_t Abs(int64_t x) {
	if (x >= 0) {
		return x;
	}
	return -x;
}

// Min returns the minimum value from a list of integers
int64_t Min(int64_t values[], int64_t length) {
	if (length == 0) {
		panic("no values");
	}
	int64_t min = values[0];
	for (int64_t i = 1; i < length; i++) {
		if (values[i] < min) {
			min = values[i];
		}
	}
	return min;
}

// Max returns the maximum value from a list of integers
int64_t Max(int64_t values[], int64_t length) {
	if (length == 0) {
		panic("no values");
	}
	int64_t max = values[0];
	for (int64_t i = 1; i < length; i++) {
		if (values[i] > max) {
			max = values[i];
		}
	}
	return max;
}

// Pow calculates the power of a base raised to an exponent
int64_t Pow(int64_t base, uint64_t exponent) {
	int64_t answer = 1;
	for (uint64_t i = 0; i < exponent; i++) {
		answer *= base;
	}
	return answer;
}

// Abs64 returns the absolute value of an int64
int64_t Abs64(int64_t x) {
	if (x >= 0) {
		return x;
	}
	return -x;
}

// Min64 returns the minimum value from a list of int64 values
int64_t Min64(int64_t values[], int64_t length) {
	if (length == 0) {
		panic("no values");
	}
	int64_t min = values[0];
	for (int64_t i = 1; i < length; i++) {
		if (values[i] < min) {
			min = values[i];
		}
	}
	return min;
}

// Max64 returns the maximum value from a list of int64 values
int64_t Max64(int64_t values[], int64_t length) {
	if (length == 0) {
		panic("no values");
	}
	int64_t max = values[0];
	for (int64_t i = 1; i < length; i++) {
		if (values[i] > max) {
			max = values[i];
		}
	}
	return max;
}

// Pow64 calculates the power of a base (int64) raised to an exponent
int64_t Pow64(int64_t base, uint64_t exponent) {
	int64_t answer = 1;
	for (uint64_t i = 0; i < exponent; i++) {
		answer *= base;
	}
	return answer;
}

// *   io

// Scanner is a custom input scanner that reads words from standard input
typedef struct {
	bufio_Scanner *bufScanner;
} Scanner;

// NewScanner initializes a new Scanner instance
Scanner *NewScanner() {
	bufio_Scanner *bufSc = bufio_NewScanner(os_Stdin);
	bufSc->Split(bufio_ScanWords); // Split input by words
	return (Scanner *)bufSc;
}

// ReadString reads a single string from input
char *ReadString(Scanner *sc) {
	bufio_Scanner *bufSc = (bufio_Scanner *)sc;
	bufSc->Scan(); // Scan the next word
	return bufSc->Text(); // Return the scanned text
}

// ReadInt reads a single integer from input
int64_t ReadInt(Scanner *sc) {
	bufio_Scanner *bufSc = (bufio_Scanner *)sc;
	bufSc->Scan(); // Scan the next word
	char *text = bufSc->Text();

	// Convert the scanned text to an integer
	int64_t num;
	sscanf(text, "%ld", &num);
	return num;
}

// ReadInt64 reads a single int64 from input
int64_t ReadInt64(Scanner *sc) {
	bufio_Scanner *bufSc = (bufio_Scanner *)sc;
	bufSc->Scan(); // Scan the next word
	char *text = bufSc->Text();

	// Convert the scanned text to an int64
	int64_t num;
	sscanf(text, "%ld", &num);
	return num;
}

// *   main

// main is the entry point of the program
int main(int argc, char *argv[]) {
	// Initialize a new scanner for reading input
	Scanner *sc = NewScanner();

	// Read two integers n and k from input
	int64_t n = ReadInt64(sc);
	int64_t k = ReadInt64(sc);

	// Initialize a variable to hold the total count
	int64_t total = 0;

	// Calculate the total combinations from k to n+1
	for (int64_t i = k; i <= n+1; i++) {
		total += combi(n, i); // Add combinations for the current i
		total = total % (int64_t)(1e9 + 7); // Apply modulo to prevent overflow
	}

	// Print the final total
	printf("%ld\n", total);
	return 0;
}

// util
// *   math/simple

// Abs returns the absolute value of an integer
int64_t Abs(int64_t x) {
	if (x >= 0) {
		return x;
	}
	return -x;
}

// Min returns the minimum value from a list of integers
int64_t Min(int64_t values[], int64_t length) {
	if (length == 0) {
		panic("no values");
	}
	int64_t min = values[0];
	for (int64_t i = 1; i < length; i++) {
		if (values[i] < min) {
			min = values[i];
		}
	}
	return min;
}

// Max returns the maximum value from a list of integers
int64_t Max(int64_t values[], int64_t length) {
	if (length == 0) {
		panic("no values");
	}
	int64_t max = values[0];
	for (int64_t i = 1; i < length; i++) {
		if (values[i] > max) {
			max = values[i];
		}
	}
	return max;
}

// Pow calculates the power of a base raised to an exponent
int64_t Pow(int64_t base, uint64_t exponent) {
	int64_t answer = 1;
	for (uint64_t i = 0; i < exponent; i++) {
		answer *= base;
	}
	return answer;
}

// Abs64 returns the absolute value of an int64
int64_t Abs64(int64_t x) {
	if (x >= 0) {
		return x;
	}
	return -x;
}

// Min64 returns the minimum value from a list of int64 values
int64_t Min64(int64_t values[], int64_t length) {
	if (length == 0) {
		panic("no values");
	}
	int64_t min = values[0];
	for (int64_t i = 1; i < length; i++) {
		if (values[i] < min) {
			min = values[i];
		}
	}
	return min;
}

// Max64 returns the maximum value from a list of int64 values
int64_t Max64(int64_t values[], int64_t length) {
	if (length == 0) {
		panic("no values");
	}
	int64_t max = values[0];
	for (int64_t i = 1; i < length; i++) {
		if (values[i] > max) {
			max = values[i];
		}
	}
	return max;
}

// Pow64 calculates the power of a base (int64) raised to an exponent
int64_t Pow64(int64_t base, uint64_t exponent) {
	int64_t answer = 1;
	for (uint64_t i = 0; i < exponent; i++) {
		answer *= base;
	}
	return answer;
}

// *   io

// Scanner is a custom input scanner that reads words from standard input
typedef struct {
	bufio_Scanner *bufScanner;
} Scanner;

// NewScanner initializes a new Scanner instance
Scanner *NewScanner() {
	bufio_Scanner *bufSc = bufio_NewScanner(os_Stdin);
	bufSc->Split(bufio_ScanWords); // Split input by words
	return (Scanner *)bufSc;
}

// ReadString reads a single string from input
char *ReadString(Scanner *sc) {
	bufio_Scanner *bufSc = (bufio_Scanner *)sc;
	bufSc->Scan(); // Scan the next word
	return bufSc->Text(); // Return the scanned text
}

// ReadInt reads a single integer from input
int64_t ReadInt(Scanner *sc) {
	bufio_Scanner *bufSc = (bufio_Scanner *)sc;
	bufSc->Scan(); // Scan the next word
	char *text = bufSc->Text();

	// Convert the scanned text to an integer
	int64_t num;
	sscanf(text, "%ld", &num);
	return num;
}

// ReadInt64 reads a single int64 from input
int64_t ReadInt64(Scanner *sc) {
	bufio_Scanner *bufSc = (bufio_Scanner *)sc;
	bufSc->Scan(); // Scan the next word
	char *text = bufSc->Text();

	// Convert the scanned text to an int64
	int64_t num;
	sscanf(text, "%ld", &num);
	return num;
}

// *   main

// main is the entry point of the program
int main(int argc, char *argv[]) {
	// Initialize a new scanner for reading input
	Scanner *sc = NewScanner();

	// Read two integers n and k from input
	int64_t n = ReadInt64(sc);
	int64_t k = ReadInt64(sc);

	// Initialize a variable to hold the total count
	int64_t total = 0;

	// Calculate the total combinations from k to n+1
	for (int64_t i = k; i <= n+1; i++) {
		total += combi(n, i); // Add combinations for the current i
		total = total % (int64_t)(1e9 + 7); // Apply modulo to prevent overflow
	}

	// Print the final total
	printf("%ld\n", total);
	return 0;
}

// util
// *   math/simple

// Abs returns the absolute value of an integer
int64_t Abs(int64_t x) {
	if (x >= 0) {
		return x;
	}
	return -x;
}

// Min returns the minimum value from a list of integers
int64_t Min(int64_t values[], int64_t length) {
	if (length == 0) {
		panic("no values");
	}
	int64_t min = values[0];
	for (int64_t i = 1; i < length; i++) {
		if (values[i] < min) {
			min = values[i];
		}
	}
	return min;
}

// Max returns the maximum value from a list of integers
int64_t Max(int64_t values[], int64_t length) {
	if (length == 0) {
		panic("no values");
	}
	int64_t max = values[0];
	for (int64_t i = 1; i < length; i++) {
		if (values[i] > max) {
			max = values[i];
		}
	}
	return max;
}

// Pow calculates the power of a base raised to an exponent
int64_t Pow(int64_t base, uint64_t exponent) {
	int64_t answer = 1;
	for (uint64_t i = 0; i < exponent; i++) {
		answer *= base;
	}
	return answer;
}

// Abs64 returns the absolute value of an int64
int64_t Abs64(int64_t x) {
	if (x >= 0) {
		return x;
	}
	return -x;
}

// Min64 returns the minimum value from a list of int64 values
int64_t Min64(int64_t values[], int64_t length) {
	if (length == 0) {
		panic("no values");
	}
	int64_t min = values[0];
	for (int64_t i = 1; i < length; i++) {
		if (values[i] < min) {
			min = values[i];
		}
	}
	return min;
}

// Max64 returns the maximum value from a list of int64 values
int64_t Max64(int64_t values[], int64_t length) {
	if (length == 0) {
		panic("no values");
	}
	int64_t max = values[0];
	for (int64_t i = 1; i < length; i++) {
		if (values[i] > max) {
			max = values[i];
		}
	}
	return max;
}

// Pow64 calculates the power of a base (int64) raised to an exponent
int64_t Pow64(int64_t base, uint64_t exponent) {
	int64_t answer = 1;
	for (uint64_t i =