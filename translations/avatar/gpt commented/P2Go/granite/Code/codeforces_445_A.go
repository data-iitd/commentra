
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	// Read two integers n and m from input, representing the number of rows and columns
	nTemp, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(strings.TrimSpace(nTemp))

	mTemp, _ := reader.ReadString('\n')
	m, _ := strconv.Atoi(strings.TrimSpace(mTemp))

	// Initialize an empty list to store the resulting grid
	l := make([][]string, n)

	// Iterate over each row index i from 0 to n-1
	for i := 0; i < n; i++ {
		// Read a string input for the current row
		sTemp, _ := reader.ReadString('\n')
		s := strings.TrimSpace(sTemp)

		// Convert the string into a list of characters for mutability
		s = strings.Split(s, "")

		// Iterate over each column index j from 0 to m-1
		for j := 0; j < m; j++ {
			// Check if the current cell is empty (represented by '.')
			if s[j] == "." {
				// Assign 'W' or 'B' based on the parity of the sum of indices (i + j)
				if (i + j) % 2 == 0 {
					s[j] = "W" // Assign 'W' for even sums
				} else {
					s[j] = "B" // Assign 'B' for odd sums
				}
			}
		}

		// Append the modified row (as a list) to the grid
		l[i] = s
	}

	// Print each row of the grid as a string
	for _, c := range l {
		fmt.Println(strings.Join(c, ""))
	}
}
