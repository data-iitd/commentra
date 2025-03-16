package main

import (
	"fmt"
	"math"
)

func main() {
	// Initialize variables for coordinates and control flags
	var x, y, k int
	flag := true

	// Create a slice to store coordinates
	co := make([][2]int, 101)

	// Read the input string from the user
	var s string
	fmt.Scan(&s)

	// Store the initial coordinates (0, 0) in the coordinates array
	co[k] = [2]int{x, y}
	k++ // Increment the index for the next coordinate

	// Process each character in the input string to update coordinates
	for i := 0; i < len(s); i++ {
		switch s[i] {
		case 'L': // Move left
			x--
		case 'R': // Move right
			x++
		case 'U': // Move up
			y++
		case 'D': // Move down
			y--
		}
		// Store the updated coordinates in the array
		co[k] = [2]int{x, y}
		k++ // Increment the index for the next coordinate
	}

	// Check for any bugs in the movement path
	for i := 0; i < k-3; i++ {
		for j := i + 3; j < k; j++ {
			// Calculate the differences in x and y coordinates
			dx := int(math.Abs(float64(co[i][0] - co[j][0])))
			dy := int(math.Abs(float64(co[i][1] - co[j][1])))

			// Check if the two points are too close to each other
			if (dx <= 1 && dy == 0) || (dy <= 1 && dx == 0) {
				flag = false // Set flag to false if a bug is found
				break        // Exit the inner loop
			}
		}
		if !flag {
			break // Exit the outer loop if a bug is found
		}
	}

	// Output the result based on the flag status
	if flag {
		fmt.Println("OK") // No bugs found
	} else {
		fmt.Println("BUG") // Bugs found in the movement path
	}
}

// <END-OF-CODE>
