
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Read initial velocities v1 and v2 from user input
	reader := bufio.NewReader(os.Stdin)
	v1Str, _ := reader.ReadString('\n')
	v2Str, _ := reader.ReadString('\n')

	// Read time t and distance increment d from user input
	tStr, _ := reader.ReadString('\n')
	dStr, _ := reader.ReadString('\n')

	// Convert input values from strings to integers
	v1, _ := strconv.Atoi(v1Str)
	v2, _ := strconv.Atoi(v2Str)
	t, _ := strconv.Atoi(tStr)
	d, _ := strconv.Atoi(dStr)

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

