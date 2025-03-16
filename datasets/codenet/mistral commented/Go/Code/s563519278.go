
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Main function is the entry point of the program
func main() {
	// Initialize variable N to store the number of elements in the array
	var N int
	fmt.Scan(&N) // Read the number of elements from the standard input

	// Initialize a scanner to read words from the standard input
	scanner := bufio.NewScanner(os.Stdin)
	// Set the split function of the scanner to split the input into words
	scanner.Split(bufio.ScanWords)

	// Initialize an array 'v' of size N to store the frequency of each element
	v := make([]int, N)

	// Iterate through the input elements and update the frequency in the array 'v'
	for i := 1; i < N; i++ {
		// Read the next element from the standard input
		scanner.Scan()
		// Convert the string to integer 'a'
		a, _ := strconv.Atoi(scanner.Text())
		// Update the frequency of the element 'a-1' in the array 'v'
		v[a-1]++
	}

	// Initialize a writer to write the output to the standard output
	w := bufio.NewWriter(os.Stdout)
	// Iterate through the array 'v' and print each element to the standard output
	for _, e := range v {
		// Print each element to the standard output
		fmt.Fprintln(w, e)
	}
	// Flush the writer buffer to write the output
	w.Flush()

	// End of the code
}

