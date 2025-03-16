package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// nextInt reads the next integer from the scanner and returns it.
func nextInt(sc *bufio.Scanner) int {
	sc.Scan() // Read the next token from the input
	t, _ := strconv.Atoi(sc.Text()) // Convert the token to an integer
	return t // Return the integer value
}

// reva reverses a slice of integers in place.
func reva(b []int) {
	for i := 0; i < len(b)/2; i++ { // Iterate only halfway through the slice
		// Swap the elements at positions i and len(b)-1-i
		b[i], b[len(b)-1-i] = b[len(b)-1-i], b[i]
	}
}

func main() {
	// Create a new scanner to read from standard input
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords) // Split input by whitespace

	// Read the number of elements in the array
	n := nextInt(sc)
	a := make([]int, n) // Initialize a slice of integers with length n

	// Populate the slice with integers from input
	for i := range a {
		a[i] = nextInt(sc) // Read each integer and store it in the slice
	}

	// Read the number of queries
	q := nextInt(sc)
	// Process each query
	for i := 0; i < q; i++ {
		b := nextInt(sc) // Read the starting index for the reversal
		e := nextInt(sc) // Read the ending index for the reversal
		reva(a[b:e]) // Reverse the slice from index b to e
	}

	// Create a buffered writer to output the results
	wtr := bufio.NewWriter(os.Stdout)
	// Write the modified array to output
	for i := 0; i < n; i++ {
		if i > 0 {
			fmt.Fprint(wtr, " ") // Print a space before each element except the first
		}
		fmt.Fprint(wtr, a[i]) // Print the current element
	}
	fmt.Fprintln(wtr) // Print a newline after the output
	wtr.Flush() // Flush the buffered writer to ensure all output is written
}
