package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

const MAX = 21

// Function prototypes
func init(n int)
func move(m int)

// Global variables
var n, x, y int
var fld [MAX][MAX]int

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	for {
		// Read the number of items to be collected
		scanner.Scan()
		n, _ = fmt.Sscanf(scanner.Text(), "%d", &n)
		if n == 0 {
			break
		}
		// Initialize the grid and the robot's position
		init(n)
		// Read the number of movements
		scanner.Scan()
		m, _ := fmt.Sscanf(scanner.Text(), "%d", &m)
		// Perform the movements
		move(m)
		// Output the result
		fmt.Println(n == 0)
	}
}

// Initializes the grid with items and sets the robot's starting position
func init(i int) {
	var a, b int
	// Set the starting position of the robot
	x, y = 10, 10
	// Clear the grid
	for i := range fld {
		for j := range fld[i] {
			fld[i][j] = 0
		}
	}
	// Read the positions of items and mark them in the grid
	for ; i > 0; i-- {
		scanner.Scan()
		fmt.Sscanf(scanner.Text(), "%d %d", &a, &b)
		fld[b][a] = 1
	}
}

// Moves the robot according to the given directions and collects items
func move(m int) {
	var a int
	var buf string
	for ; m > 0; m-- {
		scanner.Scan()
		fmt.Sscanf(scanner.Text(), "%s %d", &buf, &a)
		// Determine the direction and convert it to an index
		switch strings.TrimSpace(buf) {
		case "N":
			for ; a > 0; a-- {
				// Update the robot's position based on the direction
				switch {
				case x > 0:
					x--
				}
				// Check if the robot collects an item
				if fld[y][x] == 1 {
					fld[y][x] = 0
					n--
				}
			}
		case "E":
			for ; a > 0; a-- {
				// Update the robot's position based on the direction
				switch {
				case y < 20:
					y++
				}
				// Check if the robot collects an item
				if fld[y][x] == 1 {
					fld[y][x] = 0
					n--
				}
			}
		case "S":
			for ; a > 0; a-- {
				// Update the robot's position based on the direction
				switch {
				case x < 20:
					x++
				}
				// Check if the robot collects an item
				if fld[y][x] == 1 {
					fld[y][x] = 0
					n--
				}
			}
		case "W":
			for ; a > 0; a-- {
				// Update the robot's position based on the direction
				switch {
				case y > 0:
					y--
				}
				// Check if the robot collects an item
				if fld[y][x] == 1 {
					fld[y][x] = 0
					n--
				}
			}
		}
	}
}

