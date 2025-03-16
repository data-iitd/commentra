package main

import (
	"fmt"
)

const MAX = 21

// Global variables
var n, x, y int
var fld [MAX][MAX]int

func main() {
	var m int
	// Read the number of items to be collected
	for {
		if _, err := fmt.Scan(&n); err != nil || n == 0 {
			break
		}
		// Initialize the grid and the robot's position
		init(n)
		// Read the number of movements
		fmt.Scan(&m)
		// Perform the movements
		move(m)
		// Output the result
		if n > 0 {
			fmt.Println("No")
		} else {
			fmt.Println("Yes")
		}
	}
}

// Initializes the grid with items and sets the robot's starting position
func init(i int) {
	var a, b int
	// Set the starting position of the robot
	x, y = 10, 10
	// Clear the grid
	for j := range fld {
		for k := range fld[j] {
			fld[j][k] = 0
		}
	}
	// Read the positions of items and mark them in the grid
	for i > 0 {
		fmt.Scan(&a, &b)
		fld[b][a] = 1
		i--
	}
}

// Moves the robot according to the given directions and collects items
func move(i int) {
	var a int
	var direction string
	// Read each movement and execute it
	for i > 0 {
		fmt.Scanf("%1s %d", &direction, &a)
		var d int
		// Determine the direction and convert it to an index
		switch direction {
		case "N":
			d = 0
		case "E":
			d = 1
		case "S":
			d = 2
		case "W":
			d = 3
		}
		// Move the robot and collect items
		for a > 0 {
			if d%2 == 1 {
				if d == 1 {
					x++
				} else {
					x--
				}
			} else {
				if d == 0 {
					y++
				} else {
					y--
				}
			}
			// Check if the robot collects an item
			if fld[y][x] == 1 {
				fld[y][x] = 0
				n--
			}
			a--
		}
		i--
	}
}

// <END-OF-CODE>
