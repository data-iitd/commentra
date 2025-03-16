#include <bits/stdc++.h>

using namespace std;

// Function to calculate the absolute difference between two float64 numbers
float64_t AbsDiffFloat64(float64_t n1, float64_t n2) {
	return abs(n1 - n2);
}

// IO struct for handling input and output operations
struct IO {
	// Declare private members
	private:
	// Declare public members
	public:
	// Declare private methods
	private:
	// Declare public methods
	public:
	// Initialize a new IO instance with a scanner and writer
	IO() : scanner(newScanner()), writer(newWriter()) {}
	// Scan and return a byte slice from input
	vector<char> ScanBytes() {
		if (!scanner->Scan()) {
			panic("scan bytes failed"); // Panic if scanning fails
		}
		return scanner->Bytes(); // Return scanned bytes
	}
	// Scan and return a string from input
	string ScanString() {
		if (!scanner->Scan()) {
			panic("scan string failed"); // Panic if scanning fails
		}
		return scanner->Text(); // Return scanned string
	}
	// Scan and return a slice of strings from input
	vector<string> ScanStrings(int n) {
		vector<string> strs(n);
		for (int i = 0; i < n; i++) {
			strs[i] = ScanString(); // Scan each string
		}
		return strs; // Return the slice of strings
	}
	// Scan and return a 2D slice of strings from input
	vector<vector<string>> Scan2DStrings(int y, int x) {
		vector<vector<string>> strings(y);
		for (int i = 0; i < y; i++) {
			strings[i] = ScanStrings(x); // Scan each row of strings
		}
		return strings; // Return the 2D slice of strings
	}
	// Scan and return a 2D slice of strings representing a graph
	vector<vector<string>> Scan2DGraph(int y) {
		vector<vector<string>> strs(y);
		for (int i = 0; i < y; i++) {
			strs[i] = vector<string>(ScanString().begin(), ScanString().end()); // Split each line into characters
		}
		return strs; // Return the 2D slice of characters
	}
	// Scan and return an integer from input
	int ScanInt() {
		return atoi(ScanString().c_str()); // Convert scanned string to int
	}
	// Scan and return two integers from input
	pair<int, int> ScanInt2() {
		return make_pair(ScanInt(), ScanInt()); // Return two integers
	}
	// Scan and return three integers from input
	tuple<int, int, int> ScanInt3() {
		return make_tuple(ScanInt(), ScanInt(), ScanInt()); // Return three integers
	}
	// Scan and return four integers from input
	tuple<int, int, int, int> ScanInt4() {
		return make_tuple(ScanInt(), ScanInt(), ScanInt(), ScanInt()); // Return four integers
	}
	// Scan and return a slice of integers from input
	vector<int> ScanInts(int n) {
		vector<int> ints(n);
		for (int i = 0; i < n; i++) {
			ints[i] = ScanInt(); // Scan each integer
		}
		return ints; // Return the slice of integers
	}
	// Scan and return a 2D slice of integers from input
	vector<vector<int>> Scan2DInts(int y, int x) {
		vector<vector<int>> ints(y);
		for (int i = 0; i < y; i++) {
			ints[i] = ScanInts(x); // Scan each row of integers
		}
		return ints; // Return the 2D slice of integers
	}
	// Scan and return an int64 from input
	int64_t ScanInt64() {
		int64_t i;
		stringstream ss(ScanString());
		ss >> i;
		return i; // Return the int64 value
	}
	// Scan and return a float64 from input
	float64_t ScanFloat64() {
		float64_t i;
		stringstream ss(ScanString());
		ss >> i;
		return i; // Return the float64 value
	}
	// Scan and return a slice of float64 from input
	vector<float64_t> ScanFloat64s(int n) {
		vector<float64_t> floats(n);
		for (int i = 0; i < n; i++) {
			floats[i] = ScanFloat64(); // Scan each float64
		}
		return floats; // Return the slice of float64
	}
	// Print a line to the output
	void Println(const vector<string>& a) {
		for (int i = 0; i < a.size(); i++) {
			if (i) {
				writer->Put(' '); // Put a space between each argument
			}
			writer->Put(a[i]); // Put each argument
		}
		writer->Put('\n'); // Put a newline at the end
		writer->Flush(); // Flush the writer
	}
	// Print a line to the output
	void Println(const vector<int>& a) {
		for (int i = 0; i < a.size(); i++) {
			if (i) {
				writer->Put(' '); // Put a space between each argument
			}
			writer->Put(to_string(a[i])); // Put each argument
		}
		writer->Put('\n'); // Put a newline at the end
		writer->Flush(); // Flush the writer
	}
	// Print a line to the output
	void Println(const vector<float64_t>& a) {
		for (int i = 0; i < a.size(); i++) {
			if (i) {
				writer->Put(' '); // Put a space between each argument
			}
			writer->Put(to_string(a[i])); // Put each argument
		}
		writer->Put('\n'); // Put a newline at the end
		writer->Flush(); // Flush the writer
	}
	// Print a line to the output
	void Println(const string& a) {
		writer->Put(a); // Put the argument
		writer->Put('\n'); // Put a newline at the end
		writer->Flush(); // Flush the writer
	}
	// Print a line to the output
	void Println(const int& a) {
		writer->Put(to_string(a)); // Put the argument
		writer->Put('\n'); // Put a newline at the end
		writer->Flush(); // Flush the writer
	}
	// Print a line to the output
	void Println(const float64_t& a) {
		writer->Put(to_string(a)); // Put the argument
		writer->Put('\n'); // Put a newline at the end
		writer->Flush(); // Flush the writer
	}
	// Print a line to the output
	void Print(const vector<string>& a) {
		for (int i = 0; i < a.size(); i++) {
			if (i) {
				writer->Put(' '); // Put a space between each argument
			}
			writer->Put(a[i]); // Put each argument
		}
		writer->Flush(); // Flush the writer
	}
	// Print a line to the output
	void Print(const vector<int>& a) {
		for (int i = 0; i < a.size(); i++) {
			if (i) {
				writer->Put(' '); // Put a space between each argument
			}
			writer->Put(to_string(a[i])); // Put each argument
		}
		writer->Flush(); // Flush the writer
	}
	// Print a line to the output
	void Print(const vector<float64_t>& a) {
		for (int i = 0; i < a.size(); i++) {
			if (i) {
				writer->Put(' '); // Put a space between each argument
			}
			writer->Put(to_string(a[i])); // Put each argument
		}
		writer->Flush(); // Flush the writer
	}
	// Print a line to the output
	void Print(const string& a) {
		writer->Put(a); // Put the argument
		writer->Flush(); // Flush the writer
	}
	// Print a line to the output
	void Print(const int& a) {
		writer->Put(to_string(a)); // Put the argument
		writer->Flush(); // Flush the writer
	}
	// Print a line to the output
	void Print(const float64_t& a) {
		writer->Put(to_string(a)); // Put the argument
		writer->Flush(); // Flush the writer
	}
	// Return a new bufio.Scanner
	static shared_ptr<bufio::Scanner> newScanner() {
		shared_ptr<bufio::Scanner> s(new bufio::Scanner(cin));
		s->Buffer(make_shared<vector<char>>(10000000), 10000000); // Set buffer size for the scanner
		s->Split(bufio::ScanWords); // Split input by words
		return s;
	}
	// Return a new bufio.Writer
	static shared_ptr<bufio::Writer> newWriter() {
		return shared_ptr<bufio::Writer>(new bufio::Writer(cout)); // Write output to standard output
	}
	// Declare private members
	shared_ptr<bufio::Scanner> scanner;
	shared_ptr<bufio::Writer> writer;
};

// Main function
int main() {
	// Initialize a new IO instance
	IO io;

	// Read the number of heights, target temperature, and actual temperature
	int n = io.ScanInt();
	float64_t t = io.ScanFloat64();
	float64_t a = io.ScanFloat64();
	// Read the heights as a slice of float64
	vector<float64_t> heights = io.ScanFloat64s(n);

	// Initialize minimum difference and index for tracking the closest height
	float64_t minDiff = AbsDiffFloat64(t-heights[0]*0.006, a);
	int minIdx = 0;

	// Iterate through the heights to find the one with the minimum temperature difference
	for (int i = 0; i < heights.size(); i++) {
		float64_t diff = AbsDiffFloat64(t-heights[i]*0.006, a);
		if (diff < minDiff) {
			minDiff = diff;
			minIdx = i; // Update the index of the closest height
		}
	}

	// Output the 1-based index of the closest height
	io.Println(minIdx + 1);
}

