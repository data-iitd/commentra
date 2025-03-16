package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	// Get the initial values of v1, v2, t, and d from user input
	var input string
	fmt.Scanln(&input)
	values := strings.Split(input, " ")
	v1, _ := strconv.Atoi(values[0])
	v2, _ := strconv.Atoi(values[1])

	fmt.Scanln(&input)
	values = strings.Split(input, " ")
	t, _ := strconv.Atoi(values[0])
	d, _ := strconv.Atoi(values[1])

	// Initialize variables
	a := 1
	v := v1
	distance := 0

	// For loop to calculate the total distance
	for i := 0; i < t; i++ {
		// Check if v is ahead of v2 by more than the difference * (time - i)
		if v-v2 > (t-i)*d {
			// If so, change the direction of acceleration
			a *= -1
			// Update the position of v
			v = (t-i)*d + v2
		}

		// Add the current position of v to the total distance
		distance += v

		// Update the position of v based on the acceleration
		v += a * d
	}

	// Print the total distance
	fmt.Println(distance)
}

// <END-OF-CODE>
