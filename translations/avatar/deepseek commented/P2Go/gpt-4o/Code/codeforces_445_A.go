package main

import (
	"fmt"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m)
	// Read the number of rows and columns
	l := make([][]rune, n)
	// Initialize a slice to store the rows of the grid

	for i := 0; i < n; i++ {
		// Loop through each row
		var s string
		fmt.Scan(&s)
		// Read the row as a string

		l[i] = make([]rune, m)
		for j := 0; j < m; j++ {
			// Loop through each column in the row
			if s[j] == '.' {
				// Check if the cell is a dot
				if (i+j)%2 == 1 {
					l[i][j] = 'W'
					// If the sum of row index and column index is odd, color the cell 'W'
				} else {
					l[i][j] = 'B'
					// Otherwise, color the cell 'B'
				}
			} else {
				l[i][j] = s[j]
				// If the cell is not a dot, keep it as is
			}
		}
	}

	for _, c := range l {
		fmt.Println(string(c))
		// Print each row as a string
	}
}

// <END-OF-CODE>
