// Importing necessary packages
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Function to read next integer from the standard input
func nextInt(sc *bufio.Scanner) int {
	sc.Scan() // Scan the next token
	t, _ := strconv.Atoi(sc.Text()) // Convert the token to integer
	return t // Return the integer
}

// Function to reverse the subarray of array 'a' from index 'b' to 'e' (both inclusive)
func reva(b []int) {
	// Reverse the subarray using a simple method of swapping elements
	for i := 0; i < len(b)/2; i++ {
		b[i], b[len(b)-1-i] = b[len(b)-1-i], b[i]
	}
}

// Main function
func main() {
	// Initialize a scanner to read input from standard input
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords) // Split the input into words

	// Read the number of elements in the array 'a'
	n := nextInt(sc)
	// Allocate memory for the array 'a' of size 'n'
	a := make([]int, n)

	// Read 'n' integers from the standard input and store them in the array 'a'
	for i := range a {
		a[i] = nextInt(sc)
	}

	// Read the number of queries 'q'
	q := nextInt(sc)

	// Process each query by reversing the subarray of 'a'
	for i := 0; i < q; i++ {
		// Read the starting and ending indices of the subarray to be reversed
		b := nextInt(sc)
		e := nextInt(sc)

		// Reverse the subarray 'a[b:e]'
		reva(a[b:e])
	}

	// Write the reversed array 'a' to the standard output
	wtr := bufio.NewWriter(os.Stdout)
	for i := 0; i < n; i++ {
		// Write each element of the array 'a' to the standard output with a space in between (except for the first element)
		if i > 0 {
			fmt.Fprint(wtr, " ")
		}
		fmt.Fprint(wtr, a[i])
	}

	// Flush the buffer to write the output to the standard output
	fmt.Fprintln(wtr)
	wtr.Flush()

// End of the code
