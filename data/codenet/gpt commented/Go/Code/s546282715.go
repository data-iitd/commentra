package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// getNextWord reads the next word from the scanner and returns it as a string.
func getNextWord(scanner *bufio.Scanner) string {
	scanner.Scan()
	return scanner.Text()
}

// getNextInt reads the next word from the scanner, converts it to an integer, and returns it.
func getNextInt(scanner *bufio.Scanner) int {
	i, _ := strconv.Atoi(getNextWord(scanner))
	return i
}

func main() {
	// Set the input source to standard input; if a file is provided as an argument, open that file.
	fp := os.Stdin
	if len(os.Args) > 1 {
		fp, _ = os.Open(os.Args[1])
	}

	// Create a new scanner to read from the input source and configure it to split input into words.
	scanner := bufio.NewScanner(fp)
	scanner.Split(bufio.ScanWords)

	// Create a buffered writer to output results to standard output.
	writer := bufio.NewWriter(os.Stdout)

	// Read the first two integers, n and m, from the input.
	n := getNextInt(scanner)
	m := getNextInt(scanner)

	// Initialize a map to store the positions that are blocked (not allowed).
	aa := make(map[int]int, 0)
	for i := 0; i < m; i++ {
		// Read each blocked position and mark it in the map.
		aa[getNextInt(scanner)] = 1
	}

	// Create a dynamic programming array to store the number of ways to reach each position.
	dp := make([]int, n+1)
	dp[0] = 1 // Base case: There is one way to be at the starting position (doing nothing).

	// Iterate through each position from 0 to n.
	for i := 0; i < n; i++ {
		// Check the next two positions (i+1 and i+2) to see if they can be reached.
		for ii := 1; ii <= 2 && i+ii <= n; ii++ {
			_, ok := aa[i+ii] // Check if the next position is blocked.
			if ok {
				continue // If blocked, skip to the next iteration.
			}
			// Update the number of ways to reach position i+ii based on the current position i.
			dp[i+ii] += dp[i]
			dp[i+ii] %= 1000000007 // Ensure the result stays within the modulo limit.
		}
	}

	// Output the total number of ways to reach position n.
	fmt.Fprintln(writer, dp[n])

	// Flush the buffered writer to ensure all output is written.
	writer.Flush()
}
