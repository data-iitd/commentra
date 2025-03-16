
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

// Run function processes input from the reader and writes output to the writer
void Run(istream& r, ostream& w) {
	// Initialize a new scanner to read input
	Scanner sc(r);

	// Read the first line of input and parse N (number of lines) and D (distance threshold)
	vector<int> a = sc.ReadLine().Ints();
	int N = a[0], D = a[1];

	// Read the next N lines of input, each containing a pair of integers
	vector<vector<int>> lines = sc.ReadLines(N).Ints();

	// Initialize a counter for the number of points within the distance D
	int count = 0;
	// Iterate over each line of input
	for (vector<int> line : lines) {
		// Calculate the Euclidean distance from the origin (0, 0)
		double d = sqrt(line[0]*line[0] + line[1]*line[1]);
		// Check if the distance is less than or equal to D
		if (D >= d) {
			count++; // Increment the count if within distance
		}
	}
	// Output the total count of points within distance D
	w << count << endl;
}

// Scanner struct wraps istream for reading input
class Scanner {
public:
	Scanner(istream& r) : r(r) {}

	// ReadLine reads a single line from the input and returns it as a Value
	Value ReadLine() {
		string line;
		if (getline(r, line)) {
			return Value(line);
		}
		throw runtime_error("scan error"); // Panic if scanning fails
	}

	// ReadLines reads n lines from the input and returns them as Values
	vector<Value> ReadLines(int n) {
		vector<Value> a;
		// Loop to read n lines
		for (int i = 0; i < n; i++) {
			a.push_back(ReadLine()); // Append each line to the Values vector
		}
		return a; // Return the vector of Values
	}

private:
	istream& r;
};

// Value type represents a string value with additional methods for conversion
class Value {
public:
	Value(string s) : s(s) {}

	// String returns the string representation of the Value
	string String() {
		return s;
	}

	// Int converts the Value to an integer
	int Int() {
		int n;
		stringstream ss(s);
		ss >> n;
		if (ss.fail()) {
			throw runtime_error("conversion error"); // Panic if conversion fails
		}
		return n;
	}

	// Float64 converts the Value to a float64
	float Float64() {
		float f;
		stringstream ss(s);
		ss >> f;
		if (ss.fail()) {
			throw runtime_error("conversion error"); // Panic if conversion fails
		}
		return f;
	}

	// Strings splits the Value into a vector of strings
	vector<string> Strings() {
		vector<string> a;
		stringstream ss(s);
		string token;
		while (getline(ss, token, ' ')) {
			a.push_back(token);
		}
		return a;
	}

	// Ints converts the Value to a vector of integers
	vector<int> Ints() {
		vector<int> a;
		// Split the Value into strings and convert each to an integer
		for (string s : Strings()) {
			int n;
			stringstream ss(s);
			ss >> n;
			if (ss.fail()) {
				throw runtime_error("conversion error"); // Panic if conversion fails
			}
			a.push_back(n); // Append the integer to the vector
		}
		return a; // Return the vector of integers
	}

	// Float64s converts the Value to a vector of float64
	vector<float> Float64s() {
		vector<float> a;
		// Split the Value into strings and convert each to a float64
		for (string s : Strings()) {
			float f;
			stringstream ss(s);
			ss >> f;
			if (ss.fail()) {
				throw runtime_error("conversion error"); // Panic if conversion fails
			}
			a.push_back(f); // Append the float64 to the vector
		}
		return a; // Return the vector of float64
	}

	// Runes converts the Value to a vector of runes
	vector<char> Runes() {
		return vector<char>(s.begin(), s.end());
	}

private:
	string s;
};

// Values type represents a vector of Value
class Values {
public:
	// Strings converts the Values to a vector of string vectors
	vector<vector<string>> Strings() {
		vector<vector<string>> a;
		// Loop through each Value and convert to strings
		for (Value value : *this) {
			a.push_back(value.Strings());
		}
		return a; // Return the vector of string vectors
	}

	// Ints converts the Values to a vector of integer vectors
	vector<vector<int>> Ints() {
		vector<vector<int>> a;
		// Loop through each Value and convert to integers
		for (Value value : *this) {
			a.push_back(value.Ints());
		}
		return a; // Return the vector of integer vectors
	}

	// Float64s converts the Values to a vector of float64 vectors
	vector<vector<float>> Float64s() {
		vector<vector<float>> a;
		// Loop through each Value and convert to float64
		for (Value value : *this) {
			a.push_back(value.Float64s());
		}
		return a; // Return the vector of float64 vectors
	}

	// Runes converts the Values to a vector of rune vectors
	vector<vector<char>> Runes() {
		vector<vector<char>> a;
		// Loop through each Value and convert to runes
		for (Value value : *this) {
			a.push_back(value.Runes());
		}
		return a; // Return the vector of rune vectors
	}

private:
	vector<Value> v;
};

int main() {
	Run(cin, cout);
	return 0;
}

