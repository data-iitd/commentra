
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Main function declaration

	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)

	var n, m int
	fmt.Fscanln(reader, &n, &m)

	bannedRows := make(map[int]bool)
	bannedCols := make(map[int]bool)

	for i := 0; i < m; i++ {
		// Reading banned cells and adding them to the respective Maps

		var r, c int
		fmt.Fscanln(reader, &r, &c)

		if r > 1 && r < n {
			bannedRows[r] = true
		}

		if c > 1 && c < n {
			bannedCols[c] = true
		}
	}

	var answer int
	answer = (n - 2) * 2
	answer -= len(bannedRows)
	answer -= len(bannedCols)

	if n%2!= 0 {
		// Special case when the number of rows is odd

		mid := (n + 1) / 2
		if!bannedRows[mid] &&!bannedCols[mid] {
			// If the middle cell is not banned, decrement the answer
			answer--
		}
	}

	fmt.Fprintln(writer, answer)
	writer.Flush()
}

