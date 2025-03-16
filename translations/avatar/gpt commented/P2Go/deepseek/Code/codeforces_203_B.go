package main

import (
	"bufio"
	"fmt"
	"os"
)

func solveCase() {
	// Read the dimensions of the grid (n) and the number of operations (m)
	var n, m int
	fmt.Scan(&n, &m)
	
	// Initialize a 2D slice to keep track of counts for each cell in the grid
	count := make([][]int, n)
	for i := 0; i < n; i++ {
		count[i] = make([]int, n)
		for j := 0; j < n; j++ {
			count[i][j] = 0 // Each cell starts with a count of 0
		}
	}
	
	ans := -1 // Initialize the answer variable to -1 (indicating no solution found)
	
	// Process each operation
	for k := 0; k < m; k++ {
		// Read the coordinates for the current operation and adjust for 0-based indexing
		var x, y int
		fmt.Scan(&x, &y)
		x -= 1
		y -= 1
		
		found := false // Flag to indicate if a cell has reached the count of 9
		
		// Iterate over the 3x3 grid centered at (x, y)
		for i := x - 2; i <= x + 1; i++ {
			for j := y - 2; j <= y + 1; j++ {
				// Check if the indices are within the bounds of the grid
				if i >= 0 && i < n && j >= 0 && j < n {
					count[i][j] += 1 // Increment the count for the current cell
					
					// Check if the count for this cell has reached 9
					if count[i][j] == 9 {
						found = true // Mark that we found a cell with count 9
					}
				}
			}
		}
		
		// If a cell with count 9 was found, update the answer and break the loop
		if found {
			ans = k + 1 // Store the 1-based index of the operation
			break
		}
	}
	
	// Print the result: the operation number where a cell reached count 9, or -1 if none did
	fmt.Println(ans)
}

func main() {
	solveCase()
}

