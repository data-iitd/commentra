package main

import (
	"fmt"
	"strings"
)

func main() {
	var n, m, s, f int
	fmt.Scan(&n, &m, &s, &f)

	var d int
	var c string
	if s < f {
		d = 1  // Move right
		c = "R" // Character representing right movement
	} else {
		d = -1 // Move left
		c = "L" // Character representing left movement
	}

	res := strings.Builder{} // Initialize the result string to store the path taken
	i := 1                    // Initialize the step counter
	j := s                    // Current position

	var t, l, r int
	fmt.Scan(&t, &l, &r) // Read the first obstacle's position and range
	k := 1               // Counter for the number of obstacles processed

	// Loop until the current position reaches the finishing position
	for j != f {
		// Check if we need to read a new obstacle's position and range
		if i > t && k < m {
			fmt.Scan(&t, &l, &r) // Read the next obstacle's position and range
			k++                  // Increment the obstacle counter
		}

		// Check if the current position is at an obstacle
		if i == t && (l <= j && j <= r || l <= j+d && j+d <= r) {
			res.WriteString("X") // Mark the position with 'X' if it's blocked by an obstacle
		} else {
			res.WriteString(c) // Append the direction character to the result
			j += d             // Move to the next position in the determined direction
		}

		i++ // Increment the step counter
	}

	// Print the resulting path taken
	fmt.Println(res.String())
}

// <END-OF-CODE>
