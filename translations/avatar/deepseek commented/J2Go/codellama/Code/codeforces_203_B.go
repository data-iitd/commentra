
package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Read the first integer input, which is the size of the grid
	N, _ := strconv.Atoi(os.Args[1])

	// Read the second integer input, which is the number of operations
	M, _ := strconv.Atoi(os.Args[2])

	// Initialize a 2D array 'black' with dimensions (N+2) x (N+2)
	black := make([][]int, N+2)
	for i := range black {
		black[i] = make([]int, N+2)
	}

	// Loop through M operations
	for m := 1; m <= M; m++ {
		// Read the x-coordinate of the current operation
		x, _ := strconv.Atoi(os.Args[2*m-1])

		// Read the y-coordinate of the current operation
		y, _ := strconv.Atoi(os.Args[2*m])

		// Increment the elements in the 'black' array within the 3x3 neighborhood of (x, y)
		for xx := x - 1; xx <= x + 1; xx++ {
			for yy := y - 1; yy <= y + 1; yy++ {
				if black[xx][yy]++; black[xx][yy] == 9 {
					fmt.Println(m)
					return
				}
			}
		}
	}

	// If no element reaches 9 after all operations, print -1
	fmt.Println("-1")
}

