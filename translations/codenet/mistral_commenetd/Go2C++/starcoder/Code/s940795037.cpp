
#include <bits/stdc++.h>

using namespace std;

// Class definition
class Scanner {
public:
	// Constructor
	Scanner() {
		// Creating a new buffered reader instance
		rdr = new bufio::Reader();
		// Reading the first line from the standard input
		rdr->read_line(&buf, 1000);
		// Setting the position of the input buffer pointer to the beginning of the input buffer
		p = 0;
	}

	// Function to read the next token
	string Next() {
		// Preprocessing the input buffer
		pre();
		// Initializing the start position of the token
		int start = p;
		// Iterating through the input buffer
		for (; p < len(buf); p++) {
			// Checking if the current character is a whitespace character
			if (buf[p] =='') {
				// If yes, then setting the end position of the token
				break;
			}
		}
		// Reading the token from the input buffer
		string result = string(buf.begin() + start, buf.begin() + p);
		// Incrementing the position of the input buffer pointer
		p++;
		// Returning the token
		return result;
	}

	// Function to read the next line
	string NextLine() {
		// Preprocessing the input buffer
		pre();
		// Initializing the start position of the line
		int start = p;
		// Setting the position of the input buffer pointer to the end of the input buffer
		p = len(buf);
		// Reading the rest of the line if available
		readLine();
		// Creating a slice from the current position to the end of the input buffer
		string result = string(buf.begin() + start, buf.end());
		// Returning the line
		return result;
	}

	// Function to read the next integer
	int NextInt() {
		// Reading the next token as a string
		string token = Next();
		// Converting the token to an integer
		int v, _ = stoi(token);
		// Returning the integer
		return v;
	}

	// Function to read an array of integers
	vector<int> NextIntArray() {
		// Reading the next token as a string
		string token = Next();
		// Initializing an empty vector
		vector<int> result;
		// Reading each integer from the standard input and appending it to the vector
		for (int i = 0; i < token.length(); i++) {
			// Checking if the current character is an integer
			if (token[i] >= '0' && token[i] <= '9') {
				// If yes, then converting the character to an integer and appending it to the vector
				result.push_back(token[i] - '0');
				// Reading the next character
				token = Next();
				// If the current character is not a space character, then there is an error in the input
				if (token[0]!='') {
					throw invalid_argument("Invalid input");
				}
			} else {
				// If the current character is not an integer, then the input is invalid
				throw invalid_argument("Invalid input");
			}
		}
		// Returning the vector
		return result;
	}

	// Function to read a map
	map<int, bool> NextMap() {
		// Reading the next token as a string
		string token = Next();
		// Initializing an empty map
		map<int, bool> mp;
		// Reading each key-value pair from the standard input and adding it to the map
		for (int i = 0; i < token.length(); i++) {
			// Checking if the current character is an integer
			if (token[i] >= '0' && token[i] <= '9') {
				// If yes, then converting the character to an integer and adding it as a key to the map
				int k, _ = stoi(token);
				mp[k] = true;
				// Reading the next character
				token = Next();
				// If the current character is not a colon character, then there is an error in the input
				if (token[0]!= ':') {
					throw invalid_argument("Invalid input");
				}
				// Reading the next character as a boolean value
				bool v = (token == "true");
				// Adding the value to the map
				mp[k] = v;
				// If the current character is not a space character, then there is an error in the input
				if (token[0]!='') {
					throw invalid_argument("Invalid input");
				}
			} else {
				// If the current character is not an integer, then the input is invalid
				throw invalid_argument("Invalid input");
			}
		}
		// Returning the map
		return mp;
	}

private:
	// Function to preprocess the input buffer
	void pre() {
		// If the position of the input buffer pointer is at the end of the buffer, then reading the next line from the standard input
		if (p >= len(buf)) {
			readLine();
			p = 0;
		}
	}

	// Function to read a line from the standard input and store it in the input buffer
	void readLine() {
		// Reading a line from the standard input
		int len = rdr->read_line(&buf, 1000);
		// If there is an error, then panicking
		if (len < 0) {
			throw invalid_argument("Invalid input");
		}
	}

	// Buffered reader instance
	bufio::Reader *rdr;
	// Input buffer
	vector<char> buf;
	// Position of the input buffer pointer
	int p;
};

// Main function
int main() {
	// Creating a new scanner instance
	Scanner sc;

	// Reading the first integer from the standard input
	int n = sc.NextInt();
	// Initializing the answer variable
	double ans = 0.0;

	// Iterating through the given number of integers
	for (int i = 0; i < n; i++) {
		// Reading the next integer from the standard input
		int tmp = 1 / sc.NextInt();
		// Adding the reciprocal of the current integer to the answer
		ans += 1.0 / tmp;
	}

	// Printing the final answer
	cout << 1.0 / ans << endl;

	// Returning from the main function
	return 0;
}

