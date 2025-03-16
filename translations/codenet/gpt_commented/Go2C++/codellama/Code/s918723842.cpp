
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

// Function to return the maximum of two integers
int max(int a, int b) {
	if (a < b) {
		return b;
	}
	return a;
}

// Scanner struct to facilitate reading input
struct Scanner {
	string buf; // Buffer to hold the input data
	int p; // Current position in the buffer

	// Constructor to initialize the buffer
	Scanner() {
		buf = "";
		p = 0;
	}

	// Function to read the next token from the input
	string next() {
		pre(); // Ensure there is data to read
		int start = p; // Mark the start of the token
		while (p < buf.size()) {
			if (buf[p] == ' ') { // Stop at space character
				break;
			}
			p++;
		}
		string result = buf.substr(start, p - start); // Extract the token
		p++; // Move past the space
		return result; // Return the token
	}

	// Function to read the next line from the input
	string nextLine() {
		pre(); // Ensure there is data to read
		int start = p; // Mark the start of the line
		p = buf.size(); // Move to the end of the buffer
		return buf.substr(start); // Return the line
	}

	// Function to read the next integer from the input
	int nextInt() {
		return stoi(next()); // Convert the next token to an integer
	}

	// Function to read the next int64 from the input
	int64_t nextInt64() {
		return stoll(next()); // Convert the next token to int64
	}

	// Function to read the next float64 from the input
	double nextFloat() {
		return stod(next()); // Convert the next token to float64
	}

	// Function to read a slice of integers from the input
	vector<int> nextIntArray() {
		pre(); // Ensure there is data to read
		int start = p; // Mark the start of the array
		vector<int> result; // Initialize an empty slice to hold the integers
		while (p < buf.size() + 1) {
			if (p == buf.size() || buf[p] == ' ') { // Check for end of buffer or space
				int v = stoi(buf.substr(start, p - start)); // Parse the integer
				result.push_back(v); // Append to the result slice
				start = p + 1; // Update start for the next integer
			}
			p++;
		}
		return result; // Return the slice of integers
	}

	// Function to read a slice of int64 from the input
	vector<int64_t> nextInt64Array() {
		pre(); // Ensure there is data to read
		int start = p; // Mark the start of the array
		vector<int64_t> result; // Initialize an empty slice to hold the int64 values
		while (p < buf.size() + 1) {
			if (p == buf.size() || buf[p] == ' ') { // Check for end of buffer or space
				int64_t v = stoll(buf.substr(start, p - start)); // Parse the int64
				result.push_back(v); // Append to the result slice
				start = p + 1; // Update start for the next int64
			}
			p++;
		}
		return result; // Return the slice of int64
	}

	// Function to read a map of integers from the input
	map<int, bool> nextMap() {
		pre(); // Ensure there is data to read
		int start = p; // Mark the start of the map
		map<int, bool> mp; // Initialize an empty map
		while (p < buf.size()) {
			if (buf[p] == ' ') { // Check for space
				int v = stoi(buf.substr(start, p - start)); // Parse the integer
				mp[v] = true; // Add to the map
				start = p + 1; // Update start for the next integer
			}
			p++;
		}
		int v = stoi(buf.substr(start, p - start)); // Parse the last integer
		mp[v] = true; // Add the last integer to the map

		return mp; // Return the map
	}

	// Function to check if there is data to read and read a new line if necessary
	void pre() {
		if (p >= buf.size()) { // If current position is at the end of the buffer
			readLine(); // Read a new line
			p = 0; // Reset position to the start of the new line
		}
	}

	// Function to read a full line from the input and store it in the buffer
	void readLine() {
		buf = ""; // Reset the buffer
		while (true) {
			string l; // Declare a string to hold the line
			getline(cin, l); // Read a line from the input
			buf += l; // Append the line to the buffer
			if (!cin.good()) { // If there is an error
				panic(); // Panic
			}
			if (!cin.eof()) { // If this is not the last part of the line
				break; // Exit the loop
			}
		}
	}

	// Function to panic
	void panic() {
		cerr << "Error: Unexpected end of input" << endl;
		exit(1);
	}
};

int main() {
	// Create a new scanner to read input
	Scanner sc;

	// Read three integers from input: H, W, and N
	int H = sc.nextInt();
	int W = sc.nextInt();
	int N = sc.nextInt();

	// Calculate the maximum of H and W
	int A = max(H, W);

	// Calculate and print the number of full groups needed to accommodate N items
	cout << (N + A - 1) / A << endl;

	return 0;
}

