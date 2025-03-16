#include <bits/stdc++.h>

using namespace std;

// bufReader struct to handle buffered reading from standard input
struct bufReader {
	std::istream *stream; // Pointer to input stream
	std::vector<char> buf; // Buffer to hold read bytes
	int i;                 // Current index in the buffer
};

// Initialize a global bufReader instance for reading input
bufReader reader{&cin};

// readLine reads a line from the buffered reader into the buffer
void readLine() {
	if (reader.i < reader.buf.size()) {
		return; // Return if there are still bytes to read
	}
	reader.buf.clear(); // Reset buffer
	reader.i = 0;        // Reset index
	std::getline(*reader.stream, reader.buf, (char) 10); // Read a line
}

// next reads the next token from the buffer
std::string next() {
	readLine(); // Ensure the buffer is filled
	std::string s;
	std::istringstream iss{std::string(reader.buf.begin() + reader.i, reader.buf.end())};
	iss >> s;
	reader.i += s.length() + 1; // Move index to the end of the token
	return s;
}

// nextInt64 reads the next token as an int64
int64_t nextInt64() {
	int64_t i;
	std::istringstream iss{next()};
	iss >> i;
	return i;
}

// nextInt reads the next token as an int
int nextInt() {
	return (int) nextInt64();
}

// nextLine is a helper function to read the next full line
std::string nextLine() {
	std::string s;
	std::getline(*reader.stream, s); // Read a line
	return s;
}

// out writes the output to the writer
void out(std::string s) {
	std::cout << s << std::endl;
}

// max64 returns the maximum of two int64 values
int64_t max64(int64_t x, int64_t y) {
	return x > y? x : y;
}

// max returns the maximum of two int values
int max(int x, int y) {
	return x > y? x : y;
}

// min64 returns the minimum of two int64 values
int64_t min64(int64_t x, int64_t y) {
	return x < y? x : y;
}

// min returns the minimum of two int values
int min(int x, int y) {
	return x < y? x : y;
}

// abs64 returns the absolute value of an int64
int64_t abs64(int64_t x) {
	return x < 0? -x : x;
}

// abs returns the absolute value of an int
int abs(int x) {
	return x < 0? -x : x;
}

// joinInt64s joins a slice of int64s into a string with a separator
std::string joinInt64s(std::vector<int64_t> a, std::string sep) {
	std::string s;
	for (int i = 0; i < a.size(); i++) {
		s += std::to_string(a[i]);
		if (i < a.size() - 1) {
			s += sep;
		}
	}
	return s;
}

// joinInts joins a slice of ints into a string with a separator
std::string joinInts(std::vector<int> a, std::string sep) {
	std::string s;
	for (int i = 0; i < a.size(); i++) {
		s += std::to_string(a[i]);
		if (i < a.size() - 1) {
			s += sep;
		}
	}
	return s;
}

// divUp64 performs ceiling division on two int64 values
int64_t divUp64(int64_t x, int64_t y) {
	return (x + y - 1) / y;
}

// divUp performs ceiling division on two int values
int divUp(int x, int y) {
	return (int) divUp64(x, y);
}

// gcd64 computes the greatest common divisor of two int64 values
int64_t gcd64(int64_t x, int64_t y) {
	if (x < y) {
		x, y = y, x; // Ensure x is the larger value
	}
	while (y!= 0) {
		x, y = y, x % y; // Euclidean algorithm
	}
	return x; // Return GCD
}

// gcd computes the greatest common divisor of two int values
int gcd(int x, int y) {
	return (int) gcd64(x, y);
}

// lcm64 computes the least common multiple of two int64 values
int64_t lcm64(int64_t x, int64_t y) {
	return x * y / gcd64(x, y);
}

// lcm computes the least common multiple of two int values
int lcm(int x, int y) {
	return (int) lcm64(x, y);
}

// pow64 computes x raised to the power of y for int64 values
int64_t pow64(int64_t x, int64_t y) {
	return (int64_t) std::pow(x, y);
}

// pow computes x raised to the power of y for int values
int pow(int x, int y) {
	return (int) pow64(x, y);
}

// main function to execute the program
int main() {
	solve(); // Call the solve function
	return 0;
}

// solve function to compute the maximum profit and count
void solve() {
	int N, _; // Read number of elements and ignore the second value
	std::cin >> N >> _;
	std::vector<int> A(N); // Create a slice to hold the elements
	for (int i = 0; i < N; i++) {
		std::cin >> A[i]; // Read each element into the slice
	}
	int maxProfit = 0; // Initialize maximum profit
	int maxCnt = 0;    // Initialize count of maximum profit occurrences
	int maxA = A[N - 1]; // Start with the last element as the maximum
	for (int i = N - 2; i >= 0; i--) { // Iterate backwards through the slice
		int profit = max(0, maxA - A[i]); // Calculate profit based on the current element
		if (maxProfit < profit) { // If we found a new maximum profit
			maxProfit = profit; // Update maximum profit
			maxCnt = 1;         // Reset count to 1
		} else if (maxProfit == profit) { // If we found another occurrence of the maximum profit
			maxCnt++; // Increment the count
		}
		maxA = max(maxA, A[i]); // Update the maximum element seen so far
	}
	out(maxCnt); // Output the count of maximum profit occurrences
}

