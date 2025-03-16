
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

// Initialize IO object and handle resources
void main() {
	IO io;
	auto flash = io.Flash();

	// Read input values
	int n = io.ScanInt();
	double t = io.ScanFloat64();
	double a = io.ScanFloat64();

	// Initialize variables for heights and minimum difference
	vector<double> heights = io.ScanFloat64s(n);
	double minDiff = AbsDiffFloat64(t - heights[0] * 0.006, a);
	int minIdx = 0;

	// Iterate through the remaining heights and find the minimum difference
	for (int i = 1; i < heights.size(); i++) {
		// Calculate the difference between the target and the height
		double diff = AbsDiffFloat64(t - heights[i] * 0.006, a);

		// Update minimum difference and index if the current difference is smaller
		if (diff < minDiff) {
			minDiff = diff;
			minIdx = i;
		}
	}

	// Print the result
	io.Println(minIdx + 1);
}

// Calculate absolute difference between two float64 numbers
double AbsDiffFloat64(double n1, double n2) {
	return abs(n1 - n2);
}

// Initialize IO object with scanner and writer
class IO {
public:
	IO() : scanner(cin), writer(cout) {}

	// Create new IO object
	IO(istream& in, ostream& out) : scanner(in), writer(out) {}

	// Initialize scanner with standard input
	static IO StandardIO() {
		return IO(cin, cout);
	}

	// Read a single byte from the scanner
	string ScanBytes() {
		string str;
		scanner >> str;
		return str;
	}

	// Read a single string from the scanner
	string ScanString() {
		string str;
		scanner >> str;
		return str;
	}

	// Read multiple strings from the scanner
	vector<string> ScanStrings(int n) {
		vector<string> strs(n);
		for (int i = 0; i < n; i++) {
			strs[i] = ScanString();
		}
		return strs;
	}

	// Read a 2D array of strings from the scanner
	vector<vector<string>> Scan2DStrings(int y, int x) {
		vector<vector<string>> strs(y);
		for (int i = 0; i < y; i++) {
			strs[i] = ScanStrings(x);
		}
		return strs;
	}

	// Read a 2D array of graphs from the scanner
	vector<vector<string>> Scan2DGraph(int y) {
		vector<vector<string>> strs(y);
		for (int i = 0; i < y; i++) {
			strs[i] = ScanStrings(x);
		}
		return strs;
	}

	// Read a single integer from the scanner
	int ScanInt() {
		int i;
		scanner >> i;
		return i;
	}

	// Read two integers from the scanner
	pair<int, int> ScanInt2() {
		int i1, i2;
		scanner >> i1 >> i2;
		return make_pair(i1, i2);
	}

	// Read three integers from the scanner
	tuple<int, int, int> ScanInt3() {
		int i1, i2, i3;
		scanner >> i1 >> i2 >> i3;
		return make_tuple(i1, i2, i3);
	}

	// Read four integers from the scanner
	tuple<int, int, int, int> ScanInt4() {
		int i1, i2, i3, i4;
		scanner >> i1 >> i2 >> i3 >> i4;
		return make_tuple(i1, i2, i3, i4);
	}

	// Read a slice of integers from the scanner
	vector<int> ScanInts(int n) {
		vector<int> ints(n);
		for (int i = 0; i < n; i++) {
			ints[i] = ScanInt();
		}
		return ints;
	}

	// Read a 2D slice of integers from the scanner
	vector<vector<int>> Scan2DInts(int y, int x) {
		vector<vector<int>> ints(y);
		for (int i = 0; i < y; i++) {
			ints[i] = ScanInts(x);
		}
		return ints;
	}

	// Read a single int64 from the scanner
	int64_t ScanInt64() {
		int64_t i;
		scanner >> i;
		return i;
	}

	// Read a single float64 from the scanner
	double ScanFloat64() {
		double i;
		scanner >> i;
		return i;
	}

	// Read a slice of float64 from the scanner
	vector<double> ScanFloat64s(int n) {
		vector<double> floats(n);
		for (int i = 0; i < n; i++) {
			floats[i] = ScanFloat64();
		}
		return floats;
	}

	// Write a single line to the writer
	void Println(string a) {
		writer << a << endl;
	}

	// Flush the writer buffer
	void Flush() {
		writer.flush();
	}

	// Function to handle resource deallocation
	function<void()> Flash() {
		return [this]() {
			Flush();
		};
	}

private:
	istream& scanner;
	ostream& writer;
};

// Function to calculate the absolute difference between two float64 numbers
double AbsDiffFloat64(double n1, double n2) {
	return abs(n1 - n2);
}

