// Importing required packages
package main

import (
	"bufio"  // For reading from I/O streams
	"fmt"   // For printing output
	"os"    // For accessing operating system functions
)

func main() {
	// Initializing a scanner for reading from standard input
	sc := bufio.NewScanner(os.Stdin)

	// Reading the first line from standard input and storing it in the string 's'
	sc.Scan()
	s := sc.Text()

	// Declaring and initializing a variable 'd' with the value of 'a' - 'A'
	d := 'a' - 'A'

	// Iterating through each character 'r' in the string 's'
	for _, r := range s {
		// Declaring and initializing a variable 'rr' with the value of 'r'
		rr := r

		// Checking if the current character 'r' is an uppercase letter
		if 'A' <= r && r <= 'Z' {
			// If yes, adding the value of 'd' to 'r' and storing it in 'rr'
			rr = r + d
		} else if 'a' <= r && r <= 'z' {
			// If no, subtracting the value of 'd' from 'r' and storing it in 'rr'
			rr = r - d
		}

		// Printing the transformed character 'rr' to the standard output
		fmt.Printf("%c", rr)
	}

	// Printing a newline character after the transformation is complete
	fmt.Println()
}

// End of the code
