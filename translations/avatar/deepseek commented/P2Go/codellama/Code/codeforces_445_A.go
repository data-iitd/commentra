
package main

import "fmt"

func main() {
	var n, m int
	fmt.Scan(&n, &m)
	// Read the number of rows and columns
	l := make([][]string, n)
	// Initialize an empty list to store the rows of the grid
	for i := 0; i < n; i++ {
		// Loop through each row
		var s string
		fmt.Scan(&s)
		// Read the row
		s = string(s)
		// Convert it to a list of characters
		for j := 0; j < m; j++ {
			// Loop through each column in the row
			if s[j] == '.' {
				// Check if the cell is a dot
				if (i+j)%2 == 1 {
					s = s[:j] + "W" + s[j+1:]
					// If the sum of row index and column index is odd, color the cell 'W'
				} else {
					s = s[:j] + "B" + s[j+1:]
					// Otherwise, color the cell 'B'
				}
			}
		}
		l[i] = []string{s}
		// Add the processed row to the list
	}
	for _, c := range l {
		fmt.Println(c[0])
		// Print each row as a string
	}
}

