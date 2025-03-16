package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	// Read the dimensions of the grid (N) and the number of moves (M)
	scanner.Scan()
	N := toInt(scanner.Text())
	scanner.Scan()
	M := toInt(scanner.Text())

	// Initialize a 2D slice to keep track of the black cells, with padding to avoid boundary checks
	black := make([][]int, N+2)
	for i := range black {
		black[i] = make([]int, N+2)
	}

	// Loop through each move
	for m := 1; m <= M; m++ {
		// Read the coordinates of the current move
		scanner.Scan()
		x := toInt(scanner.Text())
		scanner.Scan()
		y := toInt(scanner.Text())

		// Increment the count of black cells in the surrounding 3x3 area
		for xx := x - 1; xx <= x+1; xx++ {
			for yy := y - 1; yy <= y+1; yy++ {
				// Increment the count for the current cell
				black[xx][yy]++
				if black[xx][yy] == 9 { // Check if the count reaches 9
					fmt.Println(m) // Print the move number where the condition is met
					return         // Exit the program
				}
			}
		}
	}

	// If no cell reached the count of 9 after all moves, print -1
	fmt.Println("-1")
}

// Helper function to convert string to integer
func toInt(s string) int {
	var res int
	for _, c := range s {
		res = res*10 + int(c-'0')
	}
	return res
}

