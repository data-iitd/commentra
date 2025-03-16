package main

import (
	"fmt"
)

func main() {
	// Read the input string representing movements
	var recordOfMovements string
	fmt.Scanln(&recordOfMovements)

	// Initialize the starting coordinates (x, y) at (0, 0)
	x, y := 0, 0

	// Define the movement directions: Left (L), Right (R), Up (U), Down (D)
	dMovement := map[rune][2]int{
		'L': {0, -1},
		'R': {0, 1},
		'U': {1, 0},
		'D': {-1, 0},
	}

	// Create a map to track visited coordinates, starting with the initial position
	visited := make(map[[2]int]struct{})
	visited[[2]int{x, y}] = struct{}{}

	// Initialize a flag to detect if a bug occurs
	bug := false

	// Iterate through each movement in the input string
	for _, move := range recordOfMovements {
		// Store the current position before the move
		temp := [2]int{x, y}

		// Update the coordinates based on the movement direction
		x += dMovement[move][0]
		y += dMovement[move][1]

		// Check if the new position has already been visited
		if _, exists := visited[[2]int{x, y}]; !exists {
			// If not visited, check for potential bugs by looking at all movement directions
			for step := range dMovement {
				// Check if moving in any direction from the new position leads to a visited position
				newX := x + dMovement[step][0]
				newY := y + dMovement[step][1]
				if [2]int{newX, newY} != temp && visited[[2]int{newX, newY}] == struct{}{} {
					// If a bug is detected, set the flag and break the loop
					bug = true
					break
				}
			}
		} else {
			// If the new position was already visited, set the bug flag
			bug = true
		}

		// If a bug has been detected, exit the loop
		if bug {
			break
		}

		// Mark the new position as visited
		visited[[2]int{x, y}] = struct{}{}
	}

	// After processing all movements, check if a bug was detected
	if bug {
		// Print 'BUG' if a bug was found
		fmt.Println("BUG")
	} else {
		// Print 'OK' if no bugs were found
		fmt.Println("OK")
	}
}

// <END-OF-CODE>
