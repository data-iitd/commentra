
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

// getScanner initializes a new stringstream with specific configurations.
stringstream getScanner(string s) {
	stringstream ss(s);
	ss.str(s);
	ss.clear();
	return ss;
}

// getNextString reads the next word from the stringstream.
string getNextString(stringstream &ss) {
	string s;
	ss >> s;
	return s;
}

// getNextInt reads the next word, converts it to an integer, and returns it.
int getNextInt(stringstream &ss) {
	int i;
	string s = getNextString(ss);
	stringstream(s) >> i;
	return i;
}

// getNextInt64 reads the next word, converts it to an int64, and returns it.
int64_t getNextInt64(stringstream &ss) {
	int64_t i;
	string s = getNextString(ss);
	stringstream(s) >> i;
	return i;
}

// getNextUint64 reads the next word, converts it to a uint64, and returns it.
uint64_t getNextUint64(stringstream &ss) {
	uint64_t i;
	string s = getNextString(ss);
	stringstream(s) >> i;
	return i;
}

// getNextFloat64 reads the next word, converts it to a float64, and returns it.
float64_t getNextFloat64(stringstream &ss) {
	float64_t i;
	string s = getNextString(ss);
	stringstream(s) >> i;
	return i;
}

// Main function handles file input/output operations based on command-line arguments.
int main(int argc, char *argv[]) {
	string line;
	stringstream ss;

	// Check if command-line arguments are provided for file input/output.
	if (argc > 1) {
		ifstream fp(argv[1]);
		if (argc > 2) {
			ofstream wfp(argv[2]);
			while (getline(fp, line)) {
				ss = getScanner(line);
				int n = getNextInt(ss);
				string ans = "second";
				for (int i = 0; i < n; i++) {
					int a = getNextInt(ss);
					if (a % 2 == 1) {
						ans = "first";
						break;
					}
				}
				wfp << ans << endl;
			}
		} else {
			while (getline(fp, line)) {
				ss = getScanner(line);
				int n = getNextInt(ss);
				string ans = "second";
				for (int i = 0; i < n; i++) {
					int a = getNextInt(ss);
					if (a % 2 == 1) {
						ans = "first";
						break;
					}
				}
				cout << ans << endl;
			}
		}
	} else {
		while (getline(cin, line)) {
			ss = getScanner(line);
			int n = getNextInt(ss);
			string ans = "second";
			for (int i = 0; i < n; i++) {
				int a = getNextInt(ss);
				if (a % 2 == 1) {
					ans = "first";
					break;
				}
			}
			cout << ans << endl;
		}
	}
	return 0;
}

