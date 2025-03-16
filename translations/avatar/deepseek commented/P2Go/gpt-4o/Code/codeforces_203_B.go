package main

import (
	"fmt"
)

func solveCase() {
	// Read the dimensions of the grid and the number of operations
	var n, m int
	fmt.Scan(&n, &m)

	// Initialize a count grid with all elements set to 0
	count := make([][]int, n)
	for i := range count {
		count[i] = make([]int, n)
	}

	// Initialize the answer to -1
	ans := -1

	// Loop through each operation
	for k := 0; k < m; k++ {
		// Read the coordinates of the operation
		var x, y int
		fmt.Scan(&x, &y)

		// Adjust the coordinates to zero-based index
		x--
		y--

		// Flag to check if a cell in the 3x3 grid reaches a count of 9
		found := false

		// Check the 3x3 grid centered at (x, y)
		for i := x - 2; i <= x; i++ {
			for j := y - 2; j <= y; j++ {
				if i >= 0 && i < n && j >= 0 && j < n {
					count[i][j]++
					if count[i][j] == 9 {
						found = true
					}
				}
			}
		}

		// If a cell in the 3x3 grid reaches a count of 9, update ans and break
		if found {
			ans = k + 1
			break
		}
	}

	// Print the result
	fmt.Println(ans)
}

func main() {
	solveCase()
}

// <END-OF-CODE>
