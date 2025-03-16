package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	// Read initial velocities v1 and v2 from user input
	var input string
	fmt.Scanln(&input)
	velocities := strings.Split(input, " ")
	v1, _ := strconv.Atoi(velocities[0])
	v2, _ := strconv.Atoi(velocities[1])

	// Read time t and distance increment d from user input
	fmt.Scanln(&input)
	distanceParams := strings.Split(input, " ")
	t, _ := strconv.Atoi(distanceParams[0])
	d, _ := strconv.Atoi(distanceParams[1])

	// Initialize acceleration factor and current velocity
	a := 1
	v := v1

	// Initialize total distance traveled
	distance := 0

	// Loop through each time unit from 0 to t-1
	for i := 0; i < t; i++ {
		// Check if the current velocity can exceed the maximum allowed velocity
		if v-v2 > (t-i-1)*d {
			// Reverse acceleration direction if the velocity exceeds the limit
			a *= -1
			// Adjust current velocity to not exceed the maximum allowed velocity
			v = (t-i-1)*d + v2
		}

		// Add current velocity to total distance
		distance += v

		// Update current velocity based on acceleration direction
		v += a * d
	}

	// Print the total distance traveled after t time units
	fmt.Println(distance)
}

// <END-OF-CODE>
