
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

// Main function starts here
int main() {
	// Initialize a new scanner to read input
	scanner sc;
	// Read the next string from the scanner
	string S = sc.next();
	// Check if the string S starts with the prefix "YAKI"
	if (S.find("YAKI") == 0) {
		// If it does, print "Yes"
		cout << "Yes" << endl;
	} else {
		// Otherwise, print "No"
		cout << "No" << endl;
	}
	return 0;
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
private:
	stringstream ss;
	string buf;
	int p;
public:
	// Function to create a new scanner instance
	scanner() {
		p = 0;
	}
	// Method to read the next word from the input
	string next() {
		pre();
		int start = p;
		for (; p < buf.length(); p++) {
			if (buf[p] == ' ') {
				break;
			}
		}
		string result = buf.substr(start, p - start);
		p++;
		return result;
	}
	// Method to read the next line from the input
	string nextLine() {
		pre();
		int start = p;
		p = buf.length();
		return buf.substr(start);
	}
	// Method to read the next integer from the input
	int nextInt() {
		string s = next();
		int v;
		stringstream ss(s);
		ss >> v;
		return v;
	}
	// Method to read the next array of integers from the input
	vector<int> nextIntArray() {
		pre();
		int start = p;
		vector<int> result;
		for (; p < buf.length() + 1; p++) {
			if (p == buf.length() || buf[p] == ' ') {
				string s = buf.substr(start, p - start);
				int v;
				stringstream ss(s);
				ss >> v;
				result.push_back(v);
				start = p + 1;
			}
		}
		return result;
	}
	// Method to preprocess the buffer before reading
	void pre() {
		if (p >= buf.length()) {
			readLine();
			p = 0;
		}
	}
	// Method to read a line from the input and update the buffer
	void readLine() {
		buf = "";
		while (true) {
			string l;
			getline(cin, l);
			buf += l;
			if (!cin.good()) {
				break;
			}
		}
	}
};

