
#include <bits/stdc++.h>

using namespace std;

// Initialize IO object and handle resources
int main() {
	IO io;
	auto flash = [&io](){
		io.writer.flush();
		io.scanner.close();
		cin.close();
		cout.close();
	};

	// Read input values
	int n, t, a = io.ScanInt(), io.ScanFloat64(), io.ScanFloat64();

	// Initialize variables for heights and minimum difference
	vector<float> heights = io.ScanFloat64s(n);
	float minDiff = abs(t - heights[0] * 0.006 - a);
	int minIdx = 0;

	// Iterate through the remaining heights and find the minimum difference
	for (int i = 1; i < n; i++) {
		// Calculate the difference between the target and the height
		float diff = abs(t - heights[i] * 0.006 - a);

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
float AbsDiffFloat64(float n1, float n2) {
	return abs(n1 - n2);
}

// Initialize IO object with scanner and writer
class IO {
public:
	IO() : scanner(new ifstream(0)), writer(new ofstream(1)) {
		scanner->tie(0);
		ios_base::sync_with_stdio(0);
	}

	~IO() {
		delete scanner;
		delete writer;
	}

	// Read a single byte from the scanner
	char ScanByte() {
		if (!scanner->get(c)) {
			throw runtime_error("scan byte failed");
		}
		return c;
	}

	// Read a single string from the scanner
	string ScanString() {
		if (!scanner->get(c)) {
			throw runtime_error("scan string failed");
		}
		while (c!='' && c!= '\n') {
			s += c;
			if (!scanner->get(c)) {
				throw runtime_error("scan string failed");
			}
		}
		return s;
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
		vector<vector<string>> strings(y);
		for (int i = 0; i < y; i++) {
			strings[i] = ScanStrings(x);
		}
		return strings;
	}

	// Read a 2D array of graphs from the scanner
	vector<vector<string>> Scan2DGraph(int y) {
		vector<vector<string>> strs(y);
		for (int i = 0; i < y; i++) {
			strs[i] = vector<string>(ScanString());
		}
		return strs;
	}

	// Read a single integer from the scanner
	int ScanInt() {
		return atoi(ScanString().c_str());
	}

	// Read two integers from the scanner
	pair<int, int> ScanInt2() {
		return make_pair(ScanInt(), ScanInt());
	}

	// Read three integers from the scanner
	tuple<int, int, int> ScanInt3() {
		return make_tuple(ScanInt(), ScanInt(), ScanInt());
	}

	// Read four integers from the scanner
	tuple<int, int, int, int> ScanInt4() {
		return make_tuple(ScanInt(), ScanInt(), ScanInt(), ScanInt());
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
		return stoll(ScanString());
	}

	// Read a single float64 from the scanner
	double ScanFloat64() {
		return stod(ScanString());
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
	void Println(const vector<string>& a) {
		for (int i = 0; i < a.size(); i++) {
			if (i) {
				writer->put(' ');
			}
			writer->write(a[i].c_str(), a[i].size());
		}
		writer->put('\n');
	}

	// Write a single line to the writer
	void Println(const string& a) {
		writer->write(a.c_str(), a.size());
		writer->put('\n');
	}

	// Write a single line to the writer
	void Println(int a) {
		writer->write(to_string(a).c_str(), to_string(a).size());
		writer->put('\n');
	}

	// Write a single line to the writer
	void Println(int64_t a) {
		writer->write(to_string(a).c_str(), to_string(a).size());
		writer->put('\n');
	}

	// Write a single line to the writer
	void Println(double a) {
		writer->write(to_string(a).c_str(), to_string(a).size());
		writer->put('\n');
	}

	// Flush the writer buffer
	void Flush() {
		writer->flush();
	}

private:
	// IO object
	istream* scanner;
	ostream* writer;
	char c, s[1000000];
};

// Function to handle resource deallocation
void flash(IO& io) {
	io.writer->flush();
	io.scanner->close();
	cin.close();
	cout.close();
}

// Function to calculate the absolute difference between two float64 numbers
float AbsDiffFloat64(float n1, float n2) {
	return abs(n1 - n2);
}

