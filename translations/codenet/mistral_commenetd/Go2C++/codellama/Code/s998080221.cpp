
#include <bits/stdc++.h>

using namespace std;

// Function (r *bufReader) readLine reads a line from os.Stdin and stores it in the buffer
void bufReader::readLine() {
	// If the index is less than the length of the buffer, it means that there is still some data left in the buffer
	if (i < buf.size()) {
		return;
	}
	// Clear the buffer and set the index to 0
	buf.clear();
	i = 0;
	// Read a line from os.Stdin and store it in the buffer
	for (;;) {
		string line;
		getline(cin, line);
		// If the line is not a prefix (i.e., it is a complete line), break the loop
		if (!cin.good()) {
			break;
		}
		// Append the line to the buffer
		buf.push_back(line);
	}
}

// Function (r *bufReader) next returns the next token (i.e., a word or a number) from the buffer
string bufReader::next() {
	// Read a line from the buffer
	readLine();
	// Find the index of the first whitespace character in the line
	int from = i;
	// Iterate through the line until a whitespace character is found
	for (; i < buf.size(); i++) {
		// If the current character is a whitespace character, break the loop
		if (buf[i] == ' ') {
			break;
		}
	}
	// Return the substring from the start index to the current index
	string s = buf.substr(from, i - from);
	// Increment the index
	i++;
	// Return the token
	return s;
}

// Function nextLine reads a line from the buffer
string bufReader::nextLine() {
	// Read a line from the buffer
	readLine();
	// Return the substring from the current index to the end of the buffer
	string s = buf.substr(i);
	// Set the index to the end of the buffer
	i = buf.size();
	// Return the line
	return s;
}

// Function next returns the next token (i.e., a word or a number) from the custom reader
string next() {
	// Call the next function of the custom reader and return the result
	return reader.next();
}

// Function nextInt64 parses an integer from the custom reader and returns it as an int64 type
int64_t nextInt64() {
	// Parse an integer from the custom reader and return it as an int64 type
	int64_t i;
	cin >> i;
	// If an error occurs during parsing, panic with the error message
	if (cin.fail()) {
		panic("failed to parse integer");
	}
	// Return the integer
	return i;
}

// Function nextInt parses an integer from the custom reader and returns it as an int type
int nextInt() {
	// Parse an integer from the custom reader and return it as an int type
	return int(nextInt64());
}

// Function nextLine reads a line from the custom reader and returns it as a string
string nextLine() {
	// Read a line from the custom reader and return it as a string
	return reader.nextLine();
}

// Function out is used for printing output to the console
void out(string a) {
	// Write the formatted output to the bufio.Writer
	cout << a << endl;
}

// Function max64 returns the maximum of two int64 values
int64_t max64(int64_t x, int64_t y) {
	// If x is greater than y, return x; otherwise, return y
	if (x > y) {
		return x;
	}
	return y;
}

// Function max returns the maximum of two int values
int max(int x, int y) {
	// Return the maximum of x and y as an int value
	return int(max64(int64_t(x), int64_t(y)));
}

// Function min64 returns the minimum of two int64 values
int64_t min64(int64_t x, int64_t y) {
	// If x is less than y, return x; otherwise, return y
	if (x < y) {
		return x;
	}
	return y;
}

// Function min returns the minimum of two int values
int min(int x, int y) {
	// Return the minimum of x and y as an int value
	return int(min64(int64_t(x), int64_t(y)));
}

// Function abs64 returns the absolute value of an int64 value
int64_t abs64(int64_t x) {
	// If x is negative, return the negative of x; otherwise, return x
	if (x < 0) {
		return -x;
	}
	return x;
}

// Function abs returns the absolute value of an int value
int abs(int x) {
	// Return the absolute value of x as an int value
	return int(abs64(int64_t(x)));
}

// Function joinInt64s joins an array of int64 values with a given separator and returns the resulting string
string joinInt64s(vector<int64_t> a, string sep) {
	// Create a slice of strings by converting each int64 value to a string
	vector<string> b(a.size());
	// Iterate through the array and convert each int64 value to a string
	for (int i = 0; i < a.size(); i++) {
		b[i] = to_string(a[i]);
	}
	// Join the strings in the slice with the given separator and return the resulting string
	return join(b, sep);
}

// Function joinInts joins an array of int values with a given separator and returns the resulting string
string joinInts(vector<int> a, string sep) {
	// Create a slice of strings by converting each int value to a string
	vector<string> b(a.size());
	// Iterate through the array and convert each int value to a string
	for (int i = 0; i < a.size(); i++) {
		b[i] = to_string(a[i]);
	}
	// Join the strings in the slice with the given separator and return the resulting string
	return join(b, sep);
}

// Function divUp64 returns the smallest integer n such that n*divisor >= dividend
int64_t divUp64(int64_t x, int64_t y) {
	// Return the smallest integer n such that n*divisor >= dividend
	return (x + y - 1) / y;
}

// Function divUp returns the smallest integer n such that n*divisor >= dividend
int divUp(int x, int y) {
	// Return the smallest integer n such that n*divisor >= dividend
	return int(divUp64(int64_t(x), int64_t(y)));
}

// Function gcd64 returns the greatest common divisor of two int64 values
int64_t gcd64(int64_t x, int64_t y) {
	// If x is greater than y, swap x and y
	if (x < y) {
		x = y;
		y = x;
	}
	// Iterate through the range of possible divisors
	for (; y != 0;) {
		// Calculate the remainder of x/y
		x = y;
		y = x % y;
	}
	// Return x as the greatest common divisor
	return x;
}

// Function gcd returns the greatest common divisor of two int values
int gcd(int x, int y) {
	// Return the greatest common divisor of x and y as an int value
	return int(gcd64(int64_t(x), int64_t(y)));
}

// Function lcm64 returns the least common multiple of two int64 values
int64_t lcm64(int64_t x, int64_t y) {
	// Calculate the greatest common divisor of x and y
	int64_t gcd = gcd64(x, y);
	// Return the product of x and y divided by their greatest common divisor
	return x * y / gcd;
}

// Function lcm returns the least common multiple of two int values
int lcm(int x, int y) {
	// Return the least common multiple of x and y as an int value
	return int(lcm64(int64_t(x), int64_t(y)));
}

// Function pow64 returns x raised to the power of y as an int64 value
int64_t pow64(int64_t x, int64_t y) {
	// Return x raised to the power of y as an int64 value using the math.Pow function
	return int64_t(pow(double(x), double(y)));
}

// Function pow returns x raised to the power of y as an int value
int pow(int x, int y) {
	// Return x raised to the power of y as an int value
	return int(pow64(int64_t(x), int64_t(y)));
}

// Function main is the entry point of the program
int main() {
	// Call the solve function to solve the problem
	solve();
	// Flush the bufio.Writer to write the output to the console
	cout.flush();
	// Return 0 to indicate successful execution
	return 0;
}

// Function solve reads input from the custom reader, processes it, and writes the output to the bufio.Writer
void solve() {
	// Read two integers N and K from the custom reader
	int N, K;
	cin >> N >> K;
	// Initialize an array A of size N
	vector<int> A(N);
	// Read N integers from the custom reader and store them in the array A
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	// Initialize variables maxProfit, maxCnt, and maxA
	int maxProfit = 0;
	int maxCnt = 0;
	int maxA = A[N - 1];
	// Iterate through the array A from the last index to the first index
	for (int i = N - 2; i >= 0; i--) {
		// Calculate the profit of the current transaction
		int profit = max(0, maxA - A[i]);
		// If the current profit is greater than the maximum profit found so far, update maxProfit and maxCnt
		if (maxProfit < profit) {
			maxProfit = profit;
			maxCnt = 1;
		} else if (maxProfit == profit) {
			maxCnt++;
		}
		// Update maxA with the maximum of the current element and maxA
		maxA = max(maxA, A[i]);
	}
	// Write the output to the console
	out(maxCnt);
}

