package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Function to read the next word from the scanner
func getNextWord(scanner *bufio.Scanner) string {
	scanner.Scan()
	return scanner.Text()
}

// Function to read the next integer from the scanner
func getNextInt(scanner *bufio.Scanner) int {
	i, _ := strconv.Atoi(getNextWord(scanner))
	return i
}

// Main function
func main() {
	// Open the standard input file if the command line argument is provided
	fp := os.Stdin
	if len(os.Args) > 1 {
		fp, _ = os.Open(os.Args[1])
	}

	// Initialize the scanner and writer
	scanner := bufio.NewScanner(fp)
	scanner.Split(bufio.ScanWords)
	writer := bufio.NewWriter(os.Stdout)

	// Read the first two integers from the input
	n := getNextInt(scanner)
	m := getNextInt(scanner)

	// Initialize an associative array to store the elements
	aa := make(map[int]int, 0)
	// Read m elements and store them in the associative array
	for i := 0; i < m; i++ {
		aa[getNextInt(scanner)] = 1
	}

	// Initialize a slice of length n+1 for dynamic programming
	dp := make([]int, n+1)
	// Initialize the first element of the slice
	dp[0] = 1

	// Iterate through the array from index 0 to n-1
	for i := 0; i < n; i++ {
		// Iterate through the prefix sum from i to i+2
		for ii := 1; ii <= 2 && i+ii <= n; ii++ {
			// Skip if the current index and its sum are already present in the associative array
			_, ok := aa[i+ii]
			if ok {
				continue
			}
			// Calculate the dynamic programming value for the current index
			dp[i+ii] += dp[i]
			// Perform modulo operation to keep the value within the range of 10^9+7
			dp[i+ii] %= 1000000007
		}
	}

	// Print the final answer
	fmt.Fprintln(writer, dp[n])

	// Flush the writer buffer
	writer.Flush()

}