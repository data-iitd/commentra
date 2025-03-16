package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var maxLevel int
	fmt.Scan(&maxLevel)

	var x, y []int
	var input string

	// Read the first list
	fmt.Scan(&input)
	x = convertToIntSlice(input)

	// Read the second list
	fmt.Scan(&input)
	y = convertToIntSlice(input)

	// Remove the first element from each list
	x = x[1:]
	y = y[1:]

	// Convert slices to maps to mimic set behavior
	xSet := make(map[int]struct{})
	ySet := make(map[int]struct{})

	for _, val := range x {
		if val != 0 {
			xSet[val] = struct{}{}
		}
	}

	for _, val := range y {
		if val != 0 {
			ySet[val] = struct{}{}
		}
	}

	// Find the union of the two sets
	unionSet := make(map[int]struct{})
	for key := range xSet {
		unionSet[key] = struct{}{}
	}
	for key := range ySet {
		unionSet[key] = struct{}{}
	}

	// Check if the length of the union set is equal to the maximum level
	if len(unionSet) != maxLevel {
		fmt.Println("Oh, my keyboard!")
	} else {
		fmt.Println("I become the guy.")
	}
}

// Helper function to convert a space-separated string of integers to a slice of integers
func convertToIntSlice(input string) []int {
	strs := strings.Fields(input)
	ints := make([]int, len(strs))
	for i, s := range strs {
		val, _ := strconv.Atoi(s)
		ints[i] = val
	}
	return ints
}
