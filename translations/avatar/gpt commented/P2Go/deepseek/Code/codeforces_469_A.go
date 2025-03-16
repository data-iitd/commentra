package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	// Read the maximum level from user input
	maxLevelStr, _ := reader.ReadString('\n')
	maxLevel, _ := strconv.Atoi(strings.TrimSpace(maxLevelStr))

	// Read the levels completed by player X and convert them to a list of integers
	xStr, _ := reader.ReadString('\n')
	xParts := strings.Split(strings.TrimSpace(xStr), " ")
	x := make([]int, len(xParts))
	for i, v := range xParts {
		x[i], _ = strconv.Atoi(v)
	}
	x = x[1:] // Remove the first element, which represents the count of levels

	// Read the levels completed by player Y and convert them to a list of integers
	yStr, _ := reader.ReadString('\n')
	yParts := strings.Split(strings.TrimSpace(yStr), " ")
	y := make([]int, len(yParts))
	for i, v := range yParts {
		y[i], _ = strconv.Atoi(v)
	}
	y = y[1:] // Remove the first element, which represents the count of levels

	// Convert the lists of levels into sets to eliminate duplicates
	xSet := make(map[int]bool)
	for _, v := range x {
		xSet[v] = true
	}
	ySet := make(map[int]bool)
	for _, v := range y {
		ySet[v] = true
	}

	// Check if player X has completed level 0, if so, remove it from the set
	if _, exists := xSet[0]; exists {
		delete(xSet, 0)
	} else if _, exists := ySet[0]; exists { // If player X has not completed level 0, check if player Y has, and remove it if present
		delete(ySet, 0)
	}

	// Create a union of both sets to combine all unique levels completed by both players
	z := make(map[int]bool)
	for k := range xSet {
		z[k] = true
	}
	for k := range ySet {
		z[k] = true
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
