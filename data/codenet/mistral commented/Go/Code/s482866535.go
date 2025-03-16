package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Function to get a new scanner from a file pointer
func getScanner(fp *os.File) *bufio.Scanner {
	scanner := bufio.NewScanner(fp)
	scanner.Split(bufio.ScanWords)
	scanner.Buffer(make([]byte, 500001), 500000) // Buffer size for efficient reading
	return scanner
}

// Function to read the next string from the scanner
func getNextString(scanner *bufio.Scanner) string {
	scanner.Scan()
	return scanner.Text()
}

// Function to read the next integer from the scanner
func getNextInt(scanner *bufio.Scanner) int {
	i, _ := strconv.Atoi(getNextString(scanner))
	return i
}

// Main function to read input and process it
func main() {
	// Open the standard input stream if no file is provided as an argument
	fp := os.Stdin
	if len(os.Args) > 1 {
		// Open the file provided as an argument and use it as the input stream
		fp, _ = os.Open(os.Args[1])
	}

	// Initialize a new scanner from the input stream
	scanner := getScanner(fp)
	writer := bufio.NewWriter(os.Stdout)

	// Read the number of test cases from the input
	n := getNextInt(scanner)

	// Initialize a slice to store the prefix sum of squares of elements
	mm := make([]int, n+1)

	// Initialize a 2D slice to store the dynamic programming table
	dp := make([][]int, n+1)
	for i := 0; i <= n; i++ {
		dp[i] = make([]int, n+1)
	}

	// Read the elements and their prefix sum of squares from the input
	for i := 0; i < n; i++ {
		// Read the next integer as the current element
		mm[i+1] = getNextInt(scanner)
		// Read the next integer as the next element's prefix sum of square
		mm[i+1] += mm[i] * mm[i]
	}

	// Process the dynamic programming table for all subarrays of given size
	for l := 2; l <= n; l++ {
		for i := 1; i <= n-l+1; i++ {
			j := i + l - 1
			// Iterate through all subarrays of the current subarray
			for k := i; k <= j-1; k++ {
				// Calculate the sum of squares of elements in the current subarray
				d := dp[i][k] + dp[k+1][j] + mm[i-1]*mm[k]*mm[j]
				// Update the dynamic programming table if a larger sum is found
				if dp[i][j] == 0 || dp[i][j] > d {
					dp[i][j] = d
				}
			}
		}
	}

	// Print the result for the given input
	fmt.Fprintln(writer, dp[1][n])

	// Flush the writer to print the result
	writer.Flush()

	// End of the code
