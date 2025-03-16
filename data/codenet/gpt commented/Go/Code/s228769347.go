package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

// getScanner initializes a new scanner for reading from the provided file pointer.
func getScanner(fp *os.File) *bufio.Scanner {
	scanner := bufio.NewScanner(fp)
	scanner.Split(bufio.ScanWords) // Set the scanner to split input by words.
	scanner.Buffer(make([]byte, 500001), 500000) // Set buffer size for the scanner.
	return scanner
}

// getNextString reads the next word from the scanner and returns it as a string.
func getNextString(scanner *bufio.Scanner) string {
	scanner.Scan() // Read the next token.
	return scanner.Text() // Return the text of the token.
}

// getNextInt converts the next word from the scanner to an integer and returns it.
func getNextInt(scanner *bufio.Scanner) int {
	i, _ := strconv.Atoi(getNextString(scanner)) // Convert the string to an int.
	return i // Return the integer.
}

// getNextInt64 converts the next word from the scanner to an int64 and returns it.
func getNextInt64(scanner *bufio.Scanner) int64 {
	i, _ := strconv.ParseInt(getNextString(scanner), 10, 64) // Convert the string to an int64.
	return i // Return the int64.
}

// getNextUint64 converts the next word from the scanner to a uint64 and returns it.
func getNextUint64(scanner *bufio.Scanner) uint64 {
	i, _ := strconv.ParseUint(getNextString(scanner), 10, 64) // Convert the string to a uint64.
	return i // Return the uint64.
}

// getNextFloat64 converts the next word from the scanner to a float64 and returns it.
func getNextFloat64(scanner *bufio.Scanner) float64 {
	i, _ := strconv.ParseFloat(getNextString(scanner), 64) // Convert the string to a float64.
	return i // Return the float64.
}

func main() {
	fp := os.Stdin // Default input is standard input.
	wfp := os.Stdout // Default output is standard output.

	// Check for command-line arguments to read from a file and write to a file.
	if len(os.Args) > 1 {
		fp, _ = os.Open(os.Args[1]) // Open the input file if provided.
		if len(os.Args) > 2 {
			wfp, _ = os.Create(os.Args[2]) // Create the output file if provided.
		}
	}

	scanner := getScanner(fp) // Initialize the scanner for input.
	writer := bufio.NewWriter(wfp) // Create a buffered writer for output.

	n := getNextInt(scanner) // Read the number of integers.
	ll := make([]int, n) // Create a slice to hold the integers.

	// Read n integers from the input.
	for i := 0; i < n; i++ {
		ll[i] = getNextInt(scanner) // Populate the slice with integers.
	}

	sort.Ints(ll) // Sort the slice of integers.

	ans := 0 // Initialize the answer counter.
	// Iterate through pairs of integers to find valid triplets.
	for i := 0; i < n-2; i++ {
		for j := i + 1; j < n-1; j++ {
			l := j + 1 // Start searching for the third element after the second element.
			r := n // Set the right boundary for binary search.
			// Perform binary search to find the count of valid third elements.
			for l < r {
				m := (l + r) >> 1 // Calculate the middle index.
				if ll[m] < ll[i]+ll[j] { // Check if the sum of the first two is greater than the middle element.
					l = m + 1 // Move the left boundary up.
					continue
				}
				r = m // Move the right boundary down.
			}
			// Count the number of valid third elements.
			ans += l - (j + 1) // Update the answer with the count of valid triplets.
		}
	}
	fmt.Fprintln(writer, ans) // Print the result to the output.

	writer.Flush() // Flush the buffered writer to ensure all output is written.
}
