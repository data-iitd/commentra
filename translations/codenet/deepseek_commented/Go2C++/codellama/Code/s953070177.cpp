
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

// getScanner initializes a new ifstream to read from a file.
// It sets the delimiter to a space and it also sets a buffer size.
ifstream getScanner(string filename) {
	ifstream scanner(filename);
	scanner.unsetf(ios::skipws);
	scanner.setbuf(new char[500001], 500000);
	return scanner;
}

// getNextString reads the next word from the scanner and returns it as a string.
string getNextString(ifstream &scanner) {
	string word;
	scanner >> word;
	return word;
}

// getNextInt reads the next word from the scanner, converts it to an integer,
// and returns it.
int getNextInt(ifstream &scanner) {
	string word = getNextString(scanner);
	return stoi(word);
}

// getNextInt64 reads the next word from the scanner, converts it to an int64,
// and returns it.
int64_t getNextInt64(ifstream &scanner) {
	string word = getNextString(scanner);
	return stoll(word);
}

// main is the entry point of the program.
// It first checks if a file name is provided as an argument,
// and if so, it opens that file for reading.
// It then initializes a scanner and a writer.
int main(int argc, char* argv[]) {
	ifstream fp;
	if (argc > 1) {
		fp = getScanner(argv[1]);
	}
	else {
		fp = getScanner("");
	}

	// Read the number of elements.
	int n = getNextInt(fp);

	// Initialize a vector to store the elements and a sum variable.
	vector<int> aa(n + 2);
	int sum = 0;

	// Read the elements into the vector and calculate the sum of absolute differences.
	for (int i = 0; i < n; i++) {
		aa[i + 1] = getNextInt(fp);
		sum += abs(aa[i + 1] - aa[i]);
	}
	sum += abs(aa[n + 1] - aa[n]);

	// Calculate and print the differences for each element.
	for (int i = 1; i < n + 1; i++) {
		int ans = sum - abs(aa[i + 1] - aa[i]) - abs(aa[i] - aa[i - 1]) + abs(aa[i + 1] - aa[i - 1]);
		cout << ans << endl;
	}

	return 0;
}

