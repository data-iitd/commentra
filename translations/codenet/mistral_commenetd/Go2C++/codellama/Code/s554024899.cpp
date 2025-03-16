
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Define a scanner structure
struct scanner {
	vector<string> buf;
	int p;
};

// Initialize a new scanner object
scanner newScanner() {
	scanner s;
	s.p = 0;
	return s;
}

// Function to read a single word from the input
string next(scanner &s) {
	if (s.p >= s.buf.size()) {
		s.buf.clear();
		string line;
		getline(cin, line);
		stringstream ss(line);
		string word;
		while (ss >> word) {
			s.buf.push_back(word);
		}
		s.p = 0;
	}
	string result = s.buf[s.p];
	s.p++;
	return result;
}

// Function to read a line from the input
string nextLine(scanner &s) {
	if (s.p >= s.buf.size()) {
		s.buf.clear();
		string line;
		getline(cin, line);
		stringstream ss(line);
		string word;
		while (ss >> word) {
			s.buf.push_back(word);
		}
		s.p = 0;
	}
	string result = s.buf[s.p];
	s.p = s.buf.size();
	return result;
}

// Function to read an integer from the input
int nextInt(scanner &s) {
	string word = next(s);
	return stoi(word);
}

// Define a 3x3 2D array a
int a[3][3] = {{1, 3, 5, 7, 8, 10, 12}, {4, 6, 9, 11}, {2}};

int main() {
	scanner sc = newScanner(); // Initialize a new scanner object

	// Read the first two integers from the standard input using the scanner
	int x = nextInt(sc);
	int y = nextInt(sc);

	// Initialize two variables xt and yt to store the indices of the arrays a where x and y are present
	int xt, yt;

	// Iterate through each inner loop of the outer loop
	for (int i = 0; i < 3; i++) {
		// Iterate through each element of the current inner loop
		for (int j = 0; j < 7; j++) {
			// Check if the current element is equal to x, if yes, store its index in xt
			if (a[i][j] == x) {
				xt = i;
			}
			// Check if the current element is equal to y, if yes, store its index in yt
			if (a[i][j] == y) {
				yt = i;
			}
		}
	}

	// Check if the indices xt and yt are equal, if yes, print "Yes"
	if (xt == yt) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}

	return 0;
}

