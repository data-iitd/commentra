package main

import (
	"fmt"
	"math"
)

func main() {
	var s string
	var x, y, k int
	var flag = true
	var co [2][101]int

	fmt.Scan(&s) // Reading the input string
	co[0][k] = x // Storing the initial x-coordinate
	co[1][k] = y // Storing the initial y-coordinate
	k++ // Incrementing the counter for storing coordinates

	// Updating the positions based on the direction commands
	for i := 0; i < len(s); i++ {
		switch s[i] {
		case 'L':
			x-- // Moving left
		case 'R':
			x++ // Moving right
		case 'U':
			y++ // Moving up
		case 'D':
			y-- // Moving down
		}
		co[0][k] = x // Storing the updated x-coordinate
		co[1][k] = y // Storing the updated y-coordinate
		k++ // Incrementing the counter for storing coordinates
	}

	// Checking for "BUG" pattern
	for i := 0; i < k-3; i++ {
		for j := i + 3; j < k; j++ {
			dx := int(math.Abs(float64(co[0][i] - co[0][j]))) // Calculating the absolute difference in x-coordinates
			dy := int(math.Abs(float64(co[1][i] - co[1][j]))) // Calculating the absolute difference in y-coordinates
			if (dx <= 1 && dy == 0) || (dy <= 1 && dx == 0) { // Checking if the movement forms a "bug" pattern
				flag = false // Setting the flag to false if a "bug" pattern is found
				break // Breaking out of the inner loop
			}
		}
		if !flag {
			break // Breaking out of the outer loop if a "bug" pattern is found
		}
	}

	// Outputting the result
	if flag {
		fmt.Println("OK") // Printing "OK" if no "bug" pattern is found
	} else {
		fmt.Println("BUG") // Printing "BUG" if a "bug" pattern is found
	}
}

// <END-OF-CODE>
