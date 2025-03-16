package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	// User inputs the maximum level of the set
	var maxLevel int
	fmt.Scan(&maxLevel)

	// User inputs two lists, x and y, separated by a newline
	var xInput, yInput string
	fmt.Scanln(&xInput)
	fmt.Scanln(&yInput)

	// Convert input strings to slices of integers
	xStr := strings.Split(xInput, " ")
	yStr := strings.Split(yInput, " ")

	// Remove the first element from both slices, as they are not part of the sets
	xStr = xStr[1:]
	yStr = yStr[1:]

	// Create maps to represent sets for faster set operations
	x := make(map[int]struct{})
	y := make(map[int]struct{})

	// Fill the first set
	for _, val := range xStr {
		num, _ := strconv.Atoi(val)
		x[num] = struct{}{}
	}

	// Fill the second set
	for _, val := range yStr {
		num, _ := strconv.Atoi(val)
		y[num] = struct{}{}
	}

	// Check if zero is present in the first set
	if _, exists := x[0]; exists {
		// If it is, remove it
		delete(x, 0)
	} else {
		// Else, check if zero is present in the second set
		if _, exists := y[0]; exists {
			// If it is, remove it
			delete(y, 0)
		}
	}

	// Combine both sets into a new set z
	z := make(map[int]struct{})
	for k := range x {
		z[k] = struct{}{}
	}
	for k := range y {
		z[k] = struct{}{}
	}

	// Check if the size of the combined set is equal to the maximum level
	if len(z) != maxLevel {
		// If not, print an error message
		fmt.Println("Oh, my keyboard!")
	} else {
		// Else, print a success message
		fmt.Println("I become the guy.")
	}
}

// <END-OF-CODE>
