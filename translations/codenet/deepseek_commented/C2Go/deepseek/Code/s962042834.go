package main

import (
	"fmt"
)

// Function prototype for kansu
func kansu(a, b int)

func main() {
	// Declare variables to store the dimensions of the grid
	var a, b int
	
	// Read the dimensions of the grid from the input
	fmt.Scan(&a, &b)
	
	// Continue reading and processing until both dimensions are zero
	for a != 0 && b != 0 {
		// Call the function kansu with the current dimensions
		kansu(a, b)
		// Read the next pair of dimensions
		fmt.Scan(&a, &b)
	}
}

// Function definition for kansu
func kansu(a, b int) {
	// Declare variables for loop indices and other necessary variables
	var i, j, x, y, n int
	
	// Declare 2D arrays to store the number of ways and the presence of obstacles
	var suu [17][17]int
	var kouji [17][17]int
	
	// Read the number of obstacles
	fmt.Scan(&n)
	
	// Initialize the kouji array to mark the positions of obstacles
	for i := 1; i <= a; i++ {
		for j := 1; j <= b; j++ {
			kouji[i][j] = 0
		}
	}
	
	// Read the positions of the obstacles and mark them in the kouji array
	for i := 0; i < n; i++ {
		fmt.Scan(&x, &y)
		kouji[x][y] = 1
	}
	
	// Initialize the suu array to store the number of ways to reach each cell
	for i := 1; i <= a; i++ {
		for j := 1; j <= b; j++ {
			// If the cell is an obstacle, set its value to 0
			if kouji[i][j] == 1 {
				suu[i][j] = 0
			} else {
				// If the cell is at the top-left corner, there is 1 way to reach it
				if i == 1 && j == 1 {
					suu[i][j] = 1
				} else {
					// Calculate the number of ways to reach the cell based on possible movements
					if i == 1 {
						suu[i][j] = suu[i][j - 1]
					} else if j == 1 {
						suu[i][j] = suu[i - 1][j]
					} else {
						suu[i][j] = suu[i][j - 1] + suu[i - 1][j]
					}
				}
			}
		}
	}
	
	// Print the number of ways to reach the bottom-right corner of the grid
	fmt.Println(suu[a][b])
}

