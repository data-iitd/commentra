package main

import (
	"fmt"
)

func main() {
	var n, levels int
	fmt.Scan(&n)      // Read the total number of levels
	fmt.Scan(&levels) // Read the number of levels the user has completed

	arr := make([]int, levels) // Initialize slice to store completed levels

	// Read the levels completed by the user
	for i := 0; i < levels; i++ {
		fmt.Scan(&arr[i])
	}

	var level2 int
	fmt.Scan(&level2) // Read the number of levels the second user has completed
	level3 := levels + level2 // Calculate the total number of levels
	arr2 := make([]int, level3) // Initialize slice to store all levels

	// Copy levels from arr to arr2
	for i := 0; i < len(arr); i++ {
		arr2[i] = arr[i]
	}

	// Read additional levels for arr2
	for i := len(arr); i < level3; i++ {
		fmt.Scan(&arr2[i])
	}

	arr3 := make([]int, n) // Generate a sequence of numbers from 1 to n
	for i := 0; i < n; i++ {
		arr3[i] = i + 1
	}

	count := 0 // Initialize count to track the number of levels completed
	// Check if all numbers from 1 to n are present in arr2
	for i := 0; i < n; i++ {
		for x := 0; x < len(arr2); x++ {
			if arr3[i] == arr2[x] {
				count++
				break
			}
		}
	}

	// Print the result based on whether all levels were completed
	if count == n {
		fmt.Println("I become the guy.")
	} else {
		fmt.Println("Oh, my keyboard!")
	}
}

// <END-OF-CODE>
