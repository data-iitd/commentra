package main

import (
	"bufio"
	"fmt"
	"io"
	"math"
	"os"
	"strconv"
	"strings"
)

// Run function processes input from the reader and writes output to the writer
func Run(r io.Reader, w io.Writer) {
	// Initialize a new scanner to read input
	sc := NewScanner(r)

	// Read the first line of input and parse N (number of lines) and D (distance threshold)
	a := sc.ReadLine().Ints()
	N, D := a[0], a[1]

	// Read the next N lines of input, each containing a pair of integers
	lines := sc.ReadLines(N).Ints()

	// Initialize a counter for the number of points within the distance D
	count := 0
	// Iterate over each line of input
	for _, line := range lines {
		// Calculate the Euclidean distance from the origin (0, 0)
		d := math.Sqrt(float64(line[0]*line[0] + line[1]*line[1]))
		// Check if the distance is less than or equal to D
		if float64(D) >= d {
			count++ // Increment the count if within distance
		}
	}
	// Output the total count of points within distance D
	fmt.Fprintln(w, count)
}

// main function serves as the entry point of the program
func main() {
	// Call the Run function with standard input and output
	Run(os.Stdin, os.Stdout)
}

// Scanner struct wraps bufio.Scanner for reading input
type Scanner struct {
	sc *bufio.Scanner
}

// NewScanner initializes a new Scanner with the provided io.Reader
func NewScanner(r io.Reader) *Scanner {
	return &Scanner{sc: bufio.NewScanner(r)}
}

// ReadLine reads a single line from the input and returns it as a Value
func (s *Scanner) ReadLine() Value {
	if s.sc.Scan() {
		return Value(s.sc.Text())
	}
	panic("scan error") // Panic if scanning fails
}

// ReadLines reads n lines from the input and returns them as Values
func (s *Scanner) ReadLines(n int) Values {
	var a Values
	// Loop to read n lines
	for i := 0; i < n; i++ {
		a = append(a, s.ReadLine()) // Append each line to the Values slice
	}
	return a // Return the slice of Values
}

// Value type represents a string value with additional methods for conversion
type Value string

// String returns the string representation of the Value
func (v Value) String() string {
	return string(v)
}

// Int converts the Value to an integer
func (v Value) Int() int {
	n, err := strconv.Atoi(v.String())
	if err != nil {
		panic(err) // Panic if conversion fails
	}
	return n
}

// Float64 converts the Value to a float64
func (v Value) Float64() float64 {
	f, err := strconv.ParseFloat(v.String(), 64)
	if err != nil {
		panic(err) // Panic if conversion fails
	}
	return f
}

// Strings splits the Value into a slice of strings
func (v Value) Strings() []string {
	return strings.Split(v.String(), " ")
}

// Ints converts the Value to a slice of integers
func (v Value) Ints() []int {
	var a []int
	// Split the Value into strings and convert each to an integer
	for _, s := range v.Strings() {
		n, err := strconv.Atoi(s)
		if err != nil {
			panic(err) // Panic if conversion fails
		}
		a = append(a, n) // Append the integer to the slice
	}
	return a // Return the slice of integers
}

// Float64s converts the Value to a slice of float64
func (v Value) Float64s() []float64 {
	var a []float64
	// Split the Value into strings and convert each to a float64
	for _, s := range v.Strings() {
		f, err := strconv.ParseFloat(s, 64)
		if err != nil {
			panic(err) // Panic if conversion fails
		}
		a = append(a, f) // Append the float64 to the slice
	}
	return a // Return the slice of float64
}

// Runes converts the Value to a slice of runes
func (v Value) Runes() []rune {
	return []rune(v.String())
}

// Values type represents a slice of Value
type Values []Value

// Strings converts the Values to a slice of string slices
func (v Values) Strings() [][]string {
	var a [][]string
	// Loop through each Value and convert to strings
	for _, value := range v {
		a = append(a, value.Strings())
	}
	return a // Return the slice of string slices
}

// Ints converts the Values to a slice of integer slices
func (v Values) Ints() [][]int {
	var a [][]int
	// Loop through each Value and convert to integers
	for _, value := range v {
		a = append(a, value.Ints())
	}
	return a // Return the slice of integer slices
}

// Float64s converts the Values to a slice of float64 slices
func (v Values) Float64s() [][]float64 {
	var a [][]float64
	// Loop through each Value and convert to float64
	for _, value := range v {
		a = append(a, value.Float64s())
	}
	return a // Return the slice of float64 slices
}

// Runes converts the Values to a slice of rune slices
func (v Values) Runes() [][]rune {
	var a [][]rune
	// Loop through each Value and convert to runes
	for _, value := range v {
		a = append(a, value.Runes())
	}
	return a // Return the slice of rune slices
}
