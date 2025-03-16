package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var h1, m1, h2, m2 int

	// Read first time input
	fmt.Scanln(&h1, &m1)
	m1 += h1 * 60

	// Read second time input
	fmt.Scanln(&h2, &m2)
	m2 += h2 * 60

	// Calculate the difference in minutes
	m2 = m1 - m2
	m2 %= 1440

	// Print the result in HH:MM format
	fmt.Printf("%02d:%02d\n", m2/60, m2%60)
}

// <END-OF-CODE>
