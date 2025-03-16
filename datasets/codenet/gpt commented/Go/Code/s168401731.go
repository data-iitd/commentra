package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// getScanner initializes a new scanner for the provided file pointer.
// It sets the scanner to split input by words and allocates a buffer size.
func getScanner(fp *os.File) *bufio.Scanner {
	scanner := bufio.NewScanner(fp)
	scanner.Split(bufio.ScanWords)
	scanner.Buffer(make([]byte, 500001), 500000)
	return scanner
}

// getNextString retrieves the next string from the scanner.
func getNextString(scanner *bufio.Scanner) string {
	scanner.Scan()
	return scanner.Text()
}

// getNextInt converts the next string from the scanner to an integer.
func getNextInt(scanner *bufio.Scanner) int {
	i, _ := strconv.Atoi(getNextString(scanner))
	return i
}

// getNextInt64 converts the next string from the scanner to a 64-bit integer.
func getNextInt64(scanner *bufio.Scanner) int64 {
	i, _ := strconv.ParseInt(getNextString(scanner), 10, 64)
	return i
}

// getNextUint64 converts the next string from the scanner to an unsigned 64-bit integer.
func getNextUint64(scanner *bufio.Scanner) uint64 {
	i, _ := strconv.ParseUint(getNextString(scanner), 10, 64)
	return i
}

// getNextFloat64 converts the next string from the scanner to a float64.
func getNextFloat64(scanner *bufio.Scanner) float64 {
	i, _ := strconv.ParseFloat(getNextString(scanner), 64)
	return i
}

func main() {
	// Initialize file pointers for input and output.
	fp := os.Stdin
	wfp := os.Stdout

	// Check for command line arguments to open input and output files.
	if len(os.Args) > 1 {
		fp, _ = os.Open(os.Args[1]) // Open input file if provided.
		if len(os.Args) > 2 {
			wfp, _ = os.Create(os.Args[2]) // Create output file if provided.
		}
	}

	// Create a scanner for reading input and a writer for output.
	scanner := getScanner(fp)
	writer := bufio.NewWriter(wfp)

	// Read the number of integers to process.
	n := getNextInt(scanner)

	// Initialize the answer as "second" and check for odd integers.
	ans := "second"
	for i := 0; i < n; i++ {
		a := getNextInt(scanner) // Read the next integer.
		if a%2 == 1 { // Check if the integer is odd.
			ans = "first" // If odd, set answer to "first".
			break // Exit the loop early if an odd integer is found.
		}
	}

	// Write the result to the output.
	fmt.Fprintln(writer, ans)
	writer.Flush() // Ensure all buffered data is written to the output.
}
