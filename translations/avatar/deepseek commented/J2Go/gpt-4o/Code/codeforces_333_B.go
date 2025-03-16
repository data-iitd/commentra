package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Create a buffered reader for input
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	// Read the dimensions of the grid
	var n, m int
	fmt.Fscan(reader, &n, &m)

	// Initialize maps to keep track of banned rows and columns
	bannedRows := make(map[int]struct{})
	bannedCols := make(map[int]struct{})

	// Read each banned cell and add it to the appropriate map if it's not on the border
	for i := 0; i < m; i++ {
		var r, c int
		fmt.Fscan(reader, &r, &c)
		if r > 1 && r < n {
			bannedRows[r] = struct{}{}
		}
		if c > 1 && c < n {
			bannedCols[c] = struct{}{}
		}
	}

	// Calculate the number of cells that can be reached, accounting for banned rows and columns
	answer := (n - 2) * 2
	answer -= len(bannedRows)
	answer -= len(bannedCols)

	// Adjust the answer if the grid size is odd and the center cell is not banned
	if n%2 != 0 {
		mid := (n + 1) / 2
		if _, ok1 := bannedRows[mid]; !ok1 && _, ok2 := bannedCols[mid]; !ok2 {
			answer--
		}
	}

	// Output the final answer
	fmt.Fprintln(writer, answer)
}

// <END-OF-CODE>
