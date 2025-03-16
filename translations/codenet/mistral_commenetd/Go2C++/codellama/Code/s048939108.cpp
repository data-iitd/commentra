
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

// Initialize a new scanner
void main() {
	scanner sc;

	// Read the first string from the standard input
	string S = sc.next();

	// Check if the string starts with "YAKI"
	if (S.find("YAKI") == 0) {
		cout << "Yes" << endl; // Print "Yes" if the condition is true
	} else {
		cout << "No" << endl; // Print "No" if the condition is false
	}
}

// Minimum function
int min(int a, int b) {
	// Determine the minimum of two integers
	if (a > b) {
		return b;
	}
	return a;
}

// Maximum function
int max(int a, int b) {
	// Determine the maximum of two integers
	if (a > b) {
		return a;
	}
	return b;
}

// Scanner structure definition
struct scanner {
	stringstream r;
	string buf;
	int p;
};

// Initialize a new scanner instance
scanner newScanner() {
	scanner sc;
	sc.r.rdbuf(cin.rdbuf());
	return sc;
}

// Next function to read the next token as a string
string scanner::next() {
	pre();
	int start = p;
	for (; p < buf.size(); p++) {
		if (buf[p] == ' ') {
			break;
		}
	}
	string result = buf.substr(start, p - start);
	p++;
	return result;
}

// NextLine function to read the next line as a string
string scanner::nextLine() {
	pre();
	int start = p;
	p = buf.size();
	return buf.substr(start);
}

// NextInt function to read the next integer from the standard input
int scanner::nextInt() {
	pre();
	int start = p;
	for (; p < buf.size(); p++) {
		if (buf[p] == ' ') {
			break;
		}
	}
	int result = stoi(buf.substr(start, p - start));
	p++;
	return result;
}

// NextIntArray function to read an array of integers from the standard input
vector<int> scanner::nextIntArray() {
	pre();
	int start = p;
	vector<int> result;
	for (; p < buf.size() + 1; p++) {
		if (p == buf.size() || buf[p] == ' ') {
			int v = stoi(buf.substr(start, p - start));
			result.push_back(v);
			start = p + 1;
		}
	}
	return result;
}

// Pre function to prepare the scanner for reading the next token
void scanner::pre() {
	if (p >= buf.size()) {
		readLine();
		p = 0;
	}
}

// ReadLine function to read a line from the standard input
void scanner::readLine() {
	buf = "";
	while (true) {
		string l;
		getline(r, l);
		buf += l;
		if (!r.good()) {
			break;
		}
	}
}

