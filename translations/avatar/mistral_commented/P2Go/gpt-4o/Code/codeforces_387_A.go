package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var input string

	// Define the first hour and minute variables from user input
	fmt.Scanln(&input)
	parts := strings.Split(input, ":")
	h1, _ := strconv.Atoi(parts[0])
	m1, _ := strconv.Atoi(parts[1])

	// Add the hour to the minute value
	m1 += h1 * 60

	// Define the second hour and minute variables from user input
	fmt.Scanln(&input)
	parts = strings.Split(input, ":")
	h2, _ := strconv.Atoi(parts[0])
	m2, _ := strconv.Atoi(parts[1])

	// Add the hour to the minute value for the second set of variables
	m2 += h2 * 60

	// Calculate the difference between the total minutes of the first and second sets of variables
	m2 = m1 - m2

	// Calculate the remainder of the difference when divided by 1440 (24 hours * 60 minutes)
	m2 = (m2 + 1440) % 1440 // Ensure m2 is non-negative

	// Print the result in the format of hours and minutes
	fmt.Printf("%02d:%02d\n", m2/60, m2%60)
}

// <END-OF-CODE>
