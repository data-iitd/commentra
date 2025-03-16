
// Package main is the entry point of the program
#include <bits/stdc++.h>

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
		double d = sqrt(double(line[0]*line[0] + line[1]*line[1]));

		// If the distance of the current line is less than or equal to D, increment the counter
		if (double(D) >= d) {
			count++;
		}
	}

	// Write the final result to the output writer
	w << count << endl;
}

// main function calls the Run function with standard input and output streams
int main() {
	Run(cin, cout);
}

// Function NewScanner initializes a new scanner object
Scanner NewScanner(istream& r) {
	return Scanner(r);
}

// Scanner structure to read input lines
class Scanner {
public:
	// Constructor to initialize the scanner object with a reference to the input stream
	Scanner(istream& r) : r(r) {}

	// ReadLine function reads a single line of input and returns it as a Value object
	Value ReadLine() {
		// Read a line using the scanner and return it as a Value object
		if (r >> s) {
			return Value(s);
		}
		// Panic if there's an error while reading input
		panic("scan error");
	}

	// ReadLines function reads N lines of input and returns them as a slice of Value objects
	Values ReadLines(int n) {
		// Initialize an empty slice called a and append N Value objects to it
		Values a;
		for (int i = 0; i < n; i++) {
			// Read a single line and append it to the slice
			a = append(a, ReadLine());
		}
		// Return the slice of Value objects
		return a;
	}

private:
	// Reference to the input stream
	istream& r;

	// String to store a single line of input
	string s;
};

// Value structure to store a string value
class Value {
public:
	// Constructor to initialize the Value object with a string
	Value(string s) : s(s) {}

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
		vector<string> a;
		istringstream(s) >> a;
		return a;
	}

	// Ints function converts a Value object to a slice of integers
	vector<int> Ints() {
		// Convert each string in the slice returned by the Strings function to an integer and return the slice
		vector<int> a;
		for (string s : Strings()) {
			int n;
			istringstream(s) >> n;
			a = append(a, n);
		}
		return a;
	}

	// Float64s function converts a Value object to a slice of float64s
	vector<double> Float64s() {
		// Parse each string in the slice returned by the Strings function to a float64 and return the slice
		vector<double> a;
		for (string s : Strings()) {
			double f;
			istringstream(s) >> f;
			a = append(a, f);
		}
		return a;
	}

	// Runes function converts a Value object to a slice of runes
	vector<char> Runes() {
		// Convert the string representation of the Value object to a slice of runes and return it
		vector<char> a;
		for (char c : s) {
			a = append(a, c);
		}
		return a;
	}

private:
	// String to store a string value
	string s;
};

// Values structure to store a slice of Value objects
class Values : public vector<Value> {
public:
	// Strings function returns a slice of slices of strings, where each inner slice corresponds to the strings in a single Value object
	vector<vector<string>> Strings() {
		// Convert each Value object to a slice of strings and return the outer slice
		vector<vector<string>> a;
		for (Value value : *this) {
			a = append(a, value.Strings());
		}
		return a;
	}

	// Ints function returns a slice of slices of integers, where each inner slice corresponds to the integers in a single Value object
	vector<vector<int>> Ints() {
		// Convert each Value object to a slice of integers and return the outer slice
		vector<vector<int>> a;
		for (Value value : *this) {
			a = append(a, value.Ints());
		}
		return a;
	}

	// Float64s function returns a slice of slices of float64s, where each inner slice corresponds to the float64s in a single Value object
	vector<vector<double>> Float64s() {
		// Convert each Value object to a slice of float64s and return the outer slice
		vector<vector<double>> a;
		for (Value value : *this) {
			a = append(a, value.Float64s());
		}
		return a;
	}

	// Runes function returns a slice of slices of runes, where each inner slice corresponds to the runes in a single Value object
	vector<vector<char>> Runes() {
		// Convert each Value object to a slice of runes and return the outer slice
		vector<vector<char>> a;
		for (Value value : *this) {
			a = append(a, value.Runes());
		}
		return a;
	}
};

// Add comments for each logical block
// Package main is the entry point of the program

import (
	// Importing required packages
	"bufio"
	"fmt"
	"io"
	"math"
	"os"
	"strconv"
	"strings"
)

// Function Run calculates the number of points within a square with side length D and center at (0,0)
func Run(r io.Reader, w io.Writer) {
	// Initialize a new scanner object to read input
	sc := NewScanner(r)

	// Read the first line of input containing N and D
	a := sc.ReadLine().Ints()
	N, D := a[0], a[1] // N is the number of lines, D is the side length of the square

	// Read N lines of input and store them in a slice called lines
	lines := sc.ReadLines(N).Ints()

	// Initialize a counter variable count to 0
	count := 0

	// Iterate through each line in the lines slice
	for _, line := range lines {
		// Calculate the Euclidean distance of the current line from the origin (0,0)
		d := math.Sqrt(float64(line[0]*line[0] + line[1]*line[1]))

		// If the distance of the current line is less than or equal to D, increment the counter
		if float64(D) >= d {
			count++
		}
	}

	// Write the final result to the output writer
	fmt.Fprintln(w, count)
}

// main function calls the Run function with standard input and output streams
func main() {
	Run(os.Stdin, os.Stdout)
}

// Function NewScanner initializes a new scanner object
func NewScanner(r io.Reader) *Scanner {
	return &Scanner{sc: bufio.NewScanner(r)}
}

// Scanner structure to read input lines
type Scanner struct {
	sc *bufio.Scanner
}

// ReadLine function reads a single line of input and returns it as a Value object
func (s *Scanner) ReadLine() Value {
	// Read a line using the scanner and return it as a Value object
	if s.sc.Scan() {
		return Value(s.sc.Text())
	}
	// Panic if there's an error while reading input
	panic("scan error")
}

// ReadLines function reads N lines of input and returns them as a slice of Value objects
func (s *Scanner) ReadLines(n int) Values {
	// Initialize an empty slice called a and append N Value objects to it
	var a Values
	for i := 0; i < n; i++ {
		// Read a single line and append it to the slice
		a = append(a, s.ReadLine())
	}
	// Return the slice of Value objects
	return a
}

// Value structure to store a string value
type Value string

// String function returns the string representation of the Value object
func (v Value) String() string {
	return string(v)
}

// Int function converts a Value object to an integer
func (v Value) Int() int {
	// Parse the string representation of the Value object to an integer and return it
	n, err := strconv.Atoi(v.String())
	if err!= nil {
		// Panic if there's an error while converting the Value object to an integer
		panic(err)
	}
	return n
}

// Float64 function converts a Value object to a float64
func (v Value) Float64() float64 {
	// Parse the string representation of the Value object to a float64 and return it
	f, err := strconv.ParseFloat(v.String(), 64)
	if err!= nil {
		// Panic if there's an error while converting the Value object to a float64
		panic(err)
	}
	return f
}

// Strings function splits a Value object into a slice of strings based on whitespace
func (v Value) Strings() []string {
	// Split the string representation of the Value object based on whitespace and return the slice
	return strings.Split(v.String(), " ")
}

// Ints function converts a Value object to a slice of integers
func (v Value) Ints() []int {
	// Convert each string in the slice returned by the Strings function to an integer and return the slice
	var a []int
	for _, s := range v.Strings() {
		n, err := strconv.Atoi(s)
		if err!= nil {
			// Panic if there's an error while converting a string to an integer
			panic(err)
		}
		a = append(a, n)
	}
	return a
}

// Float64s function converts a Value object to a slice of float64s
func (v Value) Float64s() []float64 {
	// Parse each string in the slice returned by the Strings function to a float64 and return the slice
	var a []float64
	for _, s := range v.Strings() {
		f, err := strconv.ParseFloat(s, 64)
		if err!= nil {
			// Panic if there's an error while converting a string to a float64
			panic(err)
		}
		a = append(a, f)
	}
	return a
}

// Runes function converts a Value object to a slice of runes
func (v Value) Rune