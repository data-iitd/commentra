
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

// Function Run calculates the number of points within a square with side length D and center at (0,0)
void Run(istream& r, ostream& w) {
	// Initialize a new scanner object to read input
	Scanner sc(r);

	// Read the first line of input containing N and D
	vector<int> a = sc.ReadLine().Ints();
	int N = a[0], D = a[1]; // N is the number of lines, D is the side length of the square

	// Read N lines of input and store them in a slice called lines
	vector<vector<int>> lines = sc.ReadLines(N).Ints();

	// Initialize a counter variable count to 0
	int count = 0;

	// Iterate through each line in the lines slice
	for (vector<int> line : lines) {
		// Calculate the Euclidean distance of the current line from the origin (0,0)
		double d = sqrt(line[0]*line[0] + line[1]*line[1]);

		// If the distance of the current line is less than or equal to D, increment the counter
		if (D >= d) {
			count++;
		}
	}

	// Write the final result to the output writer
	w << count << endl;
}

// main function calls the Run function with standard input and output streams
int main() {
	Run(cin, cout);
	return 0;
}

// Function NewScanner initializes a new scanner object
Scanner::Scanner(istream& r) : sc(r) {}

// Scanner structure to read input lines
struct Scanner {
	istream& sc;

	// ReadLine function reads a single line of input and returns it as a Value object
	Value ReadLine() {
		// Read a line using the scanner and return it as a Value object
		string line;
		if (getline(sc, line)) {
			return Value(line);
		}
		// Panic if there's an error while reading input
		panic("scan error");
	}

	// ReadLines function reads N lines of input and returns them as a slice of Value objects
	vector<Value> ReadLines(int n) {
		// Initialize an empty slice called a and append N Value objects to it
		vector<Value> a;
		for (int i = 0; i < n; i++) {
			// Read a single line and append it to the slice
			a.push_back(ReadLine());
		}
		// Return the slice of Value objects
		return a;
	}
};

// Value structure to store a string value
struct Value {
	string s;

	// String function returns the string representation of the Value object
	string String() {
		return s;
	}

	// Int function converts a Value object to an integer
	int Int() {
		// Parse the string representation of the Value object to an integer and return it
		int n;
		istringstream(s) >> n;
		return n;
	}

	// Float64 function converts a Value object to a float64
	double Float64() {
		// Parse the string representation of the Value object to a float64 and return it
		double f;
		istringstream(s) >> f;
		return f;
	}

	// Strings function splits a Value object into a slice of strings based on whitespace
	vector<string> Strings() {
		// Split the string representation of the Value object based on whitespace and return the slice
		istringstream ss(s);
		string word;
		vector<string> a;
		while (ss >> word) {
			a.push_back(word);
		}
		return a;
	}

	// Ints function converts a Value object to a slice of integers
	vector<int> Ints() {
		// Convert each string in the slice returned by the Strings function to an integer and return the slice
		vector<string> words = Strings();
		vector<int> a;
		for (string word : words) {
			a.push_back(atoi(word.c_str()));
		}
		return a;
	}

	// Float64s function converts a Value object to a slice of float64s
	vector<double> Float64s() {
		// Parse each string in the slice returned by the Strings function to a float64 and return the slice
		vector<string> words = Strings();
		vector<double> a;
		for (string word : words) {
			a.push_back(atof(word.c_str()));
		}
		return a;
	}

	// Runes function converts a Value object to a slice of runes
	vector<char> Runes() {
		// Convert the string representation of the Value object to a slice of runes and return it
		return vector<char>(s.begin(), s.end());
	}
};

// Function panic prints an error message and exits the program
void panic(string s) {
	cerr << "panic: " << s << endl;
	exit(1);
}

