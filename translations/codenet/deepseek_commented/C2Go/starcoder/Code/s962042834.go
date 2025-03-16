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

// Function to calculate the number of ways to reach a cell
func kansu(a, b int) int {
	// Declare variables for loop indices and other necessary variables
	var i, j, x, y, n int
	var suu [17][17]int
	var kouji [17][17]int

	// Read the number of obstacles
	fmt.Scanf("%d", &n)

	// Initialize the kouji array to mark the positions of obstacles
	for i = 1; i <= a; i++ {
		for j = 1; j <= b; j++ {
			kouji[i][j] = 0
		}
	}

	// Read the positions of the obstacles and mark them in the kouji array
	for i = 0; i < n; i++ {
		fmt.Scanf("%d %d", &x, &y)
		kouji[x][y] = 1
	}

	// Initialize the suu array to store the number of ways to reach each cell
	for i = 1; i <= a; i++ {
		for j = 1; j <= b; j++ {
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
<<<<<<< HEAD
						suu[i][j] = suu[i][j - 1]
					} else if j == 1 {
						suu[i][j] = suu[i - 1][j]
					} else {
						suu[i][j] = suu[i][j - 1] + suu[i - 1][j]
=======
						suu[i][j] = suu[i][j-1]
					} else if j == 1 {
						suu[i][j] = suu[i-1][j]
					} else {
						suu[i][j] = suu[i][j-1] + suu[i-1][j]
>>>>>>> 98c87cb78a (data updated)
					}
				}
			}
		}
	}

	// Return the number of ways to reach the bottom-right corner of the grid
	return suu[a][b]
}

func main() {
	// Declare variables to store the dimensions of the grid
	var a, b int

	// Read the dimensions of the grid from the input
	fmt.Scanf("%d %d", &a, &b)

	// Continue reading and processing until both dimensions are zero
	for a!= 0 && b!= 0 {
		// Call the function kansu with the current dimensions
<<<<<<< HEAD
		fmt.Println(kansu(a, b))
=======
		fmt.Printf("%d\n", kansu(a, b))
>>>>>>> 98c87cb78a (data updated)
		// Read the next pair of dimensions
		fmt.Scanf("%d %d", &a, &b)
	}
}

