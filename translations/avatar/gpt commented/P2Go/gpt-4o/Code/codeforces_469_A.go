package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	// Read the maximum level from user input
	var maxLevel int
	fmt.Scan(&maxLevel)

	// Read the levels completed by player X
	var xInput string
	fmt.Scan(&xInput)
	xLevels := strings.Split(xInput, " ")
	x := make(map[int]struct{})

	// Convert levels to a set of integers
	for i := 1; i < len(xLevels); i++ { // Start from 1 to skip the count
		level, _ := strconv.Atoi(xLevels[i])
		x[level] = struct{}{}
	}

	// Read the levels completed by player Y
	var yInput string
	fmt.Scan(&yInput)
	yLevels := strings.Split(yInput, " ")
	y := make(map[int]struct{})

	// Convert levels to a set of integers
	for i := 1; i < len(yLevels); i++ { // Start from 1 to skip the count
		level, _ := strconv.Atoi(yLevels[i])
		y[level] = struct{}{}
	}

	// Check if player X has completed level 0, if so, remove it from the set
	if _, exists := x[0]; exists {
		delete(x, 0)
	} else if _, exists := y[0]; exists {
		delete(y, 0)
	}

	// Create a union of both sets to combine all unique levels completed by both players
	z := make(map[int]struct{})
	for level := range x {
		z[level] = struct{}{}
	}
	for level := range y {
		z[level] = struct{}{}
	}

	// Check if the number of unique levels completed matches the maximum level
	if len(z) != maxLevel {
		// If not, print a message indicating that not all levels were completed
		fmt.Println("Oh, my keyboard!")
	} else {
		// If all levels were completed, print a success message
		fmt.Println("I become the guy.")
	}
}

// <END-OF-CODE>
