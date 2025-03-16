#include <bits/stdc++.h>

using namespace std;

// Run function processes input from the reader and writes output to the writer
void Run(std::istream& r, std::ostream& w) {
	// Initialize a new scanner to read input
	Scanner sc(r);

	// Read the first line of input and parse N (number of lines) and D (distance threshold)
	auto a = sc.ReadLine().Ints();
	int N = a[0], D = a[1];

	// Read the next N lines of input, each containing a pair of integers
	auto lines = sc.ReadLines(N).Ints();

	// Initialize a counter for the number of points within the distance D
	int count = 0;
	// Iterate over each line of input
	for (auto line : lines) {
		// Calculate the Euclidean distance from the origin (0, 0)
		double d = sqrt(pow(line[0], 2) + pow(line[1], 2));
		// Check if the distance is less than or equal to D
		if (D >= d) {
			count++; // Increment the count if within distance
		}
	}
	// Output the total count of points within distance D
	w << count << endl;
}

// Scanner struct wraps std::istream for reading input
struct Scanner {
	std::istream& r;
	std::string s;

	Scanner(std::istream& r) : r(r) {}

	// ReadLine reads a single line from the input and returns it as a Value
	Value ReadLine() {
		if (std::getline(r, s)) {
			return Value(s);
		}
		throw std::runtime_error("scan error"); // Panic if scanning fails
	}

	// ReadLines reads n lines from the input and returns them as Values
	Values ReadLines(int n) {
		Values a;
		// Loop to read n lines
		for (int i = 0; i < n; i++) {
			a = append(a, ReadLine()); // Append each line to the Values slice
		}
		return a; // Return the slice of Values
	}
};

// Value type represents a string value with additional methods for conversion
struct Value {
	std::string s;

	Value(std::string s) : s(s) {}

	// String returns the string representation of the Value
	std::string String() {
		return s;
	}

	// Int converts the Value to an integer
	int Int() {
		int n;
		std::stringstream ss(s);
		ss >> n;
		if (ss.fail()) {
			throw std::runtime_error("conversion error"); // Panic if conversion fails
		}
		return n;
	}

	// Float64 converts the Value to a float64
	double Float64() {
		double f;
		std::stringstream ss(s);
		ss >> f;
		if (ss.fail()) {
			throw std::runtime_error("conversion error"); // Panic if conversion fails
		}
		return f;
	}

	// Strings splits the Value into a slice of strings
	std::vector<std::string> Strings() {
		std::vector<std::string> a;
		std::stringstream ss(s);
		std::string s;
		while (std::getline(ss, s,'')) {
			a.push_back(s);
		}
		return a;
	}

	// Ints converts the Value to a slice of integers
	std::vector<int> Ints() {
		std::vector<int> a;
		for (auto s : Strings()) {
			a.push_back(Int());
		}
		return a;
	}

	// Float64s converts the Value to a slice of float64
	std::vector<double> Float64s() {
		std::vector<double> a;
		for (auto s : Strings()) {
			a.push_back(Float64());
		}
		return a;
	}

	// Runes converts the Value to a slice of runes
	std::vector<char> Runes() {
		std::vector<char> a;
		for (auto c : s) {
			a.push_back(c);
		}
		return a;
	}
};

// Values type represents a slice of Value
using Values = std::vector<Value>;

// main function serves as the entry point of the program
int main() {
	// Call the Run function with standard input and output
	Run(std::cin, std::cout);
}

