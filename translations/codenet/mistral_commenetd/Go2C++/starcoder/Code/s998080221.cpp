
#include <bits/stdc++.h>

using namespace std;

// bufReader type is a custom reader that reads lines from os.Stdin
struct bufReader {
	// bufio.Reader instance
	bufio::Reader *r;
	// buffer for storing read lines
	char buf[1024];
	// index for the current position in the buffer
	int i;
	// Constructor for bufReader
	bufReader() {
		// Initialize bufio.Reader
		r = new bufio::Reader(cin.rdbuf());
		// Clear the buffer and set the index to 0
		memset(buf, 0, sizeof(buf));
		i = 0;
	}
	// Function readLine reads a line from os.Stdin and stores it in the buffer
	void readLine() {
		// If the index is less than the length of the buffer, it means that there is still some data left in the buffer
		if (i < sizeof(buf)) {
			return;
		}
		// Clear the buffer and set the index to 0
		memset(buf, 0, sizeof(buf));
		i = 0;
		// Read a line from os.Stdin and store it in the buffer
		while (true) {
			// Read a line from os.Stdin
			int len = r->readLine(buf, sizeof(buf));
			// If an error occurs during reading, panic with the error message
			if (len <= 0) {
				panic("Error reading line");
			}
			// If the line is not a prefix (i.e., it is a complete line), break the loop
			if (!r->isPrefix()) {
				break;
			}
		}
	}
	// Function next returns the next token (i.e., a word or a number) from the buffer
	string next() {
		// Read a line from the buffer
		readLine();
		// Find the index of the first whitespace character in the line
		int from = i;
		// Iterate through the line until a whitespace character is found
		while (i < sizeof(buf) && buf[i]!='') {
			i++;
		}
		// Return the substring from the start index to the current index
		string s(buf + from, i - from);
		// Increment the index
		i++;
		// Return the token
		return s;
	}
	// Function nextLine returns the next line from the buffer
	string nextLine() {
		// Read a line from the buffer
		readLine();
		// Return the substring from the current index to the end of the buffer
		string s(buf + i, sizeof(buf) - i);
		// Set the index to the end of the buffer
		i = sizeof(buf);
		// Return the line
		return s;
	}
};

// bufio.Writer is used for writing lines to os.Stdout
bufio::Writer *writer = new bufio::Writer(cout.rdbuf());

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
void out(string s) {
	// Write the formatted output to the bufio.Writer
	*writer << s << endl;
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
	// Create a stringstream object
	stringstream ss;
	// Initialize a boolean variable first to true
	bool first = true;
	// Iterate through the array
	for (int i = 0; i < a.size(); i++) {
		// If first is true, do not append a separator
		if (!first) {
			// Append the separator to the stringstream object
			ss << sep;
		}
		// Set first to false
		first = false;
		// Append the current element to the stringstream object
		ss << a[i];
	}
	// Return the stringstream object as a string
	return ss.str();
}

// Function joinInts joins an array of int values with a given separator and returns the resulting string
string joinInts(vector<int> a, string sep) {
	// Create a stringstream object
	stringstream ss;
	// Initialize a boolean variable first to true
	bool first = true;
	// Iterate through the array
	for (int i = 0; i < a.size(); i++) {
		// If first is true, do not append a separator
		if (!first) {
			// Append the separator to the stringstream object
			ss << sep;
		}
		// Set first to false
		first = false;
		// Append the current element to the stringstream object
		ss << a[i];
	}
	// Return the stringstream object as a string
	return ss.str();
}

// Function divUp64 returns the smallest integer n such that n*divisor >= dividend
int64_t divUp64(int64_t dividend, int64_t divisor) {
	// Return the smallest integer n such that n*divisor >= dividend
	return (dividend + divisor - 1) / divisor;
}

// Function divUp returns the smallest integer n such that n*divisor >= dividend
int divUp(int dividend, int divisor) {
	// Return the smallest integer n such that n*divisor >= dividend
	return int(divUp64(int64_t(dividend), int64_t(divisor)));
}

// Function gcd64 returns the greatest common divisor of two int64 values
int64_t gcd64(int64_t x, int64_t y) {
	// If x is greater than y, swap x and y
	if (x < y) {
		x, y = y, x;
	}
	// Iterate through the range of possible divisors
	for (int64_t d = y; d!= 0; d = x % y) {
		// Calculate the remainder of x/y
		x, y = y, x % y;
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
	return int64_t(pow(x, y));
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
	writer->flush();
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

