package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Read the dimensions of the grid (N) and the number of moves (M)
	N, _ := strconv.Atoi(os.Args[1])
	M, _ := strconv.Atoi(os.Args[2])

	// Initialize a 2D array to keep track of the black cells, with padding to avoid boundary checks
	black := make([][]int, N+2)
	for i := range black {
		black[i] = make([]int, N+2)
	}

	// Loop through each move
	for m := 1; m <= M; m++ {
		// Read the coordinates of the current move
		x, _ := strconv.Atoi(os.Args[3*m-2])
		y, _ := strconv.Atoi(os.Args[3*m-1])

		// Increment the count of black cells in the surrounding 3x3 area
		for xx := x - 1; xx <= x+1; xx++ {
			for yy := y - 1; yy <= y+1; yy++ {
				// Increment the count for the current cell
				if black[xx][yy]++; black[xx][yy] == 9 { // Check if the count reaches 9
					fmt.Println(m) // Print the move number where the condition is met
					return // Exit the program
				}
			}
		}
	}

	// If no cell reached the count of 9 after all moves, print -1
	fmt.Println("-1")
}

