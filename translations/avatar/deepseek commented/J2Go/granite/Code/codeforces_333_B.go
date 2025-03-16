
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
	n, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	m, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))

	// Initialize sets to keep track of banned rows and columns
	bannedRows := make(map[int]bool)
	bannedCols := make(map[int]bool)

	// Read each banned cell and add it to the appropriate set if it's not on the border
	for i := 0; i < m; i++ {
		r, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
		if r > 1 && r < n {
			bannedRows[r] = true
		}
		c, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
		if c > 1 && c < n {
			bannedCols[c] = true
		}
	}

	// Calculate the number of cells that can be reached, accounting for banned rows and columns
	answer := (n - 2) * 2
	answer -= len(bannedRows)
	answer -= len(bannedCols)

	// Adjust the answer if the grid size is odd and the center cell is not banned
	if n%2!= 0 {
		mid := (n + 1) / 2
		if!bannedRows[mid] &&!bannedCols[mid] {
			answer--
		}
	}

	// Output the final answer
	fmt.Println(answer)
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return strings.TrimRight(string(str), "\r\n")
	}
	return ""
}

