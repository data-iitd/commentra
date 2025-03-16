package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

const MAX = 21

// Function prototypes
func init(int)
func move(int)

// Global variables to hold the state of the game
var n, x, y int
var fld [MAX][MAX]int

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	for {
		scanner.Scan()
		n := scanner.Text()
		if n == "0" {
			break
		}
		n_int := parseInt(n)
		// Initialize the field based on the size provided
		init(n_int)
		// Read the number of moves to be made
		scanner.Scan()
		m := parseInt(scanner.Text())
		// Execute the moves
		move(m)
		// Print "Yes" if all fields are cleared, otherwise print "No"
		if n_int == 0 {
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
	for i := 0; i < MAX; i++ {
		for j := 0; j < MAX; j++ {
			fld[i][j] = 0
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
	var buf string
	for i > 0 {
		fmt.Scan(&buf, &a)
		// Determine the direction based on the input
		switch buf {
		case "N":
			for a > 0 {
				// Update the position based on the direction
				if d%2 == 0 {
					y--
				} else {
					x--
				}
				a--
				// Check if the new position has an obstacle
				if fld[y][x] == 1 {
					// Remove the obstacle and decrement the count of remaining obstacles
					fld[y][x] = 0
					n--
				}
			}
		case "E":
			for a > 0 {
				// Update the position based on the direction
				if d%2 == 0 {
					x++
				} else {
					y--
				}
				a--
				// Check if the new position has an obstacle
				if fld[y][x] == 1 {
					// Remove the obstacle and decrement the count of remaining obstacles
					fld[y][x] = 0
					n--
				}
			}
		case "S":
			for a > 0 {
				// Update the position based on the direction
				if d%2 == 0 {
					y++
				} else {
					x++
				}
				a--
				// Check if the new position has an obstacle
				if fld[y][x] == 1 {
					// Remove the obstacle and decrement the count of remaining obstacles
					fld[y][x] = 0
					n--
				}
			}
		case "W":
			for a > 0 {
				// Update the position based on the direction
				if d%2 == 0 {
					x--
				} else {
					y++
				}
				a--
				// Check if the new position has an obstacle
				if fld[y][x] == 1 {
					// Remove the obstacle and decrement the count of remaining obstacles
					fld[y][x] = 0
					n--
				}
			}
		}
		i--
	}
}

func parseInt(s string) int {
	var result int
	fmt.Sscanf(s, "%d", &result)
	return result
}

