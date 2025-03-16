package main

import (
	"fmt"
)

func main() {
	var recordOfMovements string
	fmt.Scan(&recordOfMovements) // Read input for movements

	x, y := 0, 0 // Initialize the starting position of the bug
	dMovement := map[rune][2]int{ // Define a map to store the direction of movement
		'L': {0, -1},
		'R': {0, 1},
		'U': {1, 0},
		'D': {-1, 0},
	}
	d := make(map[[2]int]struct{}) // Initialize a map to store the visited positions
	d[[2]int{x, y}] = struct{}{}
	bug := false // Initialize a boolean variable to check if the bug is trapped

	// Iterate through each movement in the record
	for _, move := range recordOfMovements {
		// Save the current position of the bug
		temp := [2]int{x, y}

		// Move the bug based on the given direction
		x += dMovement[move][0]
		y += dMovement[move][1]

		// Check if the new position is already visited
		if _, visited := d[[2]int{x, y}]; !visited {
			// If not visited, check if there is a loop in the path
			for step := range dMovement {
				nextX := x + dMovement[step][0]
				nextY := y + dMovement[step][1]
				if [2]int{nextX, nextY} != temp && d[[2]int{nextX, nextY}] != struct{}{} {
					// If a loop is found, set the bug is trapped flag
					bug = true
					break
				}
			}
		}

		// If the new position is not visited, set it as visited
		d[[2]int{x, y}] = struct{}{}
	}

	// Check if the bug is trapped
	if bug {
		fmt.Println("BUG")
	} else {
		fmt.Println("OK")
	}
}

// <END-OF-CODE>
