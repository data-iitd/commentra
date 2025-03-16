package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a new Scanner to read input from stdin
	reader := bufio.NewReader(os.Stdin)

	// Read the dimensions of the grid (N) and the number of moves (M)
	fmt.Print("Enter the dimensions of the grid (N) and the number of moves (M): ")
	input, _ := reader.ReadString('\n')
	input = strings.TrimSuffix(input, "\n")
	input = strings.TrimSuffix(input, "\r")
	input = strings.TrimSpace(input)
	dimensions := strings.Split(input, " ")
	N, _ := strconv.Atoi(dimensions[0])
	M, _ := strconv.Atoi(dimensions[1])

	// Initialize a 2D array to keep track of the black cells, with padding to avoid boundary checks
	black := make([][]int, N+2)
	for i := range black {
		black[i] = make([]int, N+2)
	}

	// Loop through each move
	for m := 1; m <= M; m++ {
		// Read the coordinates of the current move
		fmt.Print("Enter the coordinates of the current move: ")
		input, _ := reader.ReadString('\n')
		input = strings.TrimSuffix(input, "\n")
		input = strings.TrimSuffix(input, "\r")
		input = strings.TrimSpace(input)
		coordinates := strings.Split(input, " ")
		x, _ := strconv.Atoi(coordinates[0])
		y, _ := strconv.Atoi(coordinates[1])

		// Increment the count of black cells in the surrounding 3x3 area
		for xx := x - 1; xx <= x + 1; xx++ {
			for yy := y - 1; yy <= y + 1; yy++ {
				// Increment the count for the current cell
				black[xx][yy]++
				if black[xx][yy] == 9 { // Check if the count reaches 9
					fmt.Println(m) // Print the move number where the condition is met
					return
				}
			}
		}
	}

	// If no cell reached the count of 9 after all moves, print -1
	fmt.Println("-1")
}

