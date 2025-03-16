#include <bits/stdc++.h>

using namespace std;

// bufReader struct to handle buffered reading from standard input
struct bufReader {
	std::istream *r; // Pointer to input stream
	std::vector<char> buf; // Buffer to hold the read data
	int i; // Current index in the buffer
};

// Initialize a global bufReader instance for reading input
bufReader reader{&cin};

// readLine reads a line from the buffered reader into the buffer
void readLine() {
	// If the current index is less than the buffer length, return (buffer already filled)
	if (i < buf.size()) {
		return;
	}
	buf.clear(); // Reset the buffer
	i = 0; // Reset the index
	for (std::string s; std::getline(*reader.r, s);) {
		buf.insert(buf.end(), s.begin(), s.end()); // Append the line to the buffer
		if (!s.empty() && s.back() == '\n') { // If the line is not a prefix, break the loop
			break;
		}
	}
}

// next retrieves the next token from the buffer
std::string next() {
	readLine(); // Ensure the buffer is filled
	auto from = i; // Store the starting index of the token
	// Iterate through the buffer until a space is found
	for (; i < buf.size(); i++) {
		if (buf[i] =='') {
			break; // Break on space
		}
	}
	auto s = std::string(buf.begin() + from, buf.begin() + i); // Extract the token from the buffer
	i++; // Move the index forward
	return s; // Return the token
}

// nextLine retrieves the next line from the buffer
std::string nextLine() {
	readLine(); // Ensure the buffer is filled
	auto s = std::string(buf.begin() + i, buf.end()); // Get the remaining part of the buffer as a string
	i = buf.size(); // Set index to the end of the buffer
	return s; // Return the line
}

// Initialize a global buffered writer for output
std::ostream writer{&cout};

// next is a wrapper to get the next token as a string
std::string next() {
	return reader.next(); // Call the next method of bufReader
}

// nextInt retrieves the next token and converts it to an int64
int64_t nextInt() {
	auto i = next(); // Get the next token
	if (i.empty()) { // If the token is empty
		return 0; // Return 0
	}
	return stoll(i); // Convert the token to an int64_t
}

// nextLine is a wrapper to get the next line as a string
std::string nextLine() {
	return reader.nextLine(); // Call the nextLine method of bufReader
}

// out prints the output to the buffered writer
void out(const std::string &s) {
	writer << s << '\n'; // Print the string to the writer
}

// max returns the maximum of two int64 values
int64_t max(int64_t x, int64_t y) {
	return x > y? x : y; // Return x if it is greater
}

// min returns the minimum of two int64 values
int64_t min(int64_t x, int64_t y) {
	return x < y? x : y; // Return x if it is lesser
}

// joinInts converts a slice of int64 to a string with a separator
std::string joinInts(const std::vector<int64_t> &a, const std::string &sep) {
	std::vector<std::string> b(a.size()); // Create a string slice to hold the converted integers
	for (size_t i = 0; i < a.size(); i++) {
		b[i] = std::to_string(a[i]); // Convert each int64 to string
	}
	return join(b, sep); // Join the strings with the specified separator
}

// divUp performs ceiling division of x by y
int64_t divUp(int64_t x, int64_t y) {
	return (x + y - 1) / y; // Return the result of ceiling division
}

// main function where the program execution starts
int main() {
	solve(); // Call the solve function to execute the main logic
	return 0;
}

// solve contains the main logic for processing input and producing output
void solve() {
	auto N = nextInt(); // Read the number of pairs
	std::vector<int64_t> T(N), A(N); // Initialize slices for T and A
	// Read pairs of integers into T and A
	for (size_t i = 0; i < N; i++) {
		T[i], A[i] = nextInt(), nextInt(); // Read each pair
	}
	auto t = T[0], a = A[0]; // Initialize t and a with the first pair
	// Iterate through the remaining pairs to compute the required values
	for (size_t i = 1; i < N; i++) {
		auto r = max(divUp(t, T[i]), divUp(a, A[i])); // Calculate the required multiplier
		t, a = T[i] * r, A[i] * r; // Update t and a based on the multiplier
	}
	out(std::to_string(t + a)); // Output the final result
}

