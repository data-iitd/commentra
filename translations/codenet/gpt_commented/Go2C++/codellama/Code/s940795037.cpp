
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

// Scanner struct to handle input reading efficiently
struct Scanner {
	string buf; // Buffer to hold the input line
	int p; // Current position in the buffer

	// Read the next token from the input
	string Next() {
		pre(); // Ensure there is data to read
		int start = p; // Mark the start position
		// Iterate through the buffer to find the next space
		while (p < buf.size()) {
			if (buf[p] == ' ') {
				break; // Stop at the first space
			}
			p++;
		}
		string result = buf.substr(start, p - start); // Extract the token
		p++; // Move past the space
		return result; // Return the token
	}

	// Read the next line from the input
	string NextLine() {
		pre(); // Ensure there is data to read
		int start = p; // Mark the start position
		p = buf.size(); // Move to the end of the buffer
		return buf.substr(start); // Return the line
	}

	// Read the next integer from the input
	int NextInt() {
		return stoi(Next()); // Convert the next token to an integer
	}

	// Read a space-separated array of integers from the input
	vector<int> NextIntArray() {
		pre(); // Ensure there is data to read
		int start = p; // Mark the start position
		vector<int> result; // Initialize an empty slice for the results
		// Iterate through the buffer to find integers separated by spaces
		while (p < buf.size()) {
			if (buf[p] == ' ') {
				int v = stoi(buf.substr(start, p - start)); // Convert the token to an integer
				result.push_back(v); // Append the integer to the result slice
				start = p + 1; // Update the start position
			}
			p++;
		}
		int v = stoi(buf.substr(start, p - start)); // Convert the last token to an integer
		result.push_back(v); // Append the last integer to the result slice

		return result; // Return the slice of integers
	}

	// Read a space-separated list of integers into a map
	map<int, bool> NextMap() {
		pre(); // Ensure there is data to read
		int start = p; // Mark the start position
		map<int, bool> mp; // Initialize an empty map
		// Iterate through the buffer to find integers separated by spaces
		while (p < buf.size()) {
			if (buf[p] == ' ') {
				int v = stoi(buf.substr(start, p - start)); // Convert the token to an integer
				mp[v] = true; // Add the integer to the map
				start = p + 1; // Update the start position
			}
			p++;
		}
		int v = stoi(buf.substr(start, p - start)); // Convert the last token to an integer
		mp[v] = true; // Add the last integer to the map

		return mp; // Return the map of integers
	}

	// pre checks if there is data to read and reads a new line if necessary
	void pre() {
		if (p >= buf.size()) { // If the current position is at the end of the buffer
			readLine(); // Read a new line
			p = 0; // Reset the position to the start of the new line
		}
	}

	// readLine reads a full line from the input and stores it in the buffer
	void readLine() {
		buf = ""; // Reset the buffer
		while (true) {
			string l; // Declare a string to hold the line
			bool p; // Declare a boolean to hold the continuation status
			// Read a line from the buffered reader
			getline(cin, l, '\n');
			buf += l; // Append the line to the buffer
			if (!p) { // If the line is not a continuation
				break; // Exit the loop
			}
		}
	}
};

int main() {
	Scanner sc; // Create a new scanner to read input

	int n = sc.NextInt(); // Read the number of integers to process
	double ans = 0.0; // Initialize the sum

	// Loop through each integer, calculate the reciprocal, and accumulate the sum
	for (int i = 0; i < n; i++) {
		double tmp = 1 / sc.NextInt();
		ans += tmp;
	}

	// Print the harmonic mean of the input integers
	cout << 1 / ans << endl;

	return 0;
}

