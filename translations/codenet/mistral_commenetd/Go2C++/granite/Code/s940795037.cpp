
// C++ code to solve the problem
#include <bits/stdc++.h>
using namespace std;

// Function to read the next token from the standard input
string nextToken() {
	// Preprocessing the input buffer
	static char buf[1000];
	static int p = 0;
	if (p >= strlen(buf)) {
		fgets(buf, 1000, stdin);
		p = 0;
	}
	// Reading the next token from the input buffer
	string result = "";
	while (buf[p]!='' && buf[p]!= '\n') {
		result += buf[p];
		p++;
	}
	p++;
	return result;
}

// Function to read the next integer from the standard input
int nextInt() {
	// Reading the next token as a string
	string token = nextToken();
	// Converting the token to an integer
	int v = stoi(token);
	// Returning the integer
	return v;
}

// Function to read an array of integers from the standard input
vector<int> nextIntArray() {
	// Reading the next token as a string
	string token = nextToken();
	// Initializing an empty vector
	vector<int> result;
	// Reading each integer from the standard input and appending it to the vector
	while (token[token.length() - 1] >= '0' && token[token.length() - 1] <= '9') {
		// Converting the token to an integer and appending it to the vector
		int v = stoi(token);
		result.push_back(v);
		// Reading the next token
		token = nextToken();
		// If the current token is not a space character, then there is an error in the input
		if (token[0]!='') {
			cerr << "Invalid input" << endl;
			exit(1);
		}
	}
	// Returning the vector
	return result;
}

// Function to read a map from the standard input
map<int, bool> nextMap() {
	// Reading the next token as a string
	string token = nextToken();
	// Initializing an empty map
	map<int, bool> mp;
	// Reading each key-value pair from the standard input and adding it to the map
	while (token[token.length() - 1] >= '0' && token[token.length() - 1] <= '9') {
		// Converting the token to an integer and adding it as a key to the map
		int k = stoi(token);
		mp[k] = true;
		// Reading the next token
		token = nextToken();
		// If the current token is not a colon character, then there is an error in the input
		if (token[0]!= ':') {
			cerr << "Invalid input" << endl;
			exit(1);
		}
		// Reading the next token as a boolean value
		bool v = (token == "true");
		// Adding the value to the map
		mp[k] = v;
		// If the current token is not a space character, then there is an error in the input
		if (token[0]!='') {
			cerr << "Invalid input" << endl;
			exit(1);
		}
		// Reading the next token
		token = nextToken();
	}
	// Returning the map
	return mp;
}

int main() {
	// Creating a new scanner instance
	Scanner sc;

	// Reading the first integer from the standard input
	int n = sc.nextInt();
	// Initializing the answer variable
	double ans = 0.0;

	// Iterating through the given number of integers
	for (int i = 0; i < n; i++) {
		// Reading the next integer from the standard input
		int tmp = 1 / sc.nextInt();
		// Adding the reciprocal of the current integer to the answer
		ans += tmp;
	}

	// Printing the final answer
	cout << 1 / ans << endl;

	return 0;
}

// Scanner class definition
class Scanner {
private:
	// Buffer to store the input
	char buf[1000];
	// Position of the input buffer pointer
	int p;
public:
	// Constructor to initialize the input buffer
	Scanner() {
		p = 0;
	}

	// Function to read the next token from the standard input
	string nextToken() {
		// Preprocessing the input buffer
		if (p >= strlen(buf)) {
			fgets(buf, 1000, stdin);
			p = 0;
		}
		// Reading the next token from the input buffer
		string result = "";
		while (buf[p]!='' && buf[p]!= '\n') {
			result += buf[p];
			p++;
		}
		p++;
		return result;
	}

	// Function to read the next integer from the standard input
	int nextInt() {
		// Reading the next token as a string
		string token = nextToken();
		// Converting the token to an integer
		int v = stoi(token);
		// Returning the integer
		return v;
	}

	// Function to read an array of integers from the standard input
	vector<int> nextIntArray() {
		// Reading the next token as a string
		string token = nextToken();
		// Initializing an empty vector
		vector<int> result;
		// Reading each integer from the standard input and appending it to the vector
		while (token[token.length() - 1] >= '0' && token[token.length() - 1] <= '9') {
			// Converting the token to an integer and appending it to the vector
			int v = stoi(token);
			result.push_back(v);
			// Reading the next token
			token = nextToken();
			// If the current token is not a space character, then there is an error in the input
			if (token[0]!='') {
				cerr << "Invalid input" << endl;
				exit(1);
			}
		}
		// Returning the vector
		return result;
	}

	// Function to read a map from the standard input
	map<int, bool> nextMap() {
		// Reading the next token as a string
		string token = nextToken();
		// Initializing an empty map
		map<int, bool> mp;
		// Reading each key-value pair from the standard input and adding it to the map
		while (token[token.length() - 1] >= '0' && token[token.length() - 1] <= '9') {
			// Converting the token to an integer and adding it as a key to the map
			int k = stoi(token);
			mp[k] = true;
			// Reading the next token
			token = nextToken();
			// If the current token is not a colon character, then there is an error in the input
			if (token[0]!= ':') {
				cerr << "Invalid input" << endl;
				exit(1);
			}
			// Reading the next token as a boolean value
			bool v = (token == "true");
			// Adding the value to the map
			mp[k] = v;
			// If the current token is not a space character, then there is an error in the input
			if (token[0]!='') {
				cerr << "Invalid input" << endl;
				exit(1);
			}
			// Reading the next token
			token = nextToken();
		}
		// Returning the map
		return mp;
	}
};