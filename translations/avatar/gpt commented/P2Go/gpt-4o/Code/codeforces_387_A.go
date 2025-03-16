package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var time1, time2 string

	// Read the first time input in 'hh:mm' format
	fmt.Scanln(&time1)
	h1m1 := strings.Split(time1, ":")
	h1, _ := strconv.Atoi(h1m1[0])
	m1, _ := strconv.Atoi(h1m1[1])

	// Convert the first time into total minutes
	m1 += h1 * 60

	// Read the second time input in 'hh:mm' format
	fmt.Scanln(&time2)
	h2m2 := strings.Split(time2, ":")
	h2, _ := strconv.Atoi(h2m2[0])
	m2, _ := strconv.Atoi(h2m2[1])

	// Convert the second time into total minutes
	m2 += h2 * 60

	// Calculate the difference in minutes between the first and second time
	m2 = m1 - m2

	// Ensure the result is within a 24-hour format by taking modulo 1440 (total minutes in a day)
	m2 = (m2 + 1440) % 1440 // Adding 1440 to handle negative values

	// Print the result in 'hh:mm' format, ensuring two digits for both hours and minutes
	fmt.Printf("%02d:%02d\n", m2/60, m2%60)
}

// <END-OF-CODE>
