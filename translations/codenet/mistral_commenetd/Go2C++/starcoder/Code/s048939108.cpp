
#include <iostream>
#include <string>
#include <vector>

// Initialize a new scanner
class scanner {
public:
	scanner() {
		r = new std::cin;
	}

	// Read the next token as a string
	std::string next() {
		pre();
		std::string result;
		while (p < buf.size() && buf[p]!='') {
			result += buf[p];
			p++;
		}
		p++;
		return result;
	}

	// Read the next line as a string
	std::string nextLine() {
		pre();
		std::string result;
		while (p < buf.size()) {
			result += buf[p];
			p++;
		}
		return result;
	}

	// Read the next integer from the standard input
	int nextInt() {
		return std::stoi(next());
	}

	// Read an array of integers from the standard input
	std::vector<int> nextIntArray() {
		pre();
		std::vector<int> result;
		while (p < buf.size() + 1) {
			if (p == buf.size() || buf[p] =='') {
				result.push_back(std::stoi(std::string(buf.begin() + start, buf.begin() + p)));
				start = p + 1;
			}
			p++;
		}
		return result;
	}

private:
	// Prepare the scanner for reading the next token
	void pre() {
		if (p >= buf.size()) {
			readLine();
			p = 0;
		}
	}

	// Read a line from the standard input
	void readLine() {
		buf.clear();
		while (true) {
			std::string l;
			std::getline(*r, l);
			buf += l;
			if (!r->good()) {
				break;
			}
		}
	}

	std::istream *r;
	std::vector<char> buf;
	int p = 0;
	int start = 0;
};

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

int main() {
	scanner sc;

	// Read the first string from the standard input
	std::string S = sc.next();

	// Check if the string starts with "YAKI"
	if (S.find("YAKI") == 0) {
		std::cout << "Yes" << std::endl; // Print "Yes" if the condition is true
	} else {
		std::cout << "No" << std::endl; // Print "No" if the condition is false
	}
}

