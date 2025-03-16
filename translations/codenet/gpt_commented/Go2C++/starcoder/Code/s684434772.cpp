#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// util
// *   math/simple

// Abs returns the absolute value of an integer
int Abs(int x) {
	if (x >= 0) {
		return x;
	}
	return -x;
}

// Min returns the minimum value from a list of integers
int Min(int values[]) {
	if (values.size() == 0) {
		return 0;
	}
	int min = values[0];
	for (int i = 1; i < values.size(); i++) {
		if (values[i] < min) {
			min = values[i];
		}
	}
	return min;
}

// Max returns the maximum value from a list of integers
int Max(int values[]) {
	if (values.size() == 0) {
		return 0;
	}
	int max = values[0];
	for (int i = 1; i < values.size(); i++) {
		if (values[i] > max) {
			max = values[i];
		}
	}
	return max;
}

// Pow calculates the power of a base raised to an exponent
int Pow(int base, int exponent) {
	int answer = 1;
	for (int i = 0; i < exponent; i++) {
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
int64_t Min64(int64_t values[]) {
	if (values.size() == 0) {
		return 0;
	}
	int64_t min = values[0];
	for (int i = 1; i < values.size(); i++) {
		if (values[i] < min) {
			min = values[i];
		}
	}
	return min;
}

// Max64 returns the maximum value from a list of int64 values
int64_t Max64(int64_t values[]) {
	if (values.size() == 0) {
		return 0;
	}
	int64_t max = values[0];
	for (int i = 1; i < values.size(); i++) {
		if (values[i] > max) {
			max = values[i];
		}
	}
	return max;
}

// Pow64 calculates the power of a base (int64) raised to an exponent
int64_t Pow64(int64_t base, int exponent) {
	int64_t answer = 1;
	for (int i = 0; i < exponent; i++) {
		answer *= base;
	}
	return answer;
}

// *   io

// Scanner is a custom input scanner that reads words from standard input
class Scanner {
public:
	Scanner() {
		bufScanner = new bufio::Scanner(cin);
		bufScanner->Split(bufio::ScanWords); // Split input by words
	}

	// ReadString reads a single string from input
	string ReadString() {
		bufScanner->Scan(); // Scan the next word
		return bufScanner->Text(); // Return the scanned text
	}

	// ReadInt reads a single integer from input
	int ReadInt() {
		bufScanner->Scan(); // Scan the next word
		string text = bufScanner->Text();

		// Convert the scanned text to an integer
		int num;
		sscanf(text.c_str(), "%d", &num);
		return num;
	}

	// ReadInt64 reads a single int64 from input
	int64_t ReadInt64() {
		bufScanner->Scan(); // Scan the next word
		string text = bufScanner->Text();

		// Convert the scanned text to an int64
		int64_t num;
		sscanf(text.c_str(), "%lld", &num);
		return num;
	}

private:
	bufio::Scanner *bufScanner;
};

// combi calculates the number of combinations based on the given n and k
int64_t combi(int n, int k) {
	// Calculate the minimum and maximum possible values for combinations
	int64_t min = (int64_t)(k-1) * (int64_t)(k) / 2;
	int64_t max = (int64_t)(2*n-k+1) * (int64_t)(k) / 2;
	// Return the count of combinations
	return max - min + 1;
}

// main
int main() {
	// Initialize a new scanner for reading input
	Scanner sc;

	// Read two integers n and k from input
	int n = sc.ReadInt();
	int k = sc.ReadInt();

	// Initialize a variable to hold the total count
	int64_t total = 0;

	// Calculate the total combinations from k to n+1
	for (int i = k; i <= n+1; i++) {
		total += combi(n, i); // Add combinations for the current i
		total = total % (int64_t)(Pow64(10, 9) + 7); // Apply modulo to prevent overflow
	}

	// Print the final total
	cout << total << endl;
	return 0;
}

