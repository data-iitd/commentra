
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Function prototypes
func init(n int) {
	// Initialize the grid and the robot's position
}

func move(m int) {
	// Perform the movements
}

// Global variables
var (
	n, x, y int
	fld      [21][21]int
)

func main() {
	var m int
	// Read the number of items to be collected
	for {
		fmt.Scan(&n)
		if n == 0 {
			break
		}
		// Initialize the grid and the robot's position
		init(n)
		// Read the number of movements
		fmt.Scan(&m)
		// Perform the movements
		move(m)
		// Output the result
		fmt.Println(n)
	}
}

// Initializes the grid with items and sets the robot's starting position
func init(n int) {
	var a, b int
	// Set the starting position of the robot
	x, y = 10, 10
	// Clear the grid
	for i := 0; i < 21; i++ {
		for j := 0; j < 21; j++ {
			fld[i][j] = 0
		}
	}
	// Read the positions of items and mark them in the grid
	for i := 0; i < n; i++ {
		fmt.Scan(&a, &b)
		fld[b][a] = 1
	}
}

// Moves the robot according to the given directions and collects items
func move(m int) {
	var a, d int
	var buf string
	// Read each movement and execute it
	for i := 0; i < m; i++ {
		fmt.Scan(&buf, &a)
		// Determine the direction and convert it to an index
		switch buf[0] {
		case 'N':
			d = 0
		case 'E':
			d = 1
		case 'S':
			d = 2
		case 'W':
			d = 3
		}
		// Move the robot and collect items
		for j := 0; j < a; j++ {
			// Update the robot's position based on the direction
			if d%2 == 0 {
				if d == 0 {
					x--
				} else {
					x++
				}
			} else {
				if d == 2 {
					y--
				} else {
					y++
				}
			}
			// Check if the robot collects an item
			if fld[y][x] == 1 {
				fld[y][x] = 0
				n--
			}
		}
	}
}

// 