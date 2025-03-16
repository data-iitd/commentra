package main

import "fmt"

func main() {
	// Read two integers n and m from input, representing the number of rows and columns
	var n, m int
	fmt.Scan(&n, &m)

	// Initialize an empty list to store the resulting grid
	l := make([][]byte, n)

	// Iterate over each row index i from 0 to n-1
	for i := 0; i < n; i++ {
		// Read a string input for the current row
		s := make([]byte, m)
		fmt.Scan(&s)

		// Iterate over each column index j from 0 to m-1
		for j := 0; j < m; j++ {
			// Check if the current cell is empty (represented by '.')
			if s[j] == '.' {
				// Assign 'W' or 'B' based on the parity of the sum of indices (i + j)
				if (i+j)%2 == 1 {
					s[j] = 'W' // Assign 'W' for odd sums
				} else {
					s[j] = 'B' // Assign 'B' for even sums
				}
			}
		}

		// Append the modified row (as a list) to the grid
		l[i] = s
	}

	// Print each row of the grid as a string
	for _, c := range l {
		fmt.Println(string(c))
	}
}

