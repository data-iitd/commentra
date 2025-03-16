package main

import (
	"fmt"
)

const MAX = 21

// Global variables to hold the state of the game
var n, x, y int
var fld [MAX][MAX]int

func main() {
	var m int
	// Continuously read the size of the field until a zero is encountered
	for {
		if _, err := fmt.Scan(&n); err != nil || n == 0 {
			break
		}
		// Initialize the field based on the size provided
		init(n)
		// Read the number of moves to be made
		fmt.Scan(&m)
		// Execute the moves
		move(m)
		// Print "Yes" if all fields are cleared, otherwise print "No"
		if n == 0 {
			fmt.Println("Yes")
		} else {
			fmt.Println("No")
		}
	}
}

// Function to initialize the game field
func init(i int) {
	var a, b int
	// Set the starting position of the player
	x, y = 10, 10
	// Clear the field by setting all values to 0
	for j := range fld {
		for k := range fld[j] {
			fld[j][k] = 0
		}
	}
	// Read the positions of obstacles and mark them in the field
	for i > 0 {
		fmt.Scan(&a, &b)
		fld[b][a] = 1 // Mark the position as occupied
		i--
	}
}

// Function to process the moves made by the player
func move(i int) {
	var a int
	var direction string
	// Process each move command
	for i > 0 {
		fmt.Scanf("%1s %d", &direction, &a)
		var d int
		// Determine the direction based on the input
		switch direction {
		case "N":
			d = 0 // North
		case "E":
			d = 1 // East
		case "S":
			d = 2 // South
		case "W":
			d = 3 // West
		}
		// Move in the specified direction for the given number of steps
		for a > 0 {
			if d%2 == 1 {
				if d == 1 {
					x++ // East
				} else {
					x-- // West
				}
			} else {
				if d == 0 {
					y-- // North
				} else {
					y++ // South
				}
			}
			// Check if the new position has an obstacle
			if fld[y][x] == 1 {
				// Remove the obstacle and decrement the count of remaining obstacles
				fld[y][x] = 0
				n--
			}
			a--
		}
		i--
	}
}

// <END-OF-CODE>
