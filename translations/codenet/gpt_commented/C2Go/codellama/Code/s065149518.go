package main

import (
	"fmt"
	"strings"
)

const (
	MAX = 21
)

// Function prototypes
func init(n int)
func move(m int)

// Global variables to hold the state of the game
var n, x, y int
var fld [MAX][MAX]int

func main() {
	var m int
	// Continuously read the size of the field until a zero is encountered
	for {
		fmt.Scanf("%d", &n)
		if n == 0 {
			break
		}
		// Initialize the field based on the size provided
		init(n)
		// Read the number of moves to be made
		fmt.Scanf("%d", &m)
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
	x = 10
	y = 10
	// Clear the field by setting all values to 0
	for i := 0; i < MAX; i++ {
		for j := 0; j < MAX; j++ {
			fld[i][j] = 0
		}
	}
	// Read the positions of obstacles and mark them in the field
	for i > 0 {
		fmt.Scanf("%d %d", &a, &b)
		fld[b][a] = 1 // Mark the position as occupied
		i--
	}
}

// Function to process the moves made by the player
func move(i int) {
	var a, d int
	var buf string
	// Process each move command
	for i > 0 {
		// Read the direction and the number of steps
		fmt.Scanf("%s %d", &buf, &a)
		// Determine the direction based on the input
		switch buf {
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
			// Update the position based on the direction
			if d%2 == 0 {
				if d == 0 {
					x--
				} else {
					x++
				}
			} else {
				if d == 1 {
					y--
				} else {
					y++
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

