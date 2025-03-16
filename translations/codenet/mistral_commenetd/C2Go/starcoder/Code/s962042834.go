
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function to calculate the number of unique paths in a grid
func kansu(a, b int) {
	var i, j, x, y, n int
	var suu [17][17]int
	var kouji [17][17]int

	fmt.Print("Enter the number of obstacles in the grid: ")
	fmt.Scanf("%d", &n) // Read user input for number of obstacles

	// Initialize 2D array kouji with zeros
	for i = 1; i <= a; i++ {
		for j = 1; j <= b; j++ {
			kouji[i][j] = 0
		}
	}

	// Read user input for obstacle positions and mark them in kouji
	for i = 0; i < n; i++ {
		fmt.Scanf("%d %d", &x, &y)
		kouji[x][y] = 1
	}

	// Initialize first row and column of suu with ones
	for i = 1; i <= a; i++ {
		for j = 1; j <= b; j++ {
			if kouji[i][j] == 1 {
				suu[i][j] = 0 // Set suu[i][j] to zero if cell is an obstacle
			} else {
				if i == 1 && j == 1 {
					suu[i][j] = 1 // Set suu[i][j] to one if it's the starting cell
				} else {
					if i == 1 {
						suu[i][j] = suu[i][j-1] // Set suu[i][j] to the value of suu[i][j-1]
					} else if j == 1 {
						suu[i][j] = suu[i-1][j] // Set suu[i][j] to the value of suu[i-1][j]
					} else {
						suu[i][j] = suu[i][j-1] + suu[i-1][j] // Set suu[i][j] to the sum of suu[i][j-1] and suu[i-1][j]
					}
				}
			}
		}
	}

	// Print the result (unique paths)
	fmt.Printf("The number of unique paths in the grid is: %d\n", suu[a][b])
}

func main() {
	var a, b int

	fmt.Print("Enter the dimensions of the grid (width and height): ")
	fmt.Scanf("%d %d", &a, &b) // Read user input for grid dimensions

	// Loop until user enters valid dimensions (non-zero)
	for a!= 0 && b!= 0 {
		kansu(a, b) // Call function kansu to calculate unique paths
		fmt.Print("Enter the dimensions of the next grid (width and height): ")
		fmt.Scanf("%d %d", &a, &b) // Read user input for next grid dimensions
	}
}

