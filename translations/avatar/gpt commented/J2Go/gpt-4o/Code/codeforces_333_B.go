package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Fast input reading
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	// Read the dimensions of the grid
	var n, m int
	fmt.Fscan(reader, &n, &m)

	// Initialize maps to keep track of banned rows and columns
	bannedRows := make(map[int]struct{})
	bannedCols := make(map[int]struct{})

	// Read the banned rows and columns
	for i := 0; i < m; i++ {
		var r, c int
		fmt.Fscan(reader, &r, &c)
		// Add to bannedRows if the row is within valid range
		if r > 1 && r < n {
			bannedRows[r] = struct{}{}
		}
		// Add to bannedCols if the column is within valid range
		if c > 1 && c < n {
			bannedCols[c] = struct{}{}
		}
	}

	// Calculate the initial answer based on the grid size
	answer := (n - 2) * 2
	// Subtract the number of banned rows and columns from the answer
	answer -= len(bannedRows)
	answer -= len(bannedCols)

	// If n is odd, check the middle row and column
	if n%2 != 0 {
		mid := (n + 1) / 2
		// If the middle row and column are not banned, decrement the answer
		if _, ok := bannedRows[mid]; !ok {
			if _, ok := bannedCols[mid]; !ok {
				answer--
			}
		}
	}

	// Output the final answer
	fmt.Fprintln(writer, answer)
}

// <END-OF-CODE>
