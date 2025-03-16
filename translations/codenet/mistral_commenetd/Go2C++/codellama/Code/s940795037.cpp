
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstdlib>

using namespace std;

// Defining the scanner class
class Scanner {
private:
	// Defining the reader instance
	istream *r;
	// Defining the input buffer
	string buf;
	// Defining the position of the input buffer pointer
	int p;
public:
	// Constructor
	Scanner() {
		// Initializing the reader instance
		r = &cin;
		// Initializing the input buffer
		buf = "";
		// Initializing the position of the input buffer pointer
		p = 0;
	}
	// Function to read the next token from the standard input
	string Next() {
		// Preprocessing the input buffer
		pre();
		// Reading the next token from the input buffer
		int start = p;
		for (; p < buf.size(); p++) {
			// Checking if the current character is a whitespace character
			if (buf[p] == ' ') {
				// If yes, then setting the end position of the token
				break;
			}
		}
		// Reading the token from the input buffer
		string result = buf.substr(start, p - start);
		// Incrementing the position of the input buffer pointer
		p++;
		// Returning the token
		return result;
	}
	// Function to read the next line from the standard input
	string NextLine() {
		// Preprocessing the input buffer
		pre();
		// Reading the next line from the input buffer
		int start = p;
		p = buf.size();
		// Reading the rest of the line if available
		readLine();
		// Creating a slice from the current position to the end of the input buffer
		string result = buf.substr(start);
		// Returning the line
		return result;
	}
	// Function to read the next integer from the standard input
	int NextInt() {
		// Reading the next token as a string
		string token = Next();
		// Converting the token to an integer
		int v = atoi(token.c_str());
		// Returning the integer
		return v;
	}
	// Function to read an array of integers from the standard input
	vector<int> NextIntArray() {
		// Reading the next token as a string
		string token = Next();
		// Initializing an empty vector
		vector<int> result;
		// Reading each integer from the standard input and appending it to the vector
		for (;;) {
			// Checking if the current token is an integer
			if (token.size() > 0 && token[token.size() - 1] >= '0' && token[token.size() - 1] <= '9') {
				// If yes, then converting the token to an integer and appending it to the vector
				int v = atoi(token.c_str());
				result.push_back(v);
				// Reading the next token
				token = Next();
				// If the current token is not a space character, then there is an error in the input
				if (token[0] != ' ') {
					panic("Invalid input");
				}
			} else {
				// If the current token is not an integer, then the input is invalid
				panic("Invalid input");
			}
		}
		// Returning the vector
		return result;
	}
	// Function to read a map from the standard input
	map<int, bool> NextMap() {
		// Reading the next token as a string
		string token = Next();
		// Initializing an empty map
		map<int, bool> mp;
		// Reading each key-value pair from the standard input and adding it to the map
		for (;;) {
			// Checking if the current token is an integer
			if (token.size() > 0 && token[token.size() - 1] >= '0' && token[token.size() - 1] <= '9') {
				// If yes, then converting the token to an integer and adding it as a key to the map
				int k = atoi(token.c_str());
				mp[k] = true;
				// Reading the next token
				token = Next();
				// If the current token is not a colon character, then there is an error in the input
				if (token[0] != ':') {
					panic("Invalid input");
				}
				// Reading the next token as a boolean value
				bool v = Next() == "true";
				// Adding the value to the map
				mp[k] = v;
				// If the current token is not a space character, then there is an error in the input
				if (token[0] != ' ') {
					panic("Invalid input");
				}
			} else {
				// If the current token is not an integer, then the input is invalid
				panic("Invalid input");
			}
			// Checking if the next token is the end of the input
			if (token == "") {
				break;
			}
		}
		// Returning the map
		return mp;
	}
	// Function to preprocess the input buffer
	void pre() {
		// If the position of the input buffer pointer is at the end of the buffer, then reading the next line from the standard input
		if (p >= buf.size()) {
			readLine();
			p = 0;
		}
	}
	// Function to read a line from the standard input and store it in the input buffer
	void readLine() {
		// Reading a line from the standard input
		string l;
		getline(*r, l);
		// Appending the line to the input buffer
		buf += l;
		// Setting the position of the input buffer pointer to the end of the line
		p = buf.size();
	}
};

// Function to panic
void panic(string s) {
	// Printing the error message
	cout << s << endl;
	// Exiting the program
	exit(1);
}

int main() {
	// Creating a new scanner instance
	Scanner sc = Scanner();
	// Reading the first integer from the standard input
	int n = sc.NextInt();
	// Initializing the answer variable
	double ans = 0.0;
	// Iterating through the given number of integers
	for (int i = 0; i < n; i++) {
		// Reading the next integer from the standard input
		double tmp = 1 / sc.NextInt();
		// Adding the reciprocal of the current integer to the answer
		ans += tmp;
	}
	// Printing the final answer
	cout << 1 / ans << endl;
	// End of code
	return 0;
}

