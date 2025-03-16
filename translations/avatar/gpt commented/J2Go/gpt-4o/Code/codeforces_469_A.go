package main

import (
	"fmt"
)

func main() {
	// Read the number of players (n) and the number of levels (levels)
	var n, levels int
	fmt.Scan(&n, &levels)

	// Create a slice to store the levels completed by the first player
	arr := make([]int, levels)

	// Read the levels completed by the first player
	for i := 0; i < levels; i++ {
		fmt.Scan(&arr[i])
	}

	// Read the number of additional levels completed by the second player
	var level2 int
	fmt.Scan(&level2)

	// Calculate the total number of levels completed by both players
	level3 := levels + level2

	// Create a new slice to store levels completed by both players
	arr2 := make([]int, level3)

	// Copy levels from the first player's slice to the new slice
	copy(arr2, arr)

	// Read the levels completed by the second player and add them to the new slice
	for i := levels; i < level3; i++ {
		fmt.Scan(&arr2[i])
	}

	// Create a slice to represent all levels (1 to n)
	arr3 := make([]int, n)
	for i := 0; i < n; i++ {
		arr3[i] = i + 1
	}

	// Check how many levels from arr3 are completed by either player
	count := 0
	for i := 0; i < n; i++ {
		for x := 0; x < len(arr2); x++ {
			// If a level is found in arr2, increment the count and break
			if arr3[i] == arr2[x] {
				count++
				break
			}
		}
	}

	// Determine if all levels have been completed by at least one player
	if count == n {
		fmt.Println("I become the guy.")
	} else {
		fmt.Println("Oh, my keyboard!")
	}
}

// <END-OF-CODE>
