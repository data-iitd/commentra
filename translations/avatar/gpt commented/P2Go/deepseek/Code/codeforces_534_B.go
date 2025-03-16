package main

import (
	"fmt"
	"strconv"
)

func main() {
	var v1, v2, t, d int
	fmt.Scan(&v1, &v2)
	fmt.Scan(&t, &d)

	// Initialize acceleration factor and current velocity
	a := 1
	v := v1

	// Initialize total distance traveled
	distance := 0

	// Loop through each time unit from 0 to t-1
	for i := 0; i < t; i++ {
		// Check if the current velocity can exceed the maximum allowed velocity
		if v - v2 > (t - i - 1) * d {
			// Reverse acceleration direction if the velocity exceeds the limit
			a *= -1
			// Adjust current velocity to not exceed the maximum allowed velocity
			v = (t - i - 1) * d + v2
		}

		// Add current velocity to total distance
		distance += v

		// Update current velocity based on acceleration direction
		v += a * d
	}

	// Print the total distance traveled after t time units
	fmt.Println(distance)
}
