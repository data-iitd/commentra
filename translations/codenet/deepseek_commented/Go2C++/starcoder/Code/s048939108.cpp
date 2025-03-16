
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Main function starts here
int main() {
	// Initialize a new scanner to read input
	auto sc = newScanner();
	// Read the next string from the scanner
	string S = sc->next();
	// Check if the string S starts with the prefix "YAKI"
	if (S.find("YAKI") == 0) {
		// If it does, print "Yes"
		cout << "Yes" << endl;
	} else {
		// Otherwise, print "No"
		cout << "No" << endl;
	}
}

// Helper function to find the minimum of two integers
int min(int a, int b) {
	if (a > b) {
		return b;
	}
	return a;
}

// Helper function to find the maximum of two integers
int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

// Custom scanner type to handle input reading
class scanner {
public:
	// Constructor to create a new scanner instance
	scanner() {
		r = new istream(cin.rdbuf());
	}
	// Method to read the next word from the input
	string next() {
		pre();
		int start = p;
		while (p < buf.size() && buf[p]!='') {
			p++;
		}
		string result = string(buf.begin() + start, buf.begin() + p);
		p++;
		return result;
	}
	// Method to read the next line from the input
	string nextLine() {
		pre();
		int start = p;
		p = buf.size();
		return string(buf.begin() + start, buf.end());
	}
	// Method to read the next integer from the input
	int nextInt() {
		return atoi(next().c_str());
	}
	// Method to read the next array of integers from the input
	vector<int> nextIntArray() {
		pre();
		int start = p;
		vector<int> result;
		while (p < buf.size() + 1) {
			if (p == buf.size() || buf[p] =='') {
				int v = atoi(string(buf.begin() + start, buf.begin() + p).c_str());
				result.push_back(v);
				start = p + 1;
			}
			p++;
		}
		return result;
	}
private:
	// Method to preprocess the buffer before reading
	void pre() {
		if (p >= buf.size()) {
			readLine();
			p = 0;
		}
	}
	// Method to read a line from the input and update the buffer
	void readLine() {
		buf.clear();
		while (true) {
			char c;
			r->get(c);
			if (r->eof()) {
				break;
			}
			buf.push_back(c);
		}
	}
	// Input stream
	istream *r;
	// Buffer to hold the input
	vector<char> buf;
	// Current read position
	int p = 0;
};

