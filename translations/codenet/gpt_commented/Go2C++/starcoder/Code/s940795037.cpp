#include <bits/stdc++.h>

using namespace std;

// Main function where the execution starts
int main() {
	// Create a new scanner to read input
	Scanner sc;

	// Read the number of integers to process
	int n = sc.NextInt();
	double ans = 0.0;

	// Loop through each integer, calculate the reciprocal, and accumulate the sum
	for (int i = 0; i < n; i++) {
		double tmp = 1 / (double)sc.NextInt();
		ans += tmp;
	}

	// Print the harmonic mean of the input integers
	cout << 1 / ans << endl;
}

// Scanner class to handle input reading efficiently
class Scanner {
public:
	// Read the next token from the input
	string Next() {
		pre(); // Ensure there is data to read
		start = p; // Mark the start position
		// Iterate through the buffer to find the next space
		for (; p < buf.size(); p++) {
			if (buf[p] =='') {
				break; // Stop at the first space
			}
		}
		string result = string(buf.begin() + start, buf.begin() + p); // Extract the token
		p++; // Move past the space
		return result; // Return the token
	}

	// Read the next full line from the input
	string NextLine() {
		pre(); // Ensure there is data to read
		start = p; // Mark the start position
		p = buf.size(); // Move to the end of the buffer
		return string(buf.begin() + start, buf.end()); // Return the line
	}

	// Read the next integer from the input
	int NextInt() {
		return atoi(Next().c_str()); // Convert the next token to an integer
	}

	// Read a space-separated array of integers from the input
	vector<int> NextIntArray() {
		pre(); // Ensure there is data to read
		start = p; // Mark the start position
		vector<int> result; // Initialize an empty vector for the results
		// Iterate through the buffer to find integers separated by spaces
		for (; p < buf.size(); p++) {
			if (buf[p] =='') {
				int v = atoi(string(buf.begin() + start, buf.begin() + p).c_str()); // Convert the token to an integer
				result.push_back(v); // Append the integer to the result vector
				start = p + 1; // Update the start position
			}
		}
		int v = atoi(string(buf.begin() + start, buf.begin() + p).c_str()); // Convert the last token to an integer
		result.push_back(v); // Append the last integer to the result vector

		return result; // Return the vector of integers
	}

	// Read a space-separated list of integers into a map
	map<int, bool> NextMap() {
		pre(); // Ensure there is data to read
		start = p; // Mark the start position
		map<int, bool> mp; // Initialize an empty map
		// Iterate through the buffer to find integers separated by spaces
		for (; p < buf.size(); p++) {
			if (buf[p] =='') {
				int v = atoi(string(buf.begin() + start, buf.begin() + p).c_str()); // Convert the token to an integer
				mp[v] = true; // Add the integer to the map
				start = p + 1; // Update the start position
			}
		}
		int v = atoi(string(buf.begin() + start, buf.begin() + p).c_str()); // Convert the last token to an integer
		mp[v] = true; // Add the last integer to the map

		return mp; // Return the map of integers
	}

private:
	// Ensure that there is data to read
	void pre() {
		if (p >= buf.size()) { // If the current position is at the end of the buffer
			readLine(); // Read a new line
			p = 0; // Reset the position to the start of the new line
		}
	}

	// Read a full line from the input and store it in the buffer
	void readLine() {
		buf.clear(); // Reset the buffer
		while (true) {
			char *l = new char[1000]; // Allocate a new line
			char *p = fgets(l, 1000, stdin); // Read a line from the standard input
			if (!p) {
				delete[] l; // Delete the line
				return; // Exit the loop
			}
			buf.insert(buf.end(), l, l + strlen(l)); // Append the line to the buffer
			if (!p[strlen(l) - 1]) { // If the line is not a continuation
				break; // Exit the loop
			}
			delete[] l; // Delete the line
		}
	}

	vector<char> buf; // Buffer to hold the input line
	int p, start; // Current position in the buffer and start position of the next token
};

