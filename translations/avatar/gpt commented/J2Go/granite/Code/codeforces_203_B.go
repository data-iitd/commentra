
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	// Read the dimensions of the grid (N) and the number of moves (M)
	N, _ := strconv.Atoi(read(reader))
	M, _ := strconv.Atoi(read(reader))

	// Initialize a 2D array to keep track of the black cells, with padding to avoid boundary checks
	black := make([][]int, N+2)
	for i := 0; i < N+2; i++ {
		black[i] = make([]int, N+2)
	}

	// Loop through each move
	for m := 1; m <= M; m++ {
		// Read the coordinates of the current move
		x, _ := strconv.Atoi(read(reader))
		y, _ := strconv.Atoi(read(reader))

		// Increment the count of black cells in the surrounding 3x3 area
		for xx := x - 1; xx <= x+1; xx++ {
			for yy := y - 1; yy <= y+1; yy++ {
				// Increment the count for the current cell
				if black[xx][yy]++; black[xx][yy] == 9 {
					fmt.Println(m) // Print the move number where the condition is met
					return // Exit the program
				}
			}
		}
	}

	// If no cell reached the count of 9 after all moves, print -1
	fmt.Println(-1)
}

func read(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return string(str)
	}
	panic(err)
}

