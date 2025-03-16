package main

import "fmt"

func main() {
	// Define the number of rows (n) and columns (m) of the grid
	n, m := 4, 4

	// Initialize an empty list 'l' to store the rows of the grid
	l := make([][]string, n)

	// Iterate through each row 'i' in the grid
	for i := 0; i < n; i++ {
		// Read the row as a string from user input
		row := "...."

		// Convert the row string into a list for further processing
		row = []string(row)

		// Iterate through each cell 'j' in the row
		for j := 0; j < m; j++ {

			// If the cell contains a '.', assign it a color based on its position in the grid
			if row[j] == "." {
				if (i+j)%2 == 0 { // If the row index and column index have different parity
					row[j] = "W" // Assign the cell the color 'W'
				} else {
					row[j] = "B" // Assign the cell the color 'B'
				}
			}
		}

		// Append the processed row to the list 'l'
		l[i] = row
	}

	// Print each row of the grid
	for _, row := range l {
		fmt.Println(string(row))
	}
}

