package main

import (
	"fmt"
)

func main() {
	// Read two integers n and m from input, representing the number of rows and columns
	var n, m int
	fmt.Scan(&n, &m)

	// Initialize a slice to store the resulting grid
	l := make([][]rune, n)

	// Iterate over each row index i from 0 to n-1
	for i := 0; i < n; i++ {
		// Read a string input for the current row
		var s string
		fmt.Scan(&s)
		// Convert the string into a slice of runes for mutability
		row := []rune(s)

		// Iterate over each column index j from 0 to m-1
		for j := 0; j < m; j++ {
			// Check if the current cell is empty (represented by '.')
			if row[j] == '.' {
				// Assign 'W' or 'B' based on the parity of the sum of indices (i + j)
				if (i+j)%2 == 0 {
					row[j] = 'B' // Assign 'B' for even sums
				} else {
					row[j] = 'W' // Assign 'W' for odd sums
				}
			}
		}

		// Append the modified row (as a slice of runes) to the grid
		l[i] = row
	}

	// Print each row of the grid as a string
	for _, c := range l {
		fmt.Println(string(c))
	}
}

// <END-OF-CODE>
