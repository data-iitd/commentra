package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	// Read a line of input from the console
	var line string
	fmt.Scanln(&line)

	// Split the input line into an array of strings
	list := strings.Split(line, " ")

	// Parse the first three elements of the input into integers
	x, _ := strconv.Atoi(list[0])
	a, _ := strconv.Atoi(list[1])
	y, _ := strconv.Atoi(list[2])

	// Initialize a variable to hold the result, defaulting to "NO"
	h := "NO"

	// Check if any of the numbers x, a, or y are either 5 or 7
	if x == 5 || x == 7 || a == 5 || a == 7 || y == 5 || y == 7 {
		// If the sum of x, a, and y equals 17, set the result to "YES"
		if x+y+a == 17 {
			h = "YES"
		}
	}

	// Output the result
	fmt.Println(h)
}

// <END-OF-CODE>
