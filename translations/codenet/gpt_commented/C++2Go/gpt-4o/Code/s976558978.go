/*
URL_HERE
*/

/*
This section includes necessary packages and defines various constants and variables.
*/
package main

import (
	"fmt"
	"math"
	"os"
)

// Mathematical constants and limits
const (
	PI        = 3.141592653589793238462643383279502884197169399375105820974
	ten5p1   = 100001
	ten6p1   = 1000001
	ten8p1   = 100000001
	ten9p1   = 1000000001
)

// Type definitions for convenience
type (
	uint  = uint32
	ll    = int64
	ull   = uint64
)

// Function to read an integer from input
func readi() int {
	var varInt int
	fmt.Scan(&varInt)
	return varInt
}

// Function to write an integer to output
func writei(varInt int) {
	fmt.Print(varInt)
}

// Function to write a new line
func writeln() {
	fmt.Println()
}

// Main function
func main() {
	// Run local test with specified input file
	file, err := os.Open("dataabc155A.txt")
	if err != nil {
		file = os.Stdin
	}
	defer file.Close()

	// Read two integers from input
	var a, b int
	fmt.Fscanf(file, "%d %d", &a, &b)

	// Output the smaller integer b times
	if a < b {
		for i := 0; i < b; i++ {
			writei(a) // Write 'a' b times
		}
		writeln() // New line after output
	} else {
		for i := 0; i < a; i++ {
			writei(b) // Write 'b' a times
		}
		writeln() // New line after output
	}
}

// <END-OF-CODE>
