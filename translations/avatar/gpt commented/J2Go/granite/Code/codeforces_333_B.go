
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the dimensions of the grid
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)
	parts := strings.Split(input, " ")
	n, _ := strconv.Atoi(parts[0])
	m, _ := strconv.Atoi(parts[1])

	// Initialize sets to keep track of banned rows and columns
	bannedRows := make(map[int]bool)
	bannedCols := make(map[int]bool)

	// Read the banned rows and columns
	for i := 0; i < m; i++ {
		input, _ := reader.ReadString('\n')
		input = strings.TrimSpace(input)
		parts := strings.Split(input, " ")
		r, _ := strconv.Atoi(parts[0])
		c, _ := strconv.Atoi(parts[1])
		if r > 1 && r < n {
			bannedRows[r] = true
		}
		if c > 1 && c < n {
			bannedCols[c] = true
		}
	}

	// Calculate the initial answer based on the grid size
	answer := (n - 2) * 2

	// Subtract the number of banned rows and columns from the answer
	answer -= len(bannedRows)
	answer -= len(bannedCols)

	// If n is odd, check the middle row and column
	if n%2!= 0 {
		mid := (n + 1) / 2
		if!bannedRows[mid] &&!bannedCols[mid] {
			answer--
		}
	}

	// Output the final answer
	fmt.Println(answer)
}

// END-OF-CODE