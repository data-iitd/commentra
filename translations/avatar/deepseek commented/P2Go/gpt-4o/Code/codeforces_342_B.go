package main

import (
	"fmt"
	"strings"
)

func main() {
	var n, m, s, f int
	fmt.Scan(&n, &m, &s, &f) // Read values of n, m, s, and f

	// Determine the direction and character based on the starting and finishing points
	var d int
	var c string
	if s < f {
		d = 1  // Set direction to right (R)
		c = "R"
	} else {
		d = -1 // Set direction to left (L)
		c = "L"
	}

	res := strings.Builder{} // Initialize a strings.Builder to store the result
	i := 1                    // Initialize step counter
	j := s                    // Initialize current position
	var t, l, r int
	k := 1 // Initialize the current time step

	// Loop until the current position reaches the finishing point
	for j != f {
		if i > t && k < m { // Check if it's time to update the time step and there are more steps
			fmt.Scan(&t, &l, &r) // Read new values for t, l, and r
			k++                  // Increment the time step counter
		}

		if i == t && (l <= j && j <= r || l <= j+d && j+d <= r) { // Check if it's the specified time step and the position is within the allowed range
			res.WriteString("X") // Append 'X' to the result string
		} else {
			res.WriteString(c) // Append the direction character to the result string
			j += d             // Update the current position
		}
		i++ // Increment the step counter
	}

	fmt.Println(res.String()) // Print the result string
}

// <END-OF-CODE>
