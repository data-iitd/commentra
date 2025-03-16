
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	// Initialize a new scanner to read input
	Scanner sc;

	// Read the number of elements
	int n = sc.NextInt();
	// Create a vector to hold the float values
	vector<float> arr(n);
	
	// Read n integers from input and convert them to float
	for (int i = 0; i < n; i++) {
		arr[i] = float(sc.NextInt());
	}
	
	// Sort the vector of float values
	sort(arr.begin(), arr.end());

	// Initialize 'prev' with the first element of the sorted vector
	float prev = arr[0];
	
	// Calculate the average of the elements iteratively
	for (int i = 1; i < arr.size(); i++) {
		prev = (prev + arr[i]) / 2;
	}

	// Print the final computed average
	cout << prev << endl;

	return 0;
}

// Scanner struct to handle input reading
struct Scanner {
	// Buffered reader for input
	istream* r;
	// Buffer to hold the input line
	string buf;
	// Current position in the buffer
	int p;

	// Initialize a new scanner with the input stream
	Scanner(istream& is = cin) : r(&is) {
		// Reset the buffer and position
		buf = "";
		p = 0;
	}

	// Read the next token from the input
	string Next() {
		// Ensure the buffer is filled
		pre();
		// Mark the start of the token
		int start = p;
		// Iterate through the buffer to find the next space
		while (p < buf.size()) {
			if (buf[p] == ' ') {
				break;
			}
			p++;
		}
		// Extract the token
		string result = buf.substr(start, p - start);
		// Move past the space
		p++;
		return result;
	}

	// Read the next line from the input
	string NextLine() {
		// Ensure the buffer is filled
		pre();
		// Mark the start of the line
		int start = p;
		// Move to the end of the buffer
		p = buf.size();
		// Return the line
		return buf.substr(start);
	}

	// Read the next integer from the input
	int NextInt() {
		// Convert the next token to an integer
		int v = stoi(Next());
		return v;
	}

	// Read a space-separated array of integers from the input
	vector<int> NextIntArray() {
		// Ensure the buffer is filled
		pre();
		// Mark the start of the first integer
		int start = p;
		// Initialize an empty vector for the integers
		vector<int> result;
		// Iterate through the buffer to find space-separated integers
		while (p < buf.size()) {
			if (buf[p] == ' ') {
				// Convert the token to an integer
				int v = stoi(buf.substr(start, p - start));
				// Append the integer to the result vector
				result.push_back(v);
				// Update the start position for the next integer
				start = p + 1;
			}
			p++;
		}
		// Convert the last token to an integer
		int v = stoi(buf.substr(start, p - start));
		// Append the last integer to the result vector
		result.push_back(v);

		return result;
	}

	// Read a space-separated map of integers to booleans from the input
	map<int, bool> NextMap() {
		// Ensure the buffer is filled
		pre();
		// Mark the start of the first integer
		int start = p;
		// Initialize an empty map
		map<int, bool> mp;
		// Iterate through the buffer to find space-separated integers
		while (p < buf.size()) {
			if (buf[p] == ' ') {
				// Convert the token to an integer
				int v = stoi(buf.substr(start, p - start));
				// Set the integer as a key in the map with a value of true
				mp[v] = true;
				// Update the start position for the next integer
				start = p + 1;
			}
			p++;
		}
		// Convert the last token to an integer
		int v = stoi(buf.substr(start, p - start));
		// Set the last integer as a key in the map
		mp[v] = true;

		return mp;
	}

	// pre checks if the buffer needs to be filled
	void pre() {
		if (p >= buf.size()) { // If the current position is at or beyond the buffer length
			readLine(); // Read a new line into the buffer
			p = 0; // Reset the position to the start of the buffer
		}
	}

	// readLine reads a full line from the input into the buffer
	void readLine() {
		// Reset the buffer
		buf = "";
		// Read a line from the buffered reader
		string l;
		while (getline(*r, l)) {
			buf += l;
			if (!l.back()) { // If the line is not a continuation
				break; // Exit the loop
			}
		}
	}
};

