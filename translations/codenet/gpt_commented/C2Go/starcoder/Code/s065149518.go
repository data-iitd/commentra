package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Global variables to hold the state of the game
var n, x, y int
var fld [21][21]int

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
		fmt.Printf("%s\n", n > 0? "No" : "Yes")
	}
}

// Function to initialize the game field
func init(i int) {
	var a, b int
	// Set the starting position of the player
	x, y = 10, 10
	// Clear the field by setting all values to 0
	for a = 0; a < 21; a++ {
		for b = 0; b < 21; b++ {
			fld[a][b] = 0
		}
	}
	// Read the positions of obstacles and mark them in the field
	for ; i > 0; i-- {
		fmt.Scanf("%d %d", &a, &b)
		fld[b][a] = 1 // Mark the position as occupied
	}
}

// Function to process the moves made by the player
func move(i int) {
	var a, d int
	var buf string
	// Process each move command
	for ; i > 0; i-- {
		// Read the direction and the number of steps
		fmt.Scanf("%s %d", &buf, &a)
		// Determine the direction based on the input
		switch buf[0] {
		case 'N':
			d = 0 // North
		case 'E':
			d = 1 // East
		case 'S':
			d = 2 // South
		case 'W':
			d = 3 // West
		}
		// Move in the specified direction for the given number of steps
		for ; a > 0; a-- {
			// Update the position based on the direction
			d % 2 == 0? x-- : x++
			d == 0? y-- : y++
			// Check if the new position has an obstacle
			if fld[y][x] == 1 {
				// Remove the obstacle and decrement the count of remaining obstacles
				fld[y][x] = 0
				n--
			}
		}
	}
}

