package main // Declaring the main package

import (
	"bufio" // Importing the bufio package for buffered I/O
	"fmt"   // Importing the fmt package for formatted I/O
	"os"    // Importing the os package for operating system functionalities
	"strconv" // Importing the strconv package for string conversions
)

// FastReader struct for reading input efficiently
type FastReader struct {
	scanner *bufio.Scanner // Scanner for reading input
}

// NewFastReader initializes a new FastReader
func NewFastReader() *FastReader {
	return &FastReader{scanner: bufio.NewScanner(os.Stdin)} // Initializing the scanner
}

// Next reads the next token from the input
func (fr *FastReader) Next() string {
	fr.scanner.Scan() // Scanning the next line
	return fr.scanner.Text() // Returning the scanned text
}

// NextInt reads the next integer from the input
func (fr *FastReader) NextInt() int {
	val, _ := strconv.Atoi(fr.Next()) // Converting the next token to an integer
	return val // Returning the integer value
}

// NextLong reads the next long integer from the input
func (fr *FastReader) NextLong() int64 {
	val, _ := strconv.ParseInt(fr.Next(), 10, 64) // Converting the next token to a long integer
	return val // Returning the long integer value
}

// NextLine reads the next line from the input
func (fr *FastReader) NextLine() string {
	fr.scanner.Scan() // Scanning the next line
	return fr.scanner.Text() // Returning the scanned line
}

// ModPower calculates x raised to the power of y modulo mod
func ModPower(x, y, mod int) int {
	res := 1 // Initializing the result variable to 1
	x %= mod // Calculating the remainder of x when divided by mod

	if x == 0 {
		return 0 // If x is 0, the result is 0
	}

	for y > 0 { // While y is greater than 0
		if y%2 == 1 { // If y is odd
			res = (res * x) % mod // Multiplying the result with x and taking the modulo with mod
		}
		y >>= 1 // Dividing y by 2
		x = (x * x) % mod // Squaring x and taking the modulo with mod
	}
	return res // Returning the final result
}

// Pair struct for storing two elements of different types
type Pair struct {
	First  interface{} // First element
	Second interface{} // Second element
}

func main() {
	fr := NewFastReader() // Creating a FastReader object for reading input

	a := make([]int64, 4) // Declaring and initializing an array of long integers named a with size 4

	for i := 0; i < 4; i++ { // Iterating through the elements of the array a
		a[i] = fr.NextLong() // Reading the next long integer from the input and storing it in the current element of the array
	}

	// Calculating the maximum product of pairs of elements in the array a
	result := max(a[0]*a[2], max(a[1]*a[3], max(a[0]*a[3], a[1]*a[2])))

	fmt.Println(result) // Printing the result to the standard output
}

// max function to find the maximum of two int64 values
func max(x, y int64) int64 {
	if x > y {
		return x
	}
	return y
}

// <END-OF-CODE>
