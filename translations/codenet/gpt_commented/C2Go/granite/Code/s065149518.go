
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Function prototypes
func init(n int) {
	// Initialize the game field
}

func move(m int) {
	// Process the moves made by the player
}

func main() {
	var n, m int
	// Continuously read the size of the field until a zero is encountered
	for {
		fmt.Fscanf(bufio.NewReader(os.Stdin), "%d", &n)
		if n == 0 {
			break
		}
		// Initialize the field based on the size provided
		init(n)
		// Read the number of moves to be made
		fmt.Fscanf(bufio.NewReader(os.Stdin), "%d", &m)
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
func init(n int) {
	// Set the starting position of the player
	x, y = 10, 10
	// Clear the field by setting all values to 0
}

// Function to process the moves made by the player
func move(m int) {
	var a, d int
	var buf string
	// Process each move command
	for i := 0; i < m; i++ {
		// Read the direction and the number of steps
		fmt.Fscanf(bufio.NewReader(os.Stdin), "%s %d", &buf, &a)
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
		for j := 0; j < a; j++ {
			// Update the position based on the direction
			if d%2 == 0 {
				if d == 0 {
					y--
				} else {
					y++
				}
			} else {
				if d == 1 {
					x++
				} else {
					x--
				}
			}
			// Check if the new position has an obstacle
			if fld[y][x] == 1 {
				// Remove the obstacle and decrement the count of remaining obstacles
				fld[y][x] = 0
				n--
			}
		}
	}
}

// Global variables to hold the state of the game
var fld [21][21]int
var x, y int

// Translate the above C code to Go and end with comment "