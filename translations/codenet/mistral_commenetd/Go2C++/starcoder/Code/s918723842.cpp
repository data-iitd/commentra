
#include <bits/stdc++.h>

using namespace std;

// Scanner struct represents the input reader.
struct Scanner {
	// bufio.Reader field r is used for reading from the standard input.
	bufio::Reader *r;
	// buf byte slice buffer is used for storing the input line.
	char buf[1000];
	// p integer p keeps track of the current position in the buffer.
	int p;
};

// NewScanner function initializes a new Scanner object with the standard input os.Stdin as the reader.
Scanner *NewScanner() {
	// Initialize a new bufio.Reader object named rdr with the standard input as the I/O source.
	bufio::Reader *rdr = new bufio::Reader(cin.rdbuf());
	// Initialize a new Scanner object named s with the rdr as the reader field.
	Scanner *s = new Scanner();
	s->r = rdr;
	// Return the initialized Scanner object.
	return s;
}

// Next method reads the next token from the input, which can be a single word, number, or symbol.
// It skips leading whitespaces and returns the result as a string.
string Next(Scanner *s) {
	// Set the current position p to the beginning of the buffer if it's at the end.
	s->pre();
	// Start index of the token in the buffer.
	int start = s->p;
	// Read the input until a non-whitespace character is found.
	for (; s->p < sizeof(s->buf); s->p++) {
		// If the current character is a whitespace, break the loop.
		if (s->buf[s->p] =='') {
			break;
		}
	}
	// Read the token, including the whitespace character if any.
	string result = string(s->buf + start, s->p - start);
	// Increment the current position p.
	s->p++;
	// Return the result.
	return result;
}

// NextLine method reads the next line from the input and returns it as a string.
string NextLine(Scanner *s) {
	// Set the current position p to the beginning of the buffer if it's at the end.
	s->pre();
	// Start index of the line in the buffer.
	int start = s->p;
	// Read the input until the end of the line is reached.
	for (; s->p < sizeof(s->buf); s->p++) {
		// If the current character is a newline character, break the loop.
		if (s->buf[s->p] == '\n') {
			break;
		}
	}
	// Read the line, including the newline character if any.
	string result = string(s->buf + start, s->p - start);
	// Increment the current position p.
	s->p++;
	// Return the result.
	return result;
}

// NextInt method reads an integer from the input and returns it.
int NextInt(Scanner *s) {
	// Read the next token as a string.
	string token = Next(s);
	// Parse the token as an integer and return the result.
	int v;
	istringstream iss(token);
	iss >> v;
	return v;
}

// NextInt64 method reads a 64-bit integer from the input and returns it.
int64_t NextInt64(Scanner *s) {
	// Read the next token as a string.
	string token = Next(s);
	// Parse the token as a 64-bit integer and return the result.
	int64_t v;
	istringstream iss(token);
	iss >> v;
	return v;
}

// NextFloat method reads a floating-point number from the input and returns it.
double NextFloat(Scanner *s) {
	// Read the next token as a string.
	string token = Next(s);
	// Parse the token as a floating-point number and return the result.
	double v;
	istringstream iss(token);
	iss >> v;
	return v;
}

// NextIntArray method reads an array of integers from the input and returns it.
vector<int> NextIntArray(Scanner *s) {
	// Read the next line as a string.
	string line = NextLine(s);
	// Split the line into tokens using spaces as delimiters.
	vector<string> tokens = split(line, " ");
	// Parse each token as an integer and append it to the result slice.
	vector<int> result;
	for (int i = 0; i < tokens.size(); i++) {
		int v;
		istringstream iss(tokens[i]);
		iss >> v;
		result.push_back(v);
	}
	// Return the result.
	return result;
}

// NextInt64Array method reads an array of 64-bit integers from the input and returns it.
vector<int64_t> NextInt64Array(Scanner *s) {
	// Read the next line as a string.
	string line = NextLine(s);
	// Split the line into tokens using spaces as delimiters.
	vector<string> tokens = split(line, " ");
	// Parse each token as a 64-bit integer and append it to the result slice.
	vector<int64_t> result;
	for (int i = 0; i < tokens.size(); i++) {
		int64_t v;
		istringstream iss(tokens[i]);
		iss >> v;
		result.push_back(v);
	}
	// Return the result.
	return result;
}

// NextMap method reads a map from the input and returns it.
map<int, bool> NextMap(Scanner *s) {
	// Read the next line as a string.
	string line = NextLine(s);
	// Split the line into tokens using spaces as delimiters.
	vector<string> tokens = split(line, " ");
	// Parse each token as an integer and create a key-value pair.
	map<int, bool> mp;
	for (int i = 0; i < tokens.size(); i++) {
		int key;
		istringstream iss(tokens[i]);
		string token;
		getline(iss, token, ':');
		iss >> key;
		mp[key] = true;
	}
	// Return the result.
	return mp;
}

// pre method sets the current position p to the beginning of the buffer if it's at the end.
void pre(Scanner *s) {
	// If the current position p is at the end of the buffer, read the next line.
	if (s->p >= sizeof(s->buf)) {
		s->readLine();
		s->p = 0;
	}
}

// readLine method reads a line from the input and appends it to the buffer.
void readLine(Scanner *s) {
	// Read a line from the input using the bufio.Reader.
	string line;
	getline(*s->r, line);
	// Append the line to the buffer.
	strcpy(s->buf, line.c_str());
}

// split function splits a string s into tokens using the delimiter d.
vector<string> split(string s, string d) {
	// Split the string s using the delimiter d.
	vector<string> tokens;
	string token;
	istringstream iss(s);
	while (getline(iss, token, d[0])) {
		tokens.push_back(token);
	}
	// Return the result.
	return tokens;
}

// 