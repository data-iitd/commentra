package main

import (
	"fmt"
)

func main() {
	// Define the number of rows (n) and columns (m) of the grid
	var n, m int
	fmt.Scan(&n, &m)

	// Initialize a slice of slices to store the rows of the grid
	l := make([][]rune, n)

	// Iterate through each row 'i' in the grid
	for i := 0; i < n; i++ {
		// Read the row as a string from user input
		var row string
		fmt.Scan(&row)

		// Convert the row string into a slice of runes for further processing
		l[i] = []rune(row)

		// Iterate through each cell 'j' in the row
		for j := 0; j < m; j++ {
			// If the cell contains a '.', assign it a color based on its position in the grid
			if l[i][j] == '.' {
				if (i+j)%2 == 1 { // If the row index and column index have different parity
					l[i][j] = 'W' // Assign the cell the color 'W'
				} else {
					l[i][j] = 'B' // Assign the cell the color 'B'
				}
			}
		}
	}

	// Print each row of the grid
	for _, row := range l {
		fmt.Println(string(row))
	}
}

// <END-OF-CODE>
