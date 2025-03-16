package main

import (
	"fmt"
)

func main() {
	var recordOfMovements string
	fmt.Scan(&recordOfMovements) // Take input for the movements of a character

	x, y := 0, 0 // Initialize the starting position (x, y) to (0, 0)
	dMovement := map[rune][2]int{
		'L': {0, -1},
		'R': {0, 1},
		'U': {1, 0},
		'D': {-1, 0},
	} // Define a map that maps each direction to its coordinate changes

	d := make(map[[2]int]struct{}) // Initialize a map to keep track of visited positions
	d[[2]int{x, y}] = struct{}{}    // Mark the starting position as visited
	bug := false                    // Set a flag bug to false

	for _, move := range recordOfMovements { // Iterate over each movement in the input
		temp := [2]int{x, y} // Store the current position in a temporary variable
		x += dMovement[move][0] // Update the x-coordinate based on the direction
		y += dMovement[move][1] // Update the y-coordinate based on the direction

		if _, visited := d[[2]int{x, y}]; !visited { // Check if the new position has been visited before
			for step := range dMovement { // Check the surrounding positions
				newX := x + dMovement[step][0]
				newY := y + dMovement[step][1]
				if [2]int{newX, newY} != temp && d[[2]int{newX, newY}] != struct{}{} {
					bug = true // Set the bug flag to true if a bug is detected
					break // Break out of the loop if a bug is detected
				}
			}
		} else {
			bug = true // Set the bug flag to true if the new position has been visited before
		}

		if bug { // Check if a bug was detected
			break // Break out of the loop if a bug was detected
		}

		d[[2]int{x, y}] = struct{}{} // Add the new position to the map d
	}

	if bug { // Check if a bug was detected
		fmt.Println("BUG") // Print 'BUG' if a bug was detected
	} else {
		fmt.Println("OK") // Print 'OK' if no bug was detected
	}
}

// <END-OF-CODE>
