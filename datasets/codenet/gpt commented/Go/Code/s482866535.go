package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// getScanner initializes a new scanner for reading input from the provided file pointer.
func getScanner(fp *os.File) *bufio.Scanner {
	scanner := bufio.NewScanner(fp)
	scanner.Split(bufio.ScanWords) // Set the scanner to split input by words.
	scanner.Buffer(make([]byte, 500001), 500000) // Set the buffer size for the scanner.
	return scanner
}

// getNextString retrieves the next string from the scanner.
func getNextString(scanner *bufio.Scanner) string {
	scanner.Scan() // Read the next token from the input.
	return scanner.Text() // Return the scanned text.
}

// getNextInt retrieves the next integer from the scanner.
func getNextInt(scanner *bufio.Scanner) int {
	i, _ := strconv.Atoi(getNextString(scanner)) // Convert the next string to an integer.
	return i // Return the integer value.
}

func main() {
	// Determine the input source: standard input or a file specified as a command-line argument.
	fp := os.Stdin
	if len(os.Args) > 1 {
		fp, _ = os.Open(os.Args[1]) // Open the file if a filename is provided.
	}

	// Initialize the scanner for reading input and a writer for output.
	scanner := getScanner(fp)
	writer := bufio.NewWriter(os.Stdout)

	// Read the number of elements.
	n := getNextInt(scanner)
	mm := make([]int, n+1) // Create a slice to hold the input values.
	dp := make([][]int, n+1) // Create a 2D slice for dynamic programming.

	// Initialize the 2D slice for dynamic programming.
	for i := 0; i <= n; i++ {
		dp[i] = make([]int, n+1) // Each entry is initialized to zero by default.
	}

	// Read the input values into the mm slice.
	for i := 0; i < n; i++ {
		mm[i] = getNextInt(scanner) // Read the first value.
		mm[i+1] = getNextInt(scanner) // Read the second value.
	}

	// Perform dynamic programming to calculate the minimum cost.
	for l := 2; l <= n; l++ { // l is the length of the subproblem.
		for i := 1; i <= n-l+1; i++ { // i is the starting index of the subproblem.
			j := i + l - 1 // j is the ending index of the subproblem.
			for k := i; k <= j-1; k++ { // k is the partition point.
				// Calculate the cost of multiplying the matrices.
				d := dp[i][k] + dp[k+1][j] + mm[i-1]*mm[k]*mm[j]
				// Update the dp table with the minimum cost found.
				if dp[i][j] == 0 || dp[i][j] > d {
					dp[i][j] = d
				}
			}
		}
	}

	// Output the minimum cost of multiplying the entire sequence of matrices.
	fmt.Fprintln(writer, dp[1][n])

	// Flush the writer to ensure all output is written.
	writer.Flush()
}
