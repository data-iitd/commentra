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
	sc := NewScanner(r);

	// Read the first line of input containing N and D
	a := sc.ReadLine().Ints();
	N, D := a[0], a[1]; // N is the number of lines, D is the side length of the square

	// Read N lines of input and store them in a slice called lines
	lines := sc.ReadLines(N).Ints();

	// Initialize a counter variable count to 0
	count := 0;

	// Iterate through each line in the lines slice
	for _, line := range lines {
		// Calculate the Euclidean distance of the current line from the origin (0,0)
		d := Math.sqrt(float(line[0]*line[0] + line[1]*line[1]));

		// If the distance of the current line is less than or equal to D, increment the counter
		if float(D) >= d {
			count++;
		}
	}

	// Write the final result to the output writer
	fmt.Fprintln(w, count);
}

// main function calls the Run function with standard input and output streams
func main() {
	Run(os.Stdin, os.Stdout);
}

// Function NewScanner initializes a new scanner object
func NewScanner(r io.Reader) *Scanner {
	return &Scanner{sc: bufio.NewScanner(r)};
}

// Scanner structure to read input lines
type Scanner struct {
	sc *bufio.Scanner;
}

// ReadLine function reads a single line of input and returns it as a Value object
func (s *Scanner) ReadLine() Value {
	// Read a line using the scanner and return it as a Value object
	if s.sc.Scan() {
		return Value(s.sc.Text());
	}
	// Panic if there's an error while reading input
	panic("scan error");
}

// ReadLines function reads N lines of input and returns them as a slice of Value objects
func (s *Scanner) ReadLines(n int) Values {
	// Initialize an empty slice called a and append N Value objects to it
	var a Values;
	for i := 0; i < n; i++ {
		// Read a single line and append it to the slice
		a = append(a, s.ReadLine());
	}
	// Return the slice of Value objects
	return a;
}

// Value structure to store a string value
type Value string

// String function returns the string representation of the Value object
func (v Value) String() string {
	return string(v);
}

// Int function converts a Value object to an integer
func (v Value) Int() int {
	// Parse the string representation of the Value object to an integer and return it
	n, err := strconv.Atoi(v.String());
	if err!= nil {
		// Panic if there's an error while converting the Value object to an integer
		panic(err);
	}
	return n;
}

// Float64 function converts a Value object to a float64
func (v Value) Float64() float64 {
	// Parse the string representation of the Value object to a float64 and return it
	f, err := strconv.ParseFloat(v.String(), 64);
	if err!= nil {
		// Panic if there's an error while converting the Value object to a float64
		panic(err);
	}
	return f;
}

// Strings function splits a Value object into a slice of strings based on whitespace
func (v Value) Strings() []string {
	// Split the string representation of the Value object based on whitespace and return the slice
	return strings.Split(v.String(), " ");
}

// Ints function converts a Value object to a slice of integers
func (v Value) Ints() []int {
	// Convert each string in the slice returned by the Strings function to an integer and return the slice
	var a []int;
	for _, s := range v.Strings() {
		n, err := strconv.Atoi(s);
		if err!= nil {
			// Panic if there's an error while converting a string to an integer
			panic(err);
		}
		a = append(a, n);
	}
	return a;
}

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
	sc := NewScanner(r);

	// Read the first line of input containing N and D
	a := sc.ReadLine().Ints();
	N, D := a[0], a[1]; // N is the number of lines, D is the side length of the square

	// Read N lines of input and store them in a slice called lines
	lines := sc.ReadLines(N).Ints();

	// Initialize a counter variable count to 0
	count := 0;

	// Iterate through each line in the lines slice
	for _, line := range lines {
		// Calculate the Euclidean distance of the current line from the origin (0,0)
		d := Math.sqrt(float(line[0]*line[0] + line[1]*line[1]));

		// If the distance of the current line is less than or equal to D, increment the counter
		if float(D) >= d {
			count++;
		}
	}

	// Write the final result to the output writer
	fmt.Fprintln(w, count);
}

// main function calls the Run function with standard input and output streams
func main() {
	Run(os.Stdin, os.Stdout);
}

// Function NewScanner initializes a new scanner object
func NewScanner(r io.Reader) *Scanner {
	return &Scanner{sc: bufio.NewScanner(r)};
}

// Scanner structure to read input lines
type Scanner struct {
	sc *bufio.Scanner;
}

// ReadLine function reads a single line of input and returns it as a Value object
func (s *Scanner) ReadLine() Value {
	// Read a line using the scanner and return it as a Value object
	if s.sc.Scan() {
		return Value(s.sc.Text());
	}
	// Panic if there's an error while reading input
	panic("scan error");
}

// ReadLines function reads N lines of input and returns them as a slice of Value objects
func (s *Scanner) ReadLines(n int) Values {
	// Initialize an empty slice called a and append N Value objects to it
	var a Values;
	for i := 0; i < n; i++ {
		// Read a single line and append it to the slice
		a = append(a, s.ReadLine());
	}
	// Return the slice of Value objects
	return a;
}

// Value structure to store a string value
type Value string

// String function returns the string representation of the Value object
func (v Value) String() string {
	return string(v);
}

// Int function converts a Value object to an integer
func (v Value) Int() int {
	// Parse the string representation of the Value object to an integer and return it
	n, err := strconv.Atoi(v.String());
	if err!= nil {
		// Panic if there's an error while converting the Value object to an integer
		panic(err);
	}
	return n;
}

// Float64 function converts a Value object to a float64
func (v Value) Float64() float64 {
	// Parse the string representation of the Value object to a float64 and return it
	f, err := strconv.ParseFloat(v.String(), 64);
	if err!= nil {
		// Panic if there's an error while converting the Value object to a float64
		panic(err);
	}
	return f;
}

// Strings function splits a Value object into a slice of strings based on whitespace
func (v Value) Strings() []string {
	// Split the string representation of the Value object based on whitespace and return the slice
	return strings.Split(v.String(), " ");
}

// Ints function converts a Value object to a slice of integers
func (v Value) Ints() []int {
	// Convert each string in the slice returned by the Strings function to an integer and return the slice
	var a []int;
	for _, s := range v.Strings() {
		n, err := strconv.Atoi(s);
		if err!= nil {
			// Panic if there's an error while converting a string to an integer
			panic(err);
		}
		a = append(a, n);
	}
	return a;
}

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
	sc := NewScanner(r);

	// Read the first line of input containing N and D
	a := sc.ReadLine().Ints();
	N, D := a[0], a[1]; // N is the number of lines, D is the side length of the square

	// Read N lines of input and store them in a slice called lines
	lines := sc.ReadLines(N).Ints();

	// Initialize a counter variable count to 0
	count := 0;

	// Iterate through each line in the lines slice
	for _, line := range lines {
		// Calculate the Euclidean distance of the current line from the origin (0,0)
		d := Math.sqrt(float(line[0]*line[0] + line[1]*line[1]));

		// If the distance of the current line is less than or equal to D, increment the counter
		if float(D) >= d {
			count++;
		}
	}

	// Write the final result to the output writer
	fmt.Fprintln(w, count);
}

// main function calls the Run function with standard input and output streams
func main() {
	Run(os.Stdin, os.Stdout);
}

// Function NewScanner initializes a new scanner object
func NewScanner(r io.Reader) *Scanner {
	return &Scanner{sc: bufio.NewScanner(r)};
}

// Scanner structure to read input lines
type Scanner struct {
	sc *bufio.Scanner;
}

// ReadLine function reads a single line of input and returns it as a Value object
func (s *Scanner) ReadLine() Value {
	// Read a line using the scanner and return it as a Value object
	if s.sc.Scan() {
		return Value(s.sc.Text());
	}
	// Panic if there's an error while reading input
	panic("scan error");
}

// ReadLines function reads N lines of input and returns them as a slice of Value objects
func (s *Scanner) ReadLines(n int) Values {
	// Initialize an empty slice called a and append N Value objects to it
	var a Values;
	for i := 0; i < n; i++ {
		// Read a single line and append it to the slice
		a = append(a, s.ReadLine());
	}
	// Return the slice of Value objects
	return a;
}

// Value structure to store a string value
type Value string

// String function returns the string representation of the Value object
func (v Value) String() string {
	return string(v);
}

// Int function converts a Value object to an integer
func (v Value) Int() int {
	// Parse the string re