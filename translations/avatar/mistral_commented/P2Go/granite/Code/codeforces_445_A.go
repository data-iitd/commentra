
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

	// Read the number of rows (n) and columns (m) of the grid
	n, m, _ := reader.ReadLine()
	n, _ = strconv.Atoi(strings.TrimSpace(string(n)))
	m, _ = strconv.Atoi(strings.TrimSpace(string(m)))

	// Initialize an empty slice 'l' to store the rows of the grid
	l := make([][]string, n)

	// Iterate through each row 'i' in the grid
	for i := 0; i < n; i++ {
		// Read the row as a string from user input
		row, _ := reader.ReadString('\n')
		row = strings.TrimSpace(row)

		// Convert the row string into a slice for further processing
		row = strings.Split(row, "")

		// Iterate through each cell 'j' in the row
		for j := 0; j < m; j++ {
			// If the cell contains a '.', assign it a color based on its position in the grid
			if row[j] == "." {
				if (i+j)%2 == 0 { // If the row index and column index have the same parity
					row[j] = "W" // Assign the cell the color 'W'
				} else {
					row[j] = "B" // Assign the cell the color 'B'
				}
			}
		}

		// Append the processed row to the slice 'l'
		l[i] = row
	}

	// Print each row of the grid
	for _, row := range l {
		fmt.Println(strings.Join(row, ""))
	}
}
