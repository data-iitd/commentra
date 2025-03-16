
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

// scanner struct to handle buffered input reading
struct scanner {
	string buf; // Buffer to hold the input data
	int p; // Current position in the buffer
	
	// newScanner initializes a new scanner with a specified buffer size
	scanner() {
		p = 0;
	}
	
	// next reads the next word from the input
	string next() {
		pre(); // Ensure the buffer is filled
		int start = p; // Mark the start of the word
		// Iterate through the buffer until a space is found
		while (p < buf.size()) {
			if (buf[p] == ' ') {
				break;
			}
			p++;
		}
		string result = buf.substr(start, p - start); // Extract the word
		p++; // Move past the space
		return result; // Return the word
	}
	
	// nextLine reads the next line from the input
	string nextLine() {
		pre(); // Ensure the buffer is filled
		int start = p; // Mark the start of the line
		p = buf.size(); // Move to the end of the buffer
		return buf.substr(start); // Return the line
	}
	
	// nextInt reads the next integer from the input
	int nextInt() {
		return stoi(next()); // Convert the next word to an integer
	}
	
	// nextIntArray reads a space-separated array of integers from the input
	vector<int> nextIntArray() {
		pre(); // Ensure the buffer is filled
		int start = p; // Mark the start of the array
		vector<int> result; // Initialize an empty slice for the results
		// Iterate through the buffer to extract integers
		while (p < buf.size() + 1) {
			if (p == buf.size() || buf[p] == ' ') {
				int v = stoi(buf.substr(start, p - start)); // Parse the integer
				result.push_back(v); // Append the integer to the result slice
				start = p + 1; // Update the start position for the next integer
			}
			p++;
		}
		return result; // Return the slice of integers
	}
	
	// pre checks if the buffer needs to be filled
	void pre() {
		if (p >= buf.size()) { // If the current position is at or beyond the buffer length
			readLine(); // Read a new line into the buffer
			p = 0; // Reset the position to the start of the buffer
		}
	}
	
	// readLine reads a line from the input and fills the buffer
	void readLine() {
		buf = ""; // Reset the buffer
		while (true) {
			string l; // Declare a string to hold the line
			getline(cin, l); // Read a line from the input
			buf += l; // Append the line to the buffer
			if (l.size() < 1000) { // If the line is complete
				break; // Exit the loop
			}
		}
	}
};

int main() {
	// Create a new scanner to read input
	scanner sc;
	
	// Read a string from the input
	string S = sc.next();
	
	// Check if the string starts with "YAKI" and print the corresponding response
	if (S.find("YAKI") == 0) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	
	return 0;
}

