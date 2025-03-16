
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The main function is the entry point of the program.
int main() {
	// Initialize a new Scanner object named 'sc'.
	Scanner sc = NewScanner();

	// Read 'n' and 'k' from the standard input.
	int n = sc.ReadInt();
	int k = sc.ReadInt();

	// Initialize a variable 'total' to store the sum of combinations.
	long long total = 0;

	// Calculate the sum of combinations of 'n' taken 'i' at a time, where 'i' ranges from 'k' to 'n+1'.
	for (int i = k; i <= n+1; i++) {
		// Calculate the number of combinations using the combi function.
		long long comb = combi(n, i);
		// Add the number of combinations to the 'total' variable.
		total += comb;
		// Apply modulo operation to reduce the size of the number.
		total = total % (Pow64(10, 9) + 7);
	}

	// Print the result to the standard output.
	printf("%lld\n", total);

	// Return 0 to indicate that the program ended successfully.
	return 0;
}

// The combi function calculates the number of combinations of 'n' taken 'k' at a time using a simplified formula.
long long combi(int n, int k) {
	// Calculate the minimum and maximum number of combinations.
	long long min = (long long)(k-1) * (long long)(k) / 2;
	long long max = (long long)(2*n-k+1) * (long long)(k) / 2;
	// Return the difference between the maximum and minimum number of combinations.
	return max - min + 1;
}

// Util functions for performing basic mathematical operations.

// Abs returns the absolute value of a given integer.
int Abs(int x) {
	// If the number is positive, return the number itself.
	// Otherwise, return the negative of the number.
	if (x >= 0) {
		return x;
	}
	return -x;
}

// Min returns the minimum value among the given integers.
int Min(int values[], int n) {
	// Initialize the minimum value with the first integer.
	int min = values[0];
	// Compare each integer with the minimum value and update the minimum value if necessary.
	for (int i = 1; i < n; i++) {
		if (values[i] < min) {
			min = values[i];
		}
	}
	// Return the minimum value.
	return min;
}

// Max returns the maximum value among the given integers.
int Max(int values[], int n) {
	// Initialize the maximum value with the first integer.
	int max = values[0];
	// Compare each integer with the maximum value and update the maximum value if necessary.
	for (int i = 1; i < n; i++) {
		if (values[i] > max) {
			max = values[i];
		}
	}
	// Return the maximum value.
	return max;
}

// Pow returns the result of raising the base to the given exponent.
int Pow(int base, unsigned int exponent) {
	// Initialize the answer with 1.
	int answer = 1;
	// Multiply the answer with the base for each bit in the exponent.
	for (unsigned int i = 0; i < exponent; i++) {
		answer *= base;
	}
	// Return the answer.
	return answer;
}

// Abs64 returns the absolute value of a given integer64.
long long Abs64(long long x) {
	// If the number is positive, return the number itself.
	// Otherwise, return the negative of the number.
	if (x >= 0) {
		return x;
	}
	return -x;
}

// Min64 returns the minimum value among the given integer64s.
long long Min64(long long values[], int n) {
	// Initialize the minimum value with the first integer.
	long long min = values[0];
	// Compare each integer with the minimum value and update the minimum value if necessary.
	for (int i = 1; i < n; i++) {
		if (values[i] < min) {
			min = values[i];
		}
	}
	// Return the minimum value.
	return min;
}

// Max64 returns the maximum value among the given integer64s.
long long Max64(long long values[], int n) {
	// Initialize the maximum value with the first integer.
	long long max = values[0];
	// Compare each integer with the maximum value and update the maximum value if necessary.
	for (int i = 1; i < n; i++) {
		if (values[i] > max) {
			max = values[i];
		}
	}
	// Return the maximum value.
	return max;
}

// Pow64 returns the result of raising the base to the given exponent.
long long Pow64(long long base, unsigned int exponent) {
	// Initialize the answer with 1.
	long long answer = 1;
	// Multiply the answer with the base for each bit in the exponent.
	for (unsigned int i = 0; i < exponent; i++) {
		answer *= base;
	}
	// Return the answer.
	return answer;
}

// Scanner struct is used to read input from the standard input.
typedef struct {
	// bufio.Scanner is used to read input from the standard input.
	struct bufio_Scanner *bufScanner;
} Scanner;

// NewScanner initializes a new Scanner object.
Scanner NewScanner() {
	// Initialize a new bufio.Scanner object named 'bufSc'.
	struct bufio_Scanner *bufSc = bufio_NewScanner(stdin);
	// Set the splitting function of bufio.Scanner to scan words.
	bufio_Scanner_Split(bufSc, bufio_ScanWords);
	// Initialize a new Scanner object named 'sc' with the bufio.Scanner object.
	Scanner sc = {bufSc};
	// Return the Scanner object.
	return sc;
}

// ReadString reads a string from the standard input.
char *ReadString(Scanner sc) {
	// Read a word from the standard input using bufio.Scanner.
	struct bufio_Scanner *bufSc = sc.bufScanner;
	bufio_Scanner_Scan(bufSc);
	// Return the read word as a string.
	return bufio_Scanner_Text(bufSc);
}

// ReadInt reads an integer from the standard input.
int ReadInt(Scanner sc) {
	// Read a word from the standard input using bufio.Scanner.
	struct bufio_Scanner *bufSc = sc.bufScanner;
	bufio_Scanner_Scan(bufSc);
	// Convert the read word to an integer using strconv.Atoi.
	int num = atoi(bufio_Scanner_Text(bufSc));
	// If an error occurs, panic with the error message.
	if (num == 0 && errno == EINVAL) {
		perror("strconv.Atoi");
		exit(1);
	}
	// Return the read integer.
	return num;
}

// ReadInt64 reads an integer64 from the standard input.
long long ReadInt64(Scanner sc) {
	// Read a word from the standard input using bufio.Scanner.
	struct bufio_Scanner *bufSc = sc.bufScanner;
	bufio_Scanner_Scan(bufSc);
	// Convert the read word to an integer64 using strconv.ParseInt.
	long long num = strtoll(bufio_Scanner_Text(bufSc), NULL, 10);
	// If an error occurs, panic with the error message.
	if (num == 0 && errno == EINVAL) {
		perror("strconv.ParseInt");
		exit(1);
	}
	// Return the read integer64.
	return num;
}

